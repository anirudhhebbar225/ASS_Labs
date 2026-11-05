#!/bin/bash
# Usage: ./q3_upper.sh file1 file2 ...
for f in "$@"
do
  if [ -e "$f" ]
  then
    up=`echo "$f" | tr 'a-z' 'A-Z'`
    if [ -e "$up" ]
    then echo "$up already exists"
    else mv "$f" "$up"; echo "$f -> $up"
    fi
  else
    echo "$f does not exist"
  fi
done
