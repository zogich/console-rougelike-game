//
// Created by иван on 29.01.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_STRUCTURES_H
#define CONSOLE_ROUGELIKE_GAME_STRUCTURES_H
typedef struct Point{
    int x;
    int y;
}Point;

typedef struct TileMap{
    Point pos{};
    char sym;
    TileMap(Point position, char symbol) {
        this->pos = position;
        this->sym = symbol;
    };
}TileMap;

#endif //CONSOLE_ROUGELIKE_GAME_STRUCTURES_H
