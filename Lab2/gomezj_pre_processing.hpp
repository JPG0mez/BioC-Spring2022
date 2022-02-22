/* 
02/07/2022
Juan Pablo Gomez
Header file for functions used in part1 of lab 1
*/
#ifndef preprocessheader
#define preprocessheader

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>


namespace JpSpaceprocess {
    class preprocess {
    public:
        preprocess(int);
        //sum all elements of array
        
        void openfile(std::string File, std::vector<int> *outputname, int filenum);
        
        void logIR(std::vector<float> *data1, std::vector<float> *data2, std::vector<float> *output);

    };
}




#endif