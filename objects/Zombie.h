//
// Created by иван on 30.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_ZOMBIE_H
#define CONSOLE_ROUGELIKE_GAME_ZOMBIE_H
#include "objects/Character.h"

class Zombie : public Character {
private:
    int damage;
public:
    Zombie(const Point &pos);
    int GetDamage();
    void TakeDamage(const int &dmg) override;
};


#endif //CONSOLE_ROUGELIKE_GAME_ZOMBIE_H
