//
// Created by иван on 30.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_DRAGON_H
#define CONSOLE_ROUGELIKE_GAME_DRAGON_H
#include "objects/Character.h"

class Dragon : public Character{
private:
    int damage;
public:
    Dragon(const Point &pos);
    int GetDamage();
    void TakeDamage(const int &dmg) override;
};


#endif //CONSOLE_ROUGELIKE_GAME_DRAGON_H
