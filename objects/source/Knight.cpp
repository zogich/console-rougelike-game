
#include "objects/Objects.h"
Knight::Knight(const Point &pos) {
    this->SetSym('K');
    this->SetPos(pos);
    this->hp = 10;
    this->damage = 1;
}

int Knight::GetSelfDamage() {
    return this->damage;
}
void Knight::TakeDamage(const int &damage) {
    this->hp -= damage;
}

void Knight::OnGameTick() {
}