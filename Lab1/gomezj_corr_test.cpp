/* 
02/07/2022
Juan Pablo Gomez
C file for testing fucntions written
*/

#include "gomezj_corr.hpp"
#include "gomezj_stats.hpp"


int main(int argc, char * argv[]) {
    
    //open and see if file 1 exists
    std::ifstream file1;
    std::vector<float> data1;
    float element1;
    file1.open(argv[1]); 
    //Leave if doesnt exists
    if(file1.fail()){
        printf ("File does not exist\n");
        exit (EXIT_FAILURE);
    }
    while (file1 >> element1)
    {
        data1.push_back(element1);
        //printf("%f\n",element1);
    }
    file1.close();
    //open and see if file 2 exists
    std::ifstream file2;
    std::vector<float> data2;
    float element2;
    file2.open(argv[2]); 
    //Leave if doesnt exists
    if(file2.fail()){
        printf ("File does not exist\n");
        exit (EXIT_FAILURE);
    }
    while (file2 >> element2)
    {
        data2.push_back(element2);
        //printf("%f\n",element2);
    }
    file2.close();


    mySpace::corr somevariablenamecorr(12);

    somevariablenamecorr.set_corr_coefficient(&data1, &data2);

}