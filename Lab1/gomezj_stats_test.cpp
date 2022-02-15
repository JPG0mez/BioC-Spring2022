#include "gomezj_stats.hpp"
#include "gomezj_corr.hpp"

int main(int argc, char *argv[]) {

    //Initialize input file
    std::ifstream file;
    std::vector<float> data;
    float element;
    file.open(argv[1]); 
    //Leave if doesnt exists
    if(file.fail()){
        printf ("File does not exist\n");
        exit (EXIT_FAILURE);
    }
    while (file >> element)
    {
        data.push_back(element);
        //printf("%f\n",element);
    }
    file.close();
    
    // std::vector<float> data{ 10, 20, 30};
    mySpace::stats somevariablename(12, 14);
    int size = data.size();
    printf("Number of Data Points Analyzed: %i\n", size);
    //Calculate Max
    somevariablename.set_max(&data);
    float max_value = somevariablename.get_max();
    printf("The maximum value is: %f\n", max_value);
    //Calculate Min
    somevariablename.set_min(&data);
    float min_value = somevariablename.get_min();
    printf("The mininum value is: %f\n", min_value);
    //Calculate Mean
    somevariablename.set_mean(&data);
    float mean_value = somevariablename.get_mean();
    printf("The Mean value is: %f\n", mean_value);
    //Calculate Standard Dev
    somevariablename.set_SD(&data);
    float SD_value = somevariablename.get_SD();
    printf("The Standard Deviation value is: %f\n", SD_value);

    //set histogram
    somevariablename.set_hist(&data);
}
