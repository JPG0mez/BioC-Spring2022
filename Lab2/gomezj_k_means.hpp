/* 
02/27/2022
Juan Pablo Gomez
Header file for functions used in part2 of lab 1
*/
#ifndef the_artist_formally_known_as_print
#define the_artist_formally_known_as_print

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

namespace JpSpaceCluster {
    class Kcluster {
        public:
            Kcluster();
            void openfile(std::string File, std::vector<float> *outputname);
            float distance(float data);

            void set_obj_name(std::string name);
            void set_obj_mean(float mean);
            
            std::string get_obj_name();
            float get_obj_mean();
            std::vector<float> cluster_set;
        private:
            std::string name;
            float mean;
            

    };
}














#endif

