#!/bin/bash
echo "Date and time: $(date)"
echo "Users logged in: $(who | wc -l)"
