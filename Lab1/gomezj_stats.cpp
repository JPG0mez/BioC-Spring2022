#include "gomezj_stats.hpp"

mySpace::stats::stats(int, int){

    this->min;

}
//    for(float x = data->begin(); x != data->end(); ++x){

void mySpace::stats::set_max(std::vector<float> *data){

    float max_value = data->at(0);
    for(int x: *data){
        
        if (x > max_value){
            max_value = x;
        }
    }
    this->max = max_value;
}

void mySpace::stats::set_min(std::vector<float>  *data){

    float min_value = data->at(0);
    for(int x: *data){
        
        if (x < min_value){
            min_value = x;
        }
    }
    this->min = min_value;
}

void mySpace::stats::set_mean(std::vector<float>  *data){

    float mean_value = 0;
    for(int x: *data){
        
        mean_value = mean_value + x;
    }
    mean_value = mean_value/ data->size();
    this->mean = mean_value;
}

void mySpace::stats::set_SD(std::vector<float>  *data){
    float std_dev_value = 0;
    this->set_mean(data);
    float SD_mean = this->get_mean();

    for(int x : *data){
        std_dev_value = std_dev_value + pow((x-SD_mean), 2);
    }
    std_dev_value = sqrt(std_dev_value/data->size());
    this->SD_dev = std_dev_value;
}

float mySpace::stats::get_max() {

    return this->max;
    
}

float mySpace::stats::get_min() {

    return this->min;
    
}

float mySpace::stats::get_mean() {

    return this->mean;
    
}

float mySpace::stats::get_SD() {

    return this->SD_dev;
    
}