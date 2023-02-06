//

//

#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(const std::string &path_to_config_file) {
    std::ifstream file(path_to_config_file);
    std::string line;
    this->wall_factory = std::make_unique<WallFactory>();
    this->knight_factory = std::make_unique<KnightFactory>();
    this->zombie_factory = std::make_unique<ZombieFactory>();
    this->dragon_factory = std::make_unique<DragonFactory>();
    this->princess_factory = std::make_unique<PrincessFactory>();

    int line_count = 0;
    while (getline(file, line)){
        int column_count = 0;
        this->tiles.emplace_back(std::vector<Tile>());
        for (char sym: line){
            this->tiles.back().emplace_back(Tile(Point{line_count, column_count},  sym));
            column_count++;
        }
        line_count++;
    }
}

std::vector<std::vector<Tile>> Map::getTiles() const {
    return this->tiles;
}

std::ostream& operator << (std::ostream &os, const Map &map){
    for ( auto line: map.getTiles() ){
        for ( auto tile: line ){
            os << tile.sym;
        }
        os << std::endl;
    }
    return os;
}