#!/bin/bash
# Usage: ./q4_listing.sh file1 file2 ...
# %A=permissions %s=size %n=name %y=modified %x=accessed
for f in "$@"
do
  stat -c "%A  %s  %n  Modified: %y  Accessed: %x" "$f"
done
