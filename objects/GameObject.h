//
// Created by иван on 29.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_GAMEOBJECT_H
#define CONSOLE_ROUGELIKE_GAME_GAMEOBJECT_H
#include "objects/structures.h"

class GameObject {
private:
    char sym;
    Point coordinates;
public:
    Point GetPos() { return coordinates; };
    char GetSym() const { return sym; };
protected:
    void SetPos(Point pos){
        this->coordinates = pos;
    };
    void SetSym(char symbol){
        this->sym = symbol;
    }
};


#endif //CONSOLE_ROUGELIKE_GAME_GAMEOBJECT_H
