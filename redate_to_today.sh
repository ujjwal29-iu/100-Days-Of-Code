#!/usr/bin/env bash
set -euo pipefail

# Redate all commits to TODAY (Dec 3, 2025)
# Each commit gets a slightly different time on the same day so they have different timestamps

BRANCH="main"
BACKUP="backup-before-today-redate-$(date +%Y%m%d%H%M%S)"

TODAY="2025-12-03"
SECONDS_PER_COMMIT=60  # 1 minute apart

echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

# Calculate epoch for start of today
START_EPOCH=$(date -d "$TODAY 00:00:00" +%s)
echo "Rewriting all commits to TODAY: $TODAY"

# Collect commits in chronological order
mapfile -t commits < <(git rev-list --reverse --topo-order "$BRANCH")
count=${#commits[@]}
echo "Found $count commits to redate to today"

TMP_BRANCH="today-redate-$(date +%Y%m%d%H%M%S)"
echo "Creating orphan branch $TMP_BRANCH"
git checkout --orphan "$TMP_BRANCH"
git reset --hard

idx=0
for sha in "${commits[@]}"; do
  echo "Processing commit $((idx+1))/$count"

  # Checkout the tree of this commit
  git rm -rf --quiet . || true
  git checkout "$sha" -- .

  # Read author info and message
  an=$(git show -s --format=%an "$sha")
  ae=$(git show -s --format=%ae "$sha")
  msg=$(git show -s --format=%B "$sha")

  # Calculate new date for today (1 minute apart)
  epoch=$((START_EPOCH + idx * SECONDS_PER_COMMIT))
  new_date=$(date -d "@$epoch" -R)

  # Stage and commit
  git add -A
  GIT_AUTHOR_NAME="$an" GIT_AUTHOR_EMAIL="$ae" GIT_AUTHOR_DATE="$new_date" \
    GIT_COMMITTER_NAME="$an" GIT_COMMITTER_EMAIL="$ae" GIT_COMMITTER_DATE="$new_date" \
    git commit -m "$msg" || true

  idx=$((idx + 1))
done

echo "Replacing $BRANCH with $TMP_BRANCH"
git branch -f "$BRANCH" "$TMP_BRANCH"
git checkout "$BRANCH"

echo "Done! All $count commits redated to today (Dec 3, 2025)"
echo "Verify with: git log --pretty=format:\"%h %ai %s\" | head -10"
