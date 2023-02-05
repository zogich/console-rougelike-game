//
// Created by иван on 30.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_PRINCESS_H
#define CONSOLE_ROUGELIKE_GAME_PRINCESS_H
#include "objects/Character.h"

class Princess : public Character{
public:
    Princess(const Point &pos);
    void TakeDamage(const int &damage) override;
};


#endif //CONSOLE_ROUGELIKE_GAME_PRINCESS_H
