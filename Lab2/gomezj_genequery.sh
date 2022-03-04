#!/bin/bash

echo Hello, which gene are you looking for today?
read gene
echo "searching for $gene"


for (( i=0; i<7; i++ ))
do 
    echo "For Time Point $i"
    if grep -q $gene suppressed_genes_$i.txt; then
    echo "suppressed"
    fi
    if grep -q $gene stationary_genes_$i.txt; then
    echo "stationary"
    fi
    if grep -q $gene expressed_genes_$i.txt; then
    echo "expressed"
    fi
   
done