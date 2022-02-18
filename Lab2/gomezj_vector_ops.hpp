/* Juan Pablo Gomez Postigo
* 2/15/22
*/

#ifndef classheader
#define classheader

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

namespace JpSpace {
    class vectorops {
    public:
        vectorops(int);
        //sum all elements of array
        int Sum(std::vector<float> *data);
        
        //subtracts one array from other array by element
        void Subtract(std::vector<float> *data1, std::vector<float> *data2, std::vector<float> *output);
        //divides array elements by value
        void Division(std::vector<float> *data1, float const_div, std::vector<float> *output);
                
    };
}

#endif