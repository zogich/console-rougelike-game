
#include <ncurses.h>
#include "objects/Objects.h"
#include <iostream>

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
    switch (key){
        case 'w':
            this->SetPos({this->GetPos().x, this->GetPos().y-1});
            break;
        case 's':
            this->SetPos({this->GetPos().x, this->GetPos().y+1});
            break;
        case 'a':
            this->SetPos({this->GetPos().x-1, this->GetPos().y});
            break;
        case 'd':
            this->SetPos({this->GetPos().x+1, this->GetPos().y});
            break;
    }
}