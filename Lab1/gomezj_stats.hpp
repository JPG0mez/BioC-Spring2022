/* This code will act as a primer on class design and creation in C++
*/
#ifndef  Lab1
#define Lab1
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>


namespace mySpace{
    class stats{
        
    public:
        stats();
        float set_max(std::vector<float> *data);
        float set_min(std::vector<float> *data);
        float set_mean(std::vector<float> *data);
        float set_SD(std::vector<float> *data);
        float set_hist(std::vector<float> *data);
    
        void get_max();
        void get_min();
        void get_mean();
        void get_SD();
        void get_hist();

    
    private:
        float min;
        float max;
        float mean;
        float SD_dev;

    };    
}


#endif
