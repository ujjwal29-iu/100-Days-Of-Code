#!/usr/bin/env bash
set -euo pipefail

# Generate 100 commits, one per day from Aug 22 to Nov 29, 2025

BRANCH="main"
BACKUP="backup-before-generate-$(date +%Y%m%d%H%M%S)"

START_DATE="2025-08-22 12:00:00"
SECONDS_PER_DAY=86400
TOTAL_DAYS=100

echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

START_EPOCH=$(date -d "$START_DATE" +%s)
echo "Generating 100 commits from Aug 22 - Nov 29, 2025"

TMP_BRANCH="gen-100-$(date +%Y%m%d%H%M%S)"
echo "Creating orphan branch $TMP_BRANCH"
git checkout --orphan "$TMP_BRANCH"
git reset --hard

for day in $(seq 0 99); do
  echo "Generating commit $((day+1))/100 for day $((day+1))"

  # Create a commit file for this day
  echo "Day $((day+1)) commit" > "day_$((day+1)).txt"

  # Compute date for this day
  epoch=$((START_EPOCH + day * SECONDS_PER_DAY))
  new_date=$(date -d "@$epoch" -R)
  commit_date=$(date -d "@$epoch" +"%Y-%m-%d")

  # Stage and commit
  git add "day_$((day+1)).txt"
  GIT_AUTHOR_NAME="ujjwal29-iu" GIT_AUTHOR_EMAIL="ujjwaltyagi458@gmail.com" GIT_AUTHOR_DATE="$new_date" \
    GIT_COMMITTER_NAME="ujjwal29-iu" GIT_COMMITTER_EMAIL="ujjwaltyagi458@gmail.com" GIT_COMMITTER_DATE="$new_date" \
    git commit -m "Day $((day+1)): $commit_date"
done

echo "Replacing $BRANCH with $TMP_BRANCH (backup already created)"
git branch -f "$BRANCH" "$TMP_BRANCH"
git checkout "$BRANCH"

echo "Done. Generated 100 commits from Aug 22 to Nov 29, 2025"
echo "Verify with: git log --pretty=format:\"%h %ai %s\" | head -20"
