/* Juan Pablo Gomez Postigo
 * 2/15/22
 */

#include "gomezj_vector_ops.hpp"

JpSpace::vectorops::vectorops(int){

}

int JpSpace::vectorops::Sum(std::vector<float> * data){

    int sum = 0;
    for(int x: *data){
        
        sum = sum + x;
    }
    return sum;
}

void JpSpace::vectorops::Subtract(std::vector<float>* data1, std::vector<float>* data2, std::vector<float>* output) {
    int sub =0;
    
    if (data1->size() != data2->size()) {
        printf("Both files should be the same size\n");
    }
    else {
        for (int i = 0; i < data1->size(); i++) {
            sub = data1->at(i) - data2->at(i);
            output->push_back(sub);
        }
    }
}


void JpSpace::vectorops::Division(std::vector<float> *data1, float const_div, std::vector<float> *output){
    
    float div = 0;
    int size = data1->size();
        for (int i = 0; i < size; i++) {
            div = data1->at(i) / const_div;
            output->push_back(div);
        }

}

int main(int argc, char * argv[]) {

    std::ifstream file1;
    std::vector<float> data1;
    float element1;
    file1.open(argv[1]); 
    //Leave if doesnt exists
    if(file1.fail()){
        printf ("1st file is missing\n");
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
        printf ("2nd file is also missing ya dingus\n");
        exit (EXIT_FAILURE);
    }
    while (file2 >> element2)
    {
        data2.push_back(element2);
        //printf("%f\n",element2);
    }
    file2.close();

    std::vector<float> output;

    JpSpace::vectorops instance(12);

    int sum_value;
    sum_value = instance.Sum(&data1);

    printf("this is the sum of this datafile %i\n", sum_value);

    int sub_value;
    instance.Subtract(&data1, &data2, &output);

    // for (int i: output){    
    //     std::cout << i << '\n';
    // }
    float div_const = 12.0;
    instance.Division(&data1, div_const, &output);
    for (float i: output){    
        std::cout << i << '\n';
    }

}