//
// Created by иван on 01.02.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_MAP_H
#define CONSOLE_ROUGELIKE_GAME_MAP_H
#include <vector>
#include <memory>
#include "objects/structures.h"

class Map {
private:
    std::vector<std::vector<std::unique_ptr<TileMap>>> tiles;
public:
    Map(const std::string &path_to_config_file);
};


#endif //CONSOLE_ROUGELIKE_GAME_MAP_H
