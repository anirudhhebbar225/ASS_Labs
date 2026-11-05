#!/bin/bash
echo "Enter a string:"
read str
len=`expr length "$str"`
case $len in
  [0-9]) echo "String has less than 10 characters" ;;
  *)     echo "String is OK ($len characters)" ;;
esac
