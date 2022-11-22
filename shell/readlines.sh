#!/usr/bin/env bash

while read LINE
do
 echo Riadok: "$LINE"
done | sed 's/^Riadok:/LINE:/'

