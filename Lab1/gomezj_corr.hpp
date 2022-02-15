/* 
02/07/2022
Juan Pablo Gomez
Header file for functions used in corr part of lab 1
*/
#ifndef  Lab1234
#define Lab1234
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "gomezj_stats.hpp"
namespace mySpace{
    class corr{
        
    public:
        corr(int);   
        void set_corr_coefficient(std::vector<float> * data1, std::vector<float> * data2);

        float get_corr_coefficient();

    private:
        float corr_coefficient;
    };
}

#endif