#!/bin/bash
#Author: Juan Pablo Gomez Postigo
#Date: 02/08/2022
#Description: hist thing




echo 'Enter concentration percent to analyze (0 or 5)'

read input


if [ "$input" == "0" ]; then
    echo "0% concentration selected"
elif [ "$input" == "5" ]; then
    echo "5% concentration selected"
else
    echo "no valid concentration levels were selected"
    echo "Please try again"
    exit
fi

cat EEG_DATA/ERP0$input/* > EEG_DATA/catted_input.dat

FILE=EEG_DATA/histogram_$input%_concentration.txt

~/bin/./stats.out EEG_DATA/catted_input.dat > $FILE

if test -f "$FILE"; then
    echo "Histogram data printed to $FILE"
else
    echo "File could not be stored. File already exists. Or something else happened idk man"
fi



