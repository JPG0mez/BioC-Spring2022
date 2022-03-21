#!/bin/bash
#automatically generate a makefile for an arbitrary code project.  
# The script will take in exactly one argument: a path to a directory with code files (cpp/hpp) inside. 
# path is /lab/bien4290/midterm2022
if [ $# -eq 0 ]
  then
    echo "No arguments supplied, you fool"
    exit
fi
if [ $# -gt 1 ]
  then
    echo "Too Many arguments supplied. Slow down, you just need one buddy"
    exit
fi
DIR_PATH=$1
FILE="Makefile"
makefile="$DIR_PATH/$FILE"
#If Makefile already exists don't make another one
if [ ! -f "$makefile" ]; then
    touch $makefile
fi

# Add compiler to Makefile
echo "CC = g++" > $makefile

for d in midterm2022/*/ ; do
    #echo "$d" x#a/
    folder_name="${d#$DIR_PATH}"
    folder_name="${folder_name::-1}"
    # Print newlines
    printf "\n" >> $makefile
    printf "\n" >> $makefile
    # Ouput the .o to the file
    echo -n "$folder_name.o:" >> $makefile
    # Do smae thing but now with .cpp and .h files
    num_of_mains=0
    # echo $folder_name
    for p in $d* ; do
        # Strip beggining directory from filename
        file_name="${p#$DIR_PATH}"
        echo -n " $file_name" >> $makefile
        # Finds Main
        if grep -q "main" $p; then
            if cat $p | sed -n '/\/\*/, /\*\//p' | grep -q "main"; then
                # echo "False positive: ${file_name}"
                ignore_array+=("${main_file}")
            else
                num_of_mains=$((num_of_mains+1))
                # echo $num_of_mains
                if [ $num_of_mains -lt 2 ]
                then
                    # echo "Found main here: ${file_name}"
                    main_file="${p##*/}"
                    main_file="${file_name::-4}"
                    main_array+=("${main_file}")
                else    
                    ignore_main+=("${file_name}")
                    # echo "${file_name}"
                fi 
            fi
        fi
    done
    # Do it again but nor for executable
    printf "\n\t" >> $makefile
    echo "\$(CC) -c $^" >> $makefile
    printf "\n" >> $makefile
    echo -n "${folder_name}_exec:" >> $makefile
    # Create array of all executables
    exec_array+=("${folder_name}_exec")
    for p in $d* ; do
        # Strip beggining directory from filename
        file_name="${p#$DIR_PATH}"
        # echo $file_name
        # Check if file is a .c
        if [[ $file_name == *.cpp ]]; then
            # echo $file_name
            if [[ ! " ${ignore_main[*]} " =~ " $file_name " ]]; then
               file_name="${file_name::-4}"
                file_name="${file_name}.o"
                # echo $file_name
                echo -n " $file_name" >> $makefile 
            fi
        fi
        
        # file_name="${file_name::-4}"
        # file_name="${file_name}.o"
        # echo $file_name
        # echo -n " $file_name" >> $makefile
    done
    printf "\n\t" >> $makefile
    echo "\$(CC) -o \$@ \$^" >> $makefile
done

# Make all
printf "\n" >> $makefile
echo -n "all:" >> $makefile
for value in "${exec_array[@]}"
do
     echo -n " $value" >> $makefile
done
# Make the clean part of make file
printf "\n" >> $makefile
echo "
clean:" >> $makefile
for d in midterm2022/*/ ; do
    #echo "$d" x#a/
    folder_name="${d#$DIR_PATH}"
    folder_name="${folder_name::-1}"
    printf "\t" >> $makefile
    echo "rm -f $folder_name/*.o" >> $makefile
    printf "\t" >> $makefile
    echo "rm -f $folder_name/*.gch" >> $makefile
    printf "\t" >> $makefile
    echo "rm -f ${folder_name}_exec" >> $makefile
done

cd ${DIR_PATH}
make all

for value in "${exec_array[@]}"
do
     ./$value
done
# rm -f Straightforward_exec

# Straightforward_exec: Straightforward/dandelion.o Straightforward/toss_a_coin.o Straightforward/wolf.o Straightforward/valley_of_plenty.o
# 	$(CC) -o $@ $^