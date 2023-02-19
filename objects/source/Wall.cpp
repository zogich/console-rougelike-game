//
// Created by иван on 30.01.2023.
//

#include "objects/Objects.h"

Wall::Wall(const Point &pos) {
    this->SetSym('#');
    this->SetPos(pos);
}

void Wall::OnGameTick() {

}