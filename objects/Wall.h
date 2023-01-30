//
// Created by иван on 30.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_WALL_H
#define CONSOLE_ROUGELIKE_GAME_WALL_H
#include "objects/GameObject.h"

class Wall : public GameObject{
public:
    Wall(const Point &pos);
};


#endif //CONSOLE_ROUGELIKE_GAME_WALL_H
