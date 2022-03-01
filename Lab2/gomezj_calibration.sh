#!/bin/bash


echo Hello, how many microarray points would like to proccess?
read num_of_points
echo "Reading in $num_of_points points"
rm summary.txt
for (( i=0; i<7; i++ ))
do 
    ./preprocessing_exec microarray/red_$i.dat microarray/red_background_$i.dat microarray/green_$i.dat microarray/green_background_$i.dat log_ratio_$i.dat $num_of_points
    #echo $i
    cat log_ratio_$i.dat > log_ratio_input.dat
    echo "Final Data for Time point $i" >> summary.txt
    echo "Running Clustering on Time point $i"
    ./cluster_exec >> summary.txt
    cp suppressed_genes.txt suppressed_genes_$i.txt
    cp stationary_genes.txt stationary_genes_$i.txt
    cp expressed_genes.txt expressed_genes_$i.txt
done

