/* 
02/07/2022
Juan Pablo Gomez
Header file for functions used in part1 of lab 1
*/
#ifndef  Lab123
#define Lab123
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

namespace mySpace{
    class stats{
        
    public:
        stats(int, int);
        void set_max(std::vector<float> *data);
        void set_min(std::vector<float> *data);
        void set_mean(std::vector<float> *data);
        void set_SD(std::vector<float> *data);
        void set_hist(std::vector<float> *data);
    
        float get_max();
        float get_min();
        float get_mean();
        float get_SD();
        float get_hist();

    
    private:
        float min;
        float max;
        float mean;
        float SD_dev;

    };    
}


#endif
