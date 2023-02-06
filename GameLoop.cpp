//
// Created by иван on 01.02.2023.
//

#include "GameLoop.h"
#include <string>

GameLoop::GameLoop() {
    this->map = std::make_unique<Map>("map.txt");
}