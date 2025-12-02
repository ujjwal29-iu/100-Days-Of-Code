#!/usr/bin/env bash
set -euo pipefail

# Calculate dates so commits appear spread over last 100 days
# Today is Dec 3, 2025
# Oldest commit should be ~100 days ago (Sept 24, 2025)
# Newest commit should be ~5 days ago (Nov 28, 2025)

BRANCH="main"
BACKUP="backup-before-redate-$(date +%Y%m%d%H%M%S)"

# Use "today minus X days" to ensure relative to actual date
# 100 days ago from Dec 3
START_DATE=$(date -d "100 days ago" +%Y-%m-%d)
START_TIME="12:00:00"

echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

START_EPOCH=$(date -d "$START_DATE $START_TIME" +%s)
echo "Rewriting dates starting from $START_DATE $START_TIME (approximately 100 days ago)"

echo "Recreating branch with rewritten commit dates (orphan workflow)"

# Collect commits in chronological order
mapfile -t commits < <(git rev-list --reverse --topo-order "$BRANCH")
count=${#commits[@]}
echo "Found $count commits to rewrite"
echo "Will spread across 100 days (one commit per day)"
echo "Date range: ~100 days ago through ~5 days ago"

SECONDS_PER_DAY=86400
TMP_BRANCH="redate-temp-$(date +%Y%m%d%H%M%S)"
echo "Creating orphan branch $TMP_BRANCH"
git checkout --orphan "$TMP_BRANCH"
git reset --hard

idx=0
for sha in "${commits[@]}"; do
  # Spread commits across 100 days
  # If we have more than 100 commits, distribute them evenly across 100 days
  # Otherwise, each commit gets one day
  if [ "$count" -gt 100 ]; then
    # More than 100 commits: distribute across days (multiple commits per day allowed)
    day_offset=$((idx * 100 / count))
  else
    # Up to 100 commits: one per day
    day_offset=$idx
  fi

  echo "Processing commit $((idx+1))/$count (day $((day_offset+1))/100) : $sha"

  # Checkout the tree of the commit into the working tree
  git rm -rf --quiet . || true
  git checkout "$sha" -- .

  # Read author name/email and full commit message
  an=$(git show -s --format=%an "$sha")
  ae=$(git show -s --format=%ae "$sha")
  # Use %B to get the full raw commit message (subject+body)
  msg=$(git show -s --format=%B "$sha")

  # Compute new date
  epoch=$((START_EPOCH + day_offset * SECONDS_PER_DAY))
  new_date=$(date -d "@$epoch" -R)

  # Stage and commit with the same author but new dates
  git add -A
  GIT_AUTHOR_NAME="$an" GIT_AUTHOR_EMAIL="$ae" GIT_AUTHOR_DATE="$new_date" \
    GIT_COMMITTER_NAME="$an" GIT_COMMITTER_EMAIL="$ae" GIT_COMMITTER_DATE="$new_date" \
    git commit -m "$msg"

  idx=$((idx + 1))
done

echo "Replacing $BRANCH with $TMP_BRANCH (backup already created)"
git branch -f "$BRANCH" "$TMP_BRANCH"
git checkout "$BRANCH"

echo "Done. New branch $BRANCH has rewritten dates. Verify with: git log --pretty=fuller -n 20"
