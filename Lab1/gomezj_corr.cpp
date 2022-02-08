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
    printf("data1 average is: %f\n", mean1);
    somevariablename.set_mean(data2);
    float mean2 = somevariablename.get_mean();
    printf("data2 average is: %f\n", mean2);

    //float total_size = data1->size() + data2->size();

    float total_size = data1->size();
    printf("total num of points is: %f\n", total_size);
    float corr_value;
    num = 0.0;

    for (float x = 0; x < data1->size(); x++) {
        num = num + data1->at(x) * data2->at(x);
    }
    printf("Num1 is: %f\n",num);
    // Numerator of equation  sum(x*y)-N(meanx*meany)
    printf("Num2 is: %f\n",total_size * mean1 * mean2);
    num = num - (total_size * mean1 * mean2); 
    printf("Numerator is: %f\n",num);

    //Find denominator
    den1 = 0.0;
    den2 = 0.0;

    for (float x : *data1) {
        den1 = den1 + pow(x, 2);
    } 
    // sum x^2- N*meanx^2
    den1 = (den1) - (total_size * (pow(mean1, 2)));

    for (float y : *data2) {
        den2 = den2 + pow(y, 2);  // summation of y^2
    } 
    // sum y^2- N*meany^2
    den2 = (den2) - (total_size * (pow(mean2, 2)));

    // calculate denominator
    den = pow(den1*den2, 0.5);

    corr_value = num/den;
    printf("\n%f\n", corr_value);
    this->corr_coefficient = corr_value;

}

float mySpace::corr::get_corr_coefficient() {
    return corr_coefficient;
}