/* 
02/07/2022
Juan Pablo Gomez
C file for function definitions for correlation coefficient in part1 of lab1
*/

#include "gomezj_corr.hpp"
#include "gomezj_stats.hpp"

mySpace::corr::corr(int){

    this->corr_coefficient;

}

void mySpace::corr::set_corr_coefficient(std::vector<float> * data1, std::vector<float> * data2){

    int x, y;
    float correlation;
    float num;
    float den1;
    float den2;
    float den;

    mySpace::stats somevariablename(12, 14);

    //find mean of both datasets and calculate toal num of data points
    somevariablename.set_mean(data1);
    float mean1 = somevariablename.get_mean();
    somevariablename.set_mean(data2);
    float mean2 = somevariablename.get_mean();
    float total_size = data1->size() + data2->size();

    float corr_value;
    num = 0.0;
    for (int x: *data1){
        for (int y : *data2){
            num = num + (x*y);
        }
    }

    // Numerator of equation  sum(x*y)-N(meanx*meany)
    num = num - (total_size * mean1 * mean2); 

    //Find denominator
    den1 = 0.0;
    den2 = 0.0;

    for (int x : *data1) {
        den1 = den1 + pow(x, 2);
    } 
    // sum x^2- N*meanx^2
    den1 = (den1) - (total_size * (pow(mean1, 2)));

    for (int y : *data2) {
        den2 = den2 + pow(y, 2);  // summation of y^2
    } 
    // sum y^2- N*meany^2
    den2 = (den2) - (total_size * (pow(mean2, 2)));

    // calculate denominator
    den = pow(den1*den2, 0.5);

    corr_value = num/den;
    printf("%f\n", corr_value);
    this->corr_coefficient = corr_value;

}

float mySpace::corr::get_corr_coefficient() {
    return corr_coefficient;
}