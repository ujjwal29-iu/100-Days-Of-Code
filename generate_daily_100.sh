#!/usr/bin/env bash
set -euo pipefail

# Generate 100 commits over 100 days (Aug 22 - Nov 29, 2025)
# Each day adds/modifies a day_X.txt file to create ONE commit per day
# Then preserve all original code files

BRANCH="main"
BACKUP="backup-final-100-$(date +%Y%m%d%H%M%S)"

START_DATE="2025-08-22 12:00:00"
SECONDS_PER_DAY=86400

echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

START_EPOCH=$(date -d "$START_DATE" +%s)
echo "Generating 100 daily commits (Aug 22 - Nov 29, 2025)"
echo "Each commit will have its own tracked file"

TMP_BRANCH="gen-daily-100-$(date +%Y%m%d%H%M%S)"
echo "Creating orphan branch $TMP_BRANCH"
git checkout --orphan "$TMP_BRANCH"
git reset --hard

# First, add all original code from the old branch
echo "Adding all original code files..."
git checkout "$BRANCH" -- . 2>/dev/null || true
git add -A 2>/dev/null || true

# Now generate 100 daily commits
for day in $(seq 1 100); do
  echo "=== Day $day/100 ==="
  
  # Calculate date for this day
  epoch=$((START_EPOCH + (day - 1) * SECONDS_PER_DAY))
  new_date=$(date -d "@$epoch" -R)
  commit_date=$(date -d "@$epoch" +"%Y-%m-%d")
  
  # Create/update a day file
  echo "Work done on Day $day ($commit_date)" > "day_$day.txt"
  
  # Stage and commit
  git add "day_$day.txt"
  GIT_AUTHOR_NAME="ujjwal29-iu" GIT_AUTHOR_EMAIL="ujjwaltyagi458@gmail.com" GIT_AUTHOR_DATE="$new_date" \
    GIT_COMMITTER_NAME="ujjwal29-iu" GIT_COMMITTER_EMAIL="ujjwaltyagi458@gmail.com" GIT_COMMITTER_DATE="$new_date" \
    git commit -m "Day $day: $commit_date"
  
  if [ $((day % 10)) -eq 0 ]; then
    echo "Progress: $day/100 commits done"
  fi
done

echo "Replacing $BRANCH with $TMP_BRANCH"
git branch -f "$BRANCH" "$TMP_BRANCH"
git checkout "$BRANCH"

echo "Done! 100 commits generated, each on its assigned date"
echo "All original code + 100 day_X.txt files now in repo"
echo "Verify with: git log --oneline | head -20"
