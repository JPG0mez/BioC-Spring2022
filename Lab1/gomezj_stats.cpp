
#include "gomezj_stats.hpp"

mySpace::stats::myClass(){


}

float mySpace::stats::set_max(std::vector<float> *data){

    float max_value = data->at(0);
    for(auto x = data->begin(); x != data->end(); ++x){
        
        if data->at(x) > max_value{
            max_value = data->at(x);
        }
    }
    this->max = max_value;
}

float mySpace::stats::set_min(std::vector<float>  *data){

    float min_value = data->at(0);
    for(auto x = data->begin(); x != data->end(); ++x){
        
        if data->at(x) < min_value{
            min_value = data->at(x);
        }
    }
    this->min = min_value;
}

float mySpace::stats::set_mean(std::vector<float>  *data){

    float mean_value = data->at(0);
    for(auto x = data->begin(); x != data->end(); ++x){
        
        mean_value = mean_value + data->at(x);
    }
    mean_value = mean_value/(data->size);
    this->min = min_value;
}


float mySpace::stats::get_max() {

    return this->max;
    
}
s
float mySpace::stats::get_min() {

    return min;
    
}

float mySpace::stats::get_mean() {

    return mean;
    
}
