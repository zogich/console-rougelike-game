//
// Created by иван on 01.02.2023.
//

#ifndef CONSOLE_ROUGELIKE_GAME_MAP_H
#define CONSOLE_ROUGELIKE_GAME_MAP_H
#include <vector>
#include <memory>
#include "objects/structures.h"
#include "Factory.h"

class Map {
private:
    std::vector<std::vector<Tile>> tiles;
    std::unique_ptr<Factory> factory;
public:
    Map(const std::string &path_to_config_file);
    std::vector<std::vector<Tile>> getTiles() const;
    
};
std::ostream& operator << (std::ostream &os, const Map &map);

#endif //CONSOLE_ROUGELIKE_GAME_MAP_H
