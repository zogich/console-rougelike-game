
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

int Knight::GetSelfDamage() {
    return this->damage;
}
void Knight::TakeDamage(const int &damage) {
    this->hp -= damage;
}

void Knight::OnGameTick() {
    char key = getch();
   //ToDo rewrite character control way
    Point old_pos = this->GetPos();
    switch (key){
        case 'w':
            this->SetPos({this->GetPos().x, this->GetPos().y-1});
            Character::signal_upd_pos->callEvent(old_pos, this->GetPos(), this->GetSym());
            break;
        case 's':
            this->SetPos({this->GetPos().x, this->GetPos().y+1});
            Character::signal_upd_pos->callEvent(old_pos, this->GetPos(), this->GetSym());
            break;
        case 'a':
            this->SetPos({this->GetPos().x-1, this->GetPos().y});
            Character::signal_upd_pos->callEvent(old_pos, this->GetPos(), this->GetSym());
            break;
        case 'd':
            this->SetPos({this->GetPos().x+1, this->GetPos().y});
            Character::signal_upd_pos->callEvent(old_pos, this->GetPos(), this->GetSym());
            break;
    }
}