
#include "gomezj_stats.hpp"

mySpace::stats::stats(){


}
//    for(float x = data->begin(); x != data->end(); ++x){

float mySpace::stats::set_max(std::vector<float> *data){

    float max_value = data->at(0);
    for(int x: *data){
        
        if (data->at(x) > max_value){
            max_value = data->at(x);
        }
    }
    this->max = max_value;
}

float mySpace::stats::set_min(std::vector<float>  *data){

    float min_value = data->at(0);
    for(int x: *data){
        
        if (data->at(x) < min_value){
            min_value = data->at(x);
        }
    }
    this->min = min_value;
}

float mySpace::stats::set_mean(std::vector<float>  *data){

    float mean_value = data->at(0);
    for(int x: *data){
        
        mean_value = mean_value + data->at(x);
    }
    mean_value = mean_value/(data->size);
    this->min = mean_value;
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


// int main(int argc, char *argv[]) {


//     std::ifstream fin("ERP/ERP00/ERP0010.txt");
    
//     std::vector<float> *data;
//     int element;
//     while (fin >> element)
//     {
//         data->push_back(element);
//     }

   
//     mySpace::stats somevariablename;

    
//     somevariablename.set_max(data);

//     somevariablename.get_max();
// }
