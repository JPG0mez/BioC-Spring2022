#!/bin/bash
#Author: Juan Pablo Gomez Postigo
#Date: 02/08/2022
#Description: hist thing

echo 'Enter concentration percent to analyze (00 or 05)'

read input


if [ "$input" == "00" ]; then
    echo "00% concentration selected"
elif [ "$input" == "05" ]; then
    echo "05% concentration selected"
else

































    echo "no valid concentration levels were selected"
    exit
fi


# first_loop=0
# Change for loop to itterate through incrementing numbers to run command in order from 0 to 1
# that way things are commanded together in a order
j=0
for (( i=1; i<60; i++ ))
do 
    j=$((i+1))
    if [ "$input" == "05" ]; then
    file1="EEG_DATA/ERP$input/ERP$input.$i.txt"
    file2="EEG_DATA/ERP$input/ERP$input.$j.txt"
    echo "Running correlation on ERP$input.$i.txt and ERP$input.$j.txt"
    ~/bin/corr.out $file1 $file2 >> test.txt
    else 
    file1="EEG_DATA/ERP$input/ERP$input$i.txt"
    file2="EEG_DATA/ERP$input/ERP$input$j.txt"
    echo "Running correlation on ERP$input$i.txt and ERP$input$j.txt"
    ~/bin/corr.out $file1 $file2 >> test.txt
    
    fi
    
done
sed '$!s/$/,/' test.txt > EEG_DATA/conc_corr_$input%.csv
# for FILE in EEG_DATA/ERP$input/*; 
# do 
# if [ "$first_loop" == 0 ]; then
#     first_loop=1
#     previous_file=$FILE
#     echo "this is the first loop"
# else
#     echo "previous file is $previous_file"
#     echo "current file is $FILE" 
#     previous_file=$FILE
# fi
# done
