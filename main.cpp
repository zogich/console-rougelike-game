#include "iostream"
#include "Map.h"
#include <iostream>

int main(){
    Map map("/Users/ivan/Desktop/egor_learning/github/console-rougelike-game/map.txt");
    std::cout << map << std::endl;
    return 0;
}
