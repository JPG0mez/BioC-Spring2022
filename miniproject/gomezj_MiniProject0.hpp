/* Juan Pablo Gomez Postigo
* 2/18/22
* This is my first resort
* Miniproject
*/

#ifndef FalkensMaze
#define FalkensMaze

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

namespace WarGames {
    class TimeHacking {
    public:
        TimeHacking(std::string objectToHack);
        
        void setTimeToHack(int seconds);
        int getTimeToHack();
        std::string getObjectToHack();
        void hackTime();
    
    private:
        int time_to_hack;
        std::string objectToHack;
    };
}

#endif