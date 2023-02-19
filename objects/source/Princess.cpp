//
// Created by иван on 30.01.2023.
//

#include "objects/Objects.h"

Princess::Princess(const Point &pos) {
    this->SetSym('P');
    this->SetPos(pos);
}

void Princess::TakeDamage(const int &damage) {
}

void Princess::OnGameTick() {
}