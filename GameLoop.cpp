#include "GameLoop.h"
#include <string>
#include <iostream>

GameLoop::GameLoop() {
    this->map = std::make_unique<Map>("/Users/ivan/Desktop/egor_learning/github/console-rougelike-game/map.txt");
    this->pool = this->map->getPool();
    std::cout<< *this->map;
    std::cout << this->pool->size();
}
