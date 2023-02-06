//
// Created by иван on 30.01.2023.
//

#include "objects/Objects.h"
Dragon::Dragon(const Point &pos) {
    this->SetSym('D');
    this->SetPos(pos);
    this->hp = 20;
    this->damage = 2;
}

int Dragon::GetDamage() {
    return this->damage;
}

void Dragon::TakeDamage(const int &dmg) {
    this->hp -= dmg;
}