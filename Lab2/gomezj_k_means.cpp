/* 
02/27/2022
Juan Pablo Gomez
Header file for functions used in part2 of lab 1
*/

#include "gomezj_k_means.hpp"
#include "gomezj_stats.hpp"

JpSpaceCluster::Kcluster::Kcluster() {

}
void JpSpaceCluster::Kcluster::openfile(std::string filename, std::vector<float> *outputname){

    std::ifstream file;
    float element;
    file.open(filename);
    if(file.fail()){
        printf ("Data file is missing is missing\n");
        exit (EXIT_FAILURE);
    }
    //printf("printing data");
    while (file >> element)
    {
        outputname->push_back(element);
        //printf("%f\n", element);
    }
    file.close();
}

float JpSpaceCluster::Kcluster::distance(float data) {
    float distance = 0.0;
    float mean = this->mean;
    // calculate distance of data to mean
    distance = abs(data - mean);
    return distance;
}

void JpSpaceCluster::Kcluster::set_obj_name(std::string name) {
    this->name = name;
}

void JpSpaceCluster::Kcluster::set_obj_mean(float mean) {
    this->mean = mean;
}

std::string JpSpaceCluster::Kcluster::get_obj_name() {
    return name;
}

float JpSpaceCluster::Kcluster::get_obj_mean() {
    return mean;

}


int main(int argc, char* argv[]){

    JpSpaceCluster::Kcluster instance;
    std::vector<float> data;
    //open file and see if exists
    instance.openfile("log_ratio_input.dat", &data);
    float distance1, distance2, distance3;

    //Initializing three cluster classes, their names, and means
    JpSpaceCluster::Kcluster cluster1;
    JpSpaceCluster::Kcluster cluster2;
    JpSpaceCluster::Kcluster cluster3;

    cluster1.set_obj_name("Supressed");
    cluster2.set_obj_name("Stationary");
    cluster3.set_obj_name("Expressed ");

    //Set log ratio mean values

    cluster1.set_obj_mean(-0.5);
    cluster2.set_obj_mean(0.0);
    cluster3.set_obj_mean(0.5);

    //calculate distance from each point to each cluster
    float criteria = 1.0 ;
    int run=1;
    while(criteria > 0.0001){
        // printf("Starting run %i\n", run);
        // printf("Old mean for cluster1 is %f\n", cluster1.get_obj_mean());
        // printf("Old mean for cluster2 is %f\n", cluster2.get_obj_mean());
        // printf("Old mean for cluster3 is %f\n", cluster3.get_obj_mean());
        for (float element : data){
            distance1 = cluster1.distance(element);
            distance2 = cluster2.distance(element);
            distance3 = cluster3.distance(element);
            //compare distance and means

            if (distance1 < distance2 && distance1 < distance3) {
                cluster1.cluster_set.push_back(element);
            }
            else if (distance2 < distance1 && distance2 < distance3) {
                cluster2.cluster_set.push_back(element);
            }
            //else if (distance3 < distance1 && distance3 < distance2) {
            else{
                cluster3.cluster_set.push_back(element);
            }
        
        }
        //INITIALIZE VARIABLES FOR CALCULATING NEW MEANS
        mySpace::stats statcluster1(1, 1);
        mySpace::stats statcluster2(2, 2);
        mySpace::stats statcluster3(3, 3);
        //Set old mean values to temp variables
        float mean_supressed = cluster1.get_obj_mean();
        float mean_stationary = cluster2.get_obj_mean();
        float mean_expressed = cluster3.get_obj_mean();

        statcluster1.set_mean(&cluster1.cluster_set);
        float new_mean_value1 = statcluster1.get_mean();
        // printf("The Suppresed Mean value is: %f\n", new_mean_value1);

        statcluster2.set_mean(&cluster2.cluster_set);
        float new_mean_value2 = statcluster2.get_mean();
        // printf("The Stationary Mean value is: %f\n", new_mean_value2);

        statcluster3.set_mean(&cluster3.cluster_set);
        float new_mean_value3 = statcluster3.get_mean();
        //printf("The Expressed Mean value is: %f\n", new_mean_value3);

        //calculate criteria
        criteria = abs(mean_supressed - new_mean_value1) + abs(mean_stationary - new_mean_value2) + abs(mean_expressed - new_mean_value3);

        //printf("the criteria is %f\n", criteria);

        //Set new means for next loop
        cluster1.set_obj_mean(new_mean_value1);
        cluster2.set_obj_mean(new_mean_value2);
        cluster3.set_obj_mean(new_mean_value3);

        //print size
        // printf("Cluster 1 size: %li\n",cluster1.cluster_set.size());
        // printf("Cluster 2 size: %li\n",cluster2.cluster_set.size());
        // printf("Cluster 3 size: %li\n",cluster3.cluster_set.size());
        //clear vector
        cluster1.cluster_set.clear();
        cluster2.cluster_set.clear();
        cluster3.cluster_set.clear();
        run = run + 1;
        }   
    //Final run with good means calculated
    // printf("Starting final run\n");

    //Get gene names from file
    std::ifstream genefile;
    std::string element;
    std::vector<std::string> gene_name;

    genefile.open("microarray/gene_list.txt");
    if(genefile.fail()){
        printf ("gene name list is missing\n");
        exit (EXIT_FAILURE);
    }
    //printf("printing data\n");
    while (genefile >> element)
    {
        gene_name.push_back(element);
        //std::cout << element << ' ' << '\n';
    }
    
    genefile.close();

    int gene_num = 0;
    std::ofstream suppressedfile;
    std::ofstream stationaryfile;
    std::ofstream expressedfile;
    suppressedfile.open ("suppressed_genes.txt");
    stationaryfile.open ("stationary_genes.txt");
    expressedfile.open ("expressed_genes.txt");
    
    for (float element : data){
        
        distance1 = cluster1.distance(element);
        distance2 = cluster2.distance(element);
        distance3 = cluster3.distance(element);
        //compare distance and means

        if (distance1 < distance2 && distance1 < distance3) {
            cluster1.cluster_set.push_back(element);
            suppressedfile << gene_name[gene_num] << '\n';
        }
        else if (distance2 < distance1 && distance2 < distance3) {
            cluster2.cluster_set.push_back(element);
            stationaryfile << gene_name[gene_num] << '\n';
        }
        //else if (distance3 < distance1 && distance3 < distance2) {
        else{
            cluster3.cluster_set.push_back(element);
            expressedfile << gene_name[gene_num] << '\n';
        }
        gene_num = gene_num + 1;
    }
    printf("The Final mean for Suppressed gene cluster is %f\n", cluster1.get_obj_mean());
    printf("The Final mean for Stationary gene cluster is %f\n", cluster2.get_obj_mean());
    printf("The Final mean for Expressed gene cluster is %f\n", cluster3.get_obj_mean());
    printf("Number of Suppressed genes: %li\n",cluster1.cluster_set.size());
    printf("Number of Stationary genes: %li\n",cluster2.cluster_set.size());
    printf("Number of Expressed genes: %li\n",cluster3.cluster_set.size());
    suppressedfile.close();
    stationaryfile.close();
    expressedfile.close();
}
