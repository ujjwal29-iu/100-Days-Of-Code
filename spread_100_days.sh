#!/usr/bin/env bash
set -euo pipefail

# This script spreads your EXISTING commits across 100 days (Aug 22 - Nov 29, 2025)
# WITHOUT adding or removing any files

BRANCH="main"
BACKUP="backup-redate-proper-$(date +%Y%m%d%H%M%S)"

START_DATE="2025-08-22 12:00:00"
SECONDS_PER_DAY=86400
TOTAL_DAYS=100

echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

START_EPOCH=$(date -d "$START_DATE" +%s)
echo "Spreading existing commits across 100 days (Aug 22 - Nov 29, 2025)"

# Collect all commits in chronological order
mapfile -t commits < <(git rev-list --reverse --topo-order "$BRANCH")
count=${#commits[@]}
echo "Found $count existing commits"
echo "Will assign each to a day spread across the 100-day range"

TMP_BRANCH="spread-100-days-$(date +%Y%m%d%H%M%S)"
echo "Creating orphan branch $TMP_BRANCH"
git checkout --orphan "$TMP_BRANCH"
git reset --hard

idx=0
for sha in "${commits[@]}"; do
  # Spread commits evenly across 100 days
  if [ "$count" -gt 100 ]; then
    # More than 100 commits: distribute them evenly
    day_offset=$((idx * 100 / count))
  else
    # 100 or fewer commits: one per day (or multiple per day if needed)
    day_offset=$idx
  fi

  # Cap at 99 to stay within 100 days
  if [ $day_offset -ge 100 ]; then
    day_offset=99
  fi

  echo "Processing commit $((idx+1))/$count → day $((day_offset+1))/100"

  # Checkout the exact tree of this commit (preserves all files)
  git checkout "$sha" -- .

  # Read author info and commit message from original
  an=$(git show -s --format=%an "$sha")
  ae=$(git show -s --format=%ae "$sha")
  msg=$(git show -s --format=%B "$sha")

  # Calculate new date for this day
  epoch=$((START_EPOCH + day_offset * SECONDS_PER_DAY))
  new_date=$(date -d "@$epoch" -R)

  # Stage all files and commit with new date
  git add -A
  GIT_AUTHOR_NAME="$an" GIT_AUTHOR_EMAIL="$ae" GIT_AUTHOR_DATE="$new_date" \
    GIT_COMMITTER_NAME="$an" GIT_COMMITTER_EMAIL="$ae" GIT_COMMITTER_DATE="$new_date" \
    git commit -m "$msg" || true

  idx=$((idx + 1))
done

echo "Replacing $BRANCH with $TMP_BRANCH"
git branch -f "$BRANCH" "$TMP_BRANCH"
git checkout "$BRANCH"

echo "Done! All commits preserved, dates reassigned to Aug 22 - Nov 29, 2025"
echo "Verify with: git log --pretty=format:\"%h %ai %s\" | head -10"
