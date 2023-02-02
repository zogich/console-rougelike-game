//

//

#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(const std::string &path_to_config_file) {
    std::ifstream file(path_to_config_file);
    std::string line;
    int line_count = 0;
    while (getline(file, line)){
        int column_count = 0;
        this->tiles.emplace_back(std::vector<TileMap>());
        for (char sym: line){
            this->tiles.back().emplace_back(TileMap(Point{line_count, column_count},  sym));
            column_count++;
        }
        line_count++;
    }
}

std::vector<std::vector<TileMap>> Map::getTiles() const {
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