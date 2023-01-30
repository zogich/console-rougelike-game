//
// Created by иван on 29.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_KNIGHT_H
#define CONSOLE_ROUGELIKE_GAME_KNIGHT_H
#include "objects/Character.h"

class Knight : public Character{
private:
    int damage;
public:
    Knight(const Point &pos);
    int GetDamage();
    void TakeDamage(const int &damage) override;
};


#endif //CONSOLE_ROUGELIKE_GAME_KNIGHT_H
