#include "gomezj_stats.hpp"
#include "gomezj_corr.hpp"
mySpace::stats::stats(int, int){

    this->min;

}
//    for(float x = data->begin(); x != data->end(); ++x){

void mySpace::stats::set_max(std::vector<float> *data){

    float max_value = data->at(0);
    for(float x: *data){
        
        if (x > max_value){
            max_value = x;
        }
    }
    this->max = max_value;
}

void mySpace::stats::set_min(std::vector<float>  *data){

    float min_value = data->at(0);
    for(float x: *data){
        
        if (x < min_value){
            min_value = x;
        }
    }
    this->min = min_value;
}

void mySpace::stats::set_mean(std::vector<float>  *data){

    float mean_value = 0;
    for(float x: *data){
        
        mean_value = mean_value + x;
    }
    mean_value = mean_value/ data->size();
    this->mean = mean_value;
}

void mySpace::stats::set_SD(std::vector<float>  *data){
    float std_dev_value = 0;
    this->set_mean(data);
    float SD_mean = this->get_mean();

    for(float x : *data){
        std_dev_value = std_dev_value + pow((x-SD_mean), 2);
    }
    std_dev_value = sqrt(std_dev_value/data->size());
    this->SD_dev = std_dev_value;
}

void mySpace::stats::set_hist(std::vector<float> *data){
    //Initializing vector for upper and lower limits of bins
    std::vector<float> bins;
    std::vector<int> bins_values;
    // set and get Standard deviation using functions defined earlier in this code
    this->set_SD(data);
    float std_dev_value = this->get_SD();

    //set values for bin width, min, and max
    float minimum_value = -3.0 * std_dev_value;
    float maximum_value = 3.0 * std_dev_value;
    float bin_width = 0.4 * std_dev_value;

    float edge = minimum_value;

    
    while(edge < maximum_value){
        bins.push_back(edge);
        bins_values.push_back(0);
        edge = edge + bin_width;
    }

    // Value at the end of the vector contains maximum value of histogram
    bins.push_back(maximum_value);
    
    for(int x = 0; x < data->size(); x++){
        for(int y = 0; y < bins_values.size(); y++){
            if(data->at(x) >= bins.at(y) && data->at(x) < bins.at(y+1)){
                bins_values.at(y) = bins_values.at(y) + 1;
            }
        }
    }
    
    //Display histogram to terminal
    printf("\t\t This is my histogram. I want to cry\t\n");
    std::cout << R"(
 /$$   /$$ /$$             /$$                                                         
| $$  | $$|__/            | $$                                                         
| $$  | $$ /$$  /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  /$$$$$$/$$$$ 
| $$$$$$$$| $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$ /$$__  $$|____  $$| $$_  $$_  $$
| $$__  $$| $$|  $$$$$$   | $$    | $$  \ $$| $$  \ $$| $$  \__/ /$$$$$$$| $$ \ $$ \ $$
| $$  | $$| $$ \____  $$  | $$ /$$| $$  | $$| $$  | $$| $$      /$$__  $$| $$ | $$ | $$
| $$  | $$| $$ /$$$$$$$/  |  $$$$/|  $$$$$$/|  $$$$$$$| $$     |  $$$$$$$| $$ | $$ | $$
|__/  |__/|__/|_______/    \___/   \______/  \____  $$|__/      \_______/|__/ |__/ |__/
                                             /$$  \ $$                                 
                                            |  $$$$$$/                                 
                                             \______/                                 )" << '\n';
    for (int i = 0; i < 90; i++) {
        printf("-");
    }
    for (int i = 0; i < bins_values.size(); i++) {
        // prints value for each bin
        printf("\n%f: ", bins.at(i));    
        for (int k = 0; k < bins_values.at(i); k+=10) {
            //prints = for bins frequency
            printf("=");   
        }
    }
    printf("\n");
    for (int i = 0; i < 90; i++) {
        printf("-");
    }
    printf("\t'=' is equivilant to 1 val in the bin\n");
    printf("\nThat's all I hope you enjoyed it\n");
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