/* 
02/21/2022
Juan Pablo Gomez
C file for prpeprocessing
*/
#include "gomezj_pre_processing.hpp"
#include "gomezj_vector_ops.hpp"

JpSpaceprocess::preprocess::preprocess(int){

}

void JpSpaceprocess::preprocess::openfile(std::string filename, std::vector<int> *outputname, int filenum){

    std::ifstream file;
    int element;
    file.open(filename);
    if(file.fail()){
        printf ("File %i is missing\n", filenum);
        exit (EXIT_FAILURE);
    }
    printf("printing input file %i\n", filenum);
    while (file >> element)
    {
        outputname->push_back(element);
        //printf("%i\n", element);
    }
    file.close();
}

void JpSpaceprocess::preprocess::logIR(std::vector<float> *data1, std::vector<float> *data2, std::vector<float> *output){
    float div;
    for (int i = 0; i < data1->size(); i++) {
        div = log10(data1->at(i) / data2->at(i));
        output->push_back(div);
    }
}

int main(int argc, char* argv[]){
    // argc need to be greater than or equal to 7 for the 6 inputs becasue argc include program name as well
    if (argc < 7) {
        printf ("Program needs 4 input files, an output file, and the number of genes to be analyzed\n");
        exit (EXIT_FAILURE);
    }       
    JpSpaceprocess::preprocess instance(1);
    //create data vectors
    std::vector<int> output1;
    std::vector<int> output2;
    std::vector<int> output3;
    std::vector<int> output4;
    std::vector<int> outputfile;

    // Check if files provided exist
    instance.openfile(argv[1], &output1, 1);
    instance.openfile(argv[2], &output2, 2);
    instance.openfile(argv[3], &output3, 3);
    instance.openfile(argv[4], &output4, 4);
  
    // Checks if input files are of equal length
    if ((output1.size() != output2.size()) || (output1.size() != output3.size()) || (output1.size() != output4.size())){
        printf("File inputs are not of equal length\n");
        exit (EXIT_FAILURE);
        // printf("Size 1: %li\n",output1.size());
        // printf("Size 2: %li\n",output2.size());
        // printf("Size 3: %li\n",output3.size());
        // printf("Size 4: %li\n",output4.size());
    }
    // Checks if number of genese analyzed exceeds data input length
        //atoi(argv[6]) > (output1.size() || output2.size() || output3.size() || output4.size()) 
    if (atoi(argv[6]) > output1.size()){
        printf("Number of genes requested exceeds number of datapoints in input files\n");
        exit (EXIT_FAILURE);
        // printf("Size 1: %li\n",output1.size());
        // printf("Size 2: %li\n",output2.size());
        // printf("Size 3: %li\n",output3.size());
        // printf("Size 4: %li\n",output4.size());
    }

    JpSpace::vectorops vectorinstance(1);
    std::vector<int> redsubtractoutput;
  
    vectorinstance.Subtract(&output1, &output2, &redsubtractoutput);
    printf("Subtracted Red from Red background data\n");
    // for (int i: redsubtractoutput)
    // std::cout << i << ' ' << '\n';

    std::vector<int> greensubtractoutput;
    vectorinstance.Subtract(&output3, &output4, &greensubtractoutput);
    printf("Subtracted green from green background data\n");
    // for (int i: greensubtractoutput)
    // std::cout << i << ' ' << '\n';

    //Calculates Mean for corrected red and green values
    float red_mean_value;
    red_mean_value = vectorinstance.Sum(&redsubtractoutput)/redsubtractoutput.size();
    printf("The Mean value of the corrected Red data is: %f\n", red_mean_value);

    float green_mean_value;
    green_mean_value = vectorinstance.Sum(&greensubtractoutput)/greensubtractoutput.size();
    printf("The Mean value of the corrected Green data is: %f\n", green_mean_value);

    //Normalize datasets
    printf("Normalized Red\n");
    std::vector<float> normalized_red;
    vectorinstance.Division(&redsubtractoutput, red_mean_value, &normalized_red);
    // for (float i: normalized_red)
    // std::cout << i << ' ' << '\n';

    printf("Normalized Green\n");
    std::vector<float> normalized_green;
    vectorinstance.Division(&greensubtractoutput, green_mean_value, &normalized_green);
    // for (float i: normalized_green)
    // std::cout << i << ' ' << '\n';

    printf("Calculated Log Intensity Ratio\n");
    std::vector<float> LogIntensityRatio;
    instance.logIR(&normalized_red, &normalized_green, &LogIntensityRatio);

    std::ofstream outFile(argv[5]);
    // the important part
    for (const auto &value : LogIntensityRatio) outFile << value << "\n";
}