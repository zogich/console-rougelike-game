//
// Created by иван on 30.01.2023.
//

#include "Zombie.h"

Zombie::Zombie(const Point &pos) {
    this->SetSym('Z');
    this->SetPos(pos);
    this->damage = 1;
    this->hp = 10;
}

int Zombie::GetDamage() {
    return this->damage;
}

void Zombie::TakeDamage(const int &dmg) {
    this->hp -= dmg;
}