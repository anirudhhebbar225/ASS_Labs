#!/bin/bash
# Usage: ./add1_merge.sh file1 file2   -> result in merged.txt
# -n numeric, -u unique (removes duplicates)
sort -n -u "$1" "$2" > merged.txt
cat merged.txt
