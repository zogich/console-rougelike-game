//
// Created by иван on 29.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_STRUCTURES_H
#define CONSOLE_ROUGELIKE_GAME_STRUCTURES_H
#include <memory>

typedef struct Point{
    int x;
    int y;
}Point;

typedef struct Tile{
    Point pos{};
    char sym;
    Tile(Point position, char symbol) {
        this->pos = position;
        this->sym = symbol;
    };
}Tile;

#endif //CONSOLE_ROUGELIKE_GAME_STRUCTURES_H
