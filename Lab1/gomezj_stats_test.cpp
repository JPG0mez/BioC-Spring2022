#include "gomezj_stats.hpp"

int main(int argc, char *argv[]) {


    std::ifstream fin("ERP/ERP00/ERP0010.txt");
    
    std::vector<float> *data;
    int element;
    while (fin >> element)
    {
        data->push_back(element);
    }

   
    mySpace::stats somevariablename;

    
    somevariablename.set_max(data);

    somevariablename.get_max();
}
