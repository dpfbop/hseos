#!/usr/bin/env bash

echo "Removing files from $1 folder"
cd $1

echo "Enter pattern: "
while read pattern
do
echo "Removing files matching pattern $pattern"
for filename in $pattern 
do
    echo "Removing $filename"
    rm "$filename"
done
echo "Enter pattern: "
done 
echo "Exiting!"
