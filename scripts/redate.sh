#!/usr/bin/env bash
set -euo pipefail

# Configuration
BRANCH="main"
BACKUP="backup-before-redate-$(date +%Y%m%d%H%M%S)"
START_DATE="2025-08-22 12:00:00"  # change year/time here if you want
SECONDS_PER_DAY=86400

echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

START_EPOCH=$(date -d "$START_DATE" +%s)
echo "Rewriting dates starting from $START_DATE (epoch $START_EPOCH)"

echo "Recreating branch with rewritten commit dates (orphan workflow)"

# Collect commits in chronological order
mapfile -t commits < <(git rev-list --reverse --topo-order "$BRANCH")
count=${#commits[@]}
echo "Found $count commits to rewrite"

TMP_BRANCH="redate-temp-$(date +%Y%m%d%H%M%S)"
echo "Creating orphan branch $TMP_BRANCH"
git checkout --orphan "$TMP_BRANCH"
git reset --hard

idx=0
for sha in "${commits[@]}"; do
  echo "Processing commit $((idx+1))/$count : $sha"

  # Checkout the tree of the commit into the working tree
  git rm -rf --quiet . || true
  git checkout "$sha" -- .

  # Read author name/email and full commit message
  an=$(git show -s --format=%an "$sha")
  ae=$(git show -s --format=%ae "$sha")
  # Use %B to get the full raw commit message (subject+body)
  msg=$(git show -s --format=%B "$sha")

  # Compute new date
  epoch=$((START_EPOCH + idx * SECONDS_PER_DAY))
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
echo "Rewriting dates starting from $START_DATE (epoch $START_EPOCH)"
#!/usr/bin/env bash
set -euo pipefail

# Configuration
BRANCH="main"
BACKUP="backup-before-redate-$(date +%Y%m%d%H%M%S)"
START_DATE="2025-08-22 12:00:00"  # change year/time here if you want
SECONDS_PER_DAY=86400
COUNTER_FILE=".git/redate_counter"

# Create backup branch
echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

# Initialize counter
if [ ! -f "$COUNTER_FILE" ]; then
  echo 0 > "$COUNTER_FILE"
fi

START_EPOCH=$(date -d "$START_DATE" +%s)

echo "Rewriting dates starting from $START_DATE (epoch $START_EPOCH)"
START_EPOCH=$(date -d "$START_DATE" +%s)

# Build mapping of commit -> epoch (chronological order)
MAP_FILE=".git/redate_map"
rm -f "$MAP_FILE"
idx=0
while read -r sha; do
  epoch=$((START_EPOCH + idx * SECONDS_PER_DAY))
  echo "$sha $epoch" >> "$MAP_FILE"
  idx=$((idx + 1))
done < <(git rev-list --reverse --topo-order "$BRANCH")

echo "Built map with $idx commits -> $MAP_FILE"

# Run filter-branch using the map: look up $GIT_COMMIT and set dates accordingly
git filter-branch --force --env-filter '
  epoch=$(grep "^$GIT_COMMIT " .git/redate_map | cut -d" " -f2)
  if [ -n "$epoch" ]; then
    new_date=$(date -d "@$epoch" -R)
    export GIT_AUTHOR_DATE="$new_date"
    export GIT_COMMITTER_DATE="$new_date"
  fi
' -- "$BRANCH"

echo "Cleaning up map file"
rm -f .git/redate_map

echo "Done. New branch $BRANCH has rewritten dates. Verify with: git log --pretty=fuller -n 20"

#!/usr/bin/env bash
set -euo pipefail

# Configuration
BRANCH="main"
BACKUP="backup-before-redate-$(date +%Y%m%d%H%M%S)"
START_DATE="2025-08-22 12:00:00"  # change year/time here if you want
SECONDS_PER_DAY=86400
COUNTER_FILE=".git/redate_counter"

# Create backup branch
echo "Creating backup branch $BACKUP from $BRANCH"
git branch "$BACKUP" "$BRANCH"

# Initialize counter
if [ ! -f "$COUNTER_FILE" ]; then
  echo 0 > "$COUNTER_FILE"
fi

START_EPOCH=$(date -d "$START_DATE" +%s)

echo "Rewriting dates starting from $START_DATE (epoch $START_EPOCH)"

# Use git filter-branch to rewrite commits on the target branch only
git filter-branch --force --env-filter '
  cnt=$(cat .git/redate_counter || echo 0)
  start_epoch='