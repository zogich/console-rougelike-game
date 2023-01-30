//
// Created by иван on 29.01.2023.
//

#include "Knight.h"
Knight::Knight(const Point &pos) {
    this->SetSym('K');
    this->SetPos(pos);
    this->hp = 10;
    this->damage = 1;
}
int Knight::GetDamage() {
    return this->damage;
}
void Knight::TakeDamage(const int &damage) {
    this->hp -= damage;
}
