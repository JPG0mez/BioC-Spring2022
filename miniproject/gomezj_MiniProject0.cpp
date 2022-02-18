/* Juan Pablo Gomez Postigo
* 2/18/22
* This is my last resort
* Miniproject
*/


#include "gomezj_MiniProject0.hpp"


WarGames::TimeHacking::TimeHacking(std::string objectToHack){

    this->objectToHack = objectToHack;
}

void WarGames::TimeHacking::setTimeToHack(int seconds){

    this->time_to_hack = seconds;
}

int WarGames::TimeHacking::getTimeToHack(){

    return this->time_to_hack;

}

std::string WarGames::TimeHacking::getObjectToHack(){

    return this->objectToHack;
}

void WarGames::TimeHacking::hackTime(){
    sleep(this->time_to_hack);
    printf("Time has been hacked\n");
}



int main(int argc, char * argv[]) {

    std::string objectothack;
    int timetohackfor;
    printf("GREETINGS PROFESSOR FALKEN.\n");

    printf("What object would you like to hack?: ");
    std::cin >> objectothack; 
    printf("How many seconds do you want to hack it for?: ");
    std::cin >> timetohackfor;

    WarGames::TimeHacking timetohack(objectothack);

    std::string object_value = timetohack.getObjectToHack();
    timetohack.setTimeToHack(timetohackfor);
    int time_value = timetohack.getTimeToHack();
    std::cout << "Your object to hack is: " << object_value << "\n"; 
    std::cout << "Your total time to hack is: " << time_value << "\n";
    printf("Hacking in progress\n");
    
    timetohack.hackTime();

}
