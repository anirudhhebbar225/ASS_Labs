#!/bin/bash
# Usage: ./q2_del_identical.sh d1 d2
for f in "$1"/*
do
  name=`basename "$f"`
  if [ -f "$2/$name" ] && cmp -s "$f" "$2/$name"
  then
    rm "$2/$name"
    echo "Deleted $2/$name"
  fi
done
