//
// Created by иван on 29.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_CHARACTER_H
#define CONSOLE_ROUGELIKE_GAME_CHARACTER_H
#include "objects/GameObject.h"

class Character : public GameObject{
public:
    int GetHp(){ return this->hp; };
    virtual void TakeDamage(const int &damage) = 0;
protected:
    int hp;
};

#endif //CONSOLE_ROUGELIKE_GAME_CHARACTER_H
