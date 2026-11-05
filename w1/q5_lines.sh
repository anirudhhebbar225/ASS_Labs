#!/bin/bash
# Usage: ./q5_lines.sh file start end
sed -n "$2,$3p" "$1"
