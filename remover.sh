#!/usr/bin/env bash

echo "Removing files from $1 folder"

echo "Enter pattern: "
read pattern
echo "Removing files matching pattern $pattern"
cd $1
for filename in $pattern 
do
    echo "$filename"
done 
