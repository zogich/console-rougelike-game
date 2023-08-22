
#include <ncurses.h>
#include "objects/Objects.h"
#include <iostream>
#include <events/Events.h>


Knight::Knight(const Point &pos) {
    this->SetSym('K');
    this->SetPos(pos);
    this->hp = 10;
    this->damage = 1;
}

/**
 *
 * @return возвращает урон рыцаря
 */
int Knight::GetSelfDamage() {
    return this->damage;
}


void Knight::TakeDamage(const int &dmg) {
    this->hp -= damage;
}

void Knight::OnGameTick() {
    char key = getch();
   //ToDo rewrite character control way
    Point old_pos = this->GetPos();
    switch (key){
        case 'w':
            this->movePosWithOffset(0, -1);
            break;
        case 's':
            this->movePosWithOffset(0, 1);
            break;
        case 'a':
            this->movePosWithOffset(-1, 0);
            break;
        case 'd':
            this->movePosWithOffset(1, 0);
            break;
    }
}