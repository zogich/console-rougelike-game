//

//

#include "Map.h"
#include <fstream>
#include <iostream>
#include <ncurses.h>

Map::Map(const std::string &path_to_config_file) {
    std::ifstream file(path_to_config_file);
    std::string line;
    this->factory = std::make_unique<Factory>();
    int line_count = 0;
    while (getline(file, line)){
        int column_count = 0;
        this->tiles.emplace_back(std::vector<Tile>());
        for (char sym: line){
            this->tiles.back().emplace_back(Tile(Point{ column_count, line_count},  sym));

            if (sym != '.'){
                this->pool[sym].push_back(std::unique_ptr<GameObject>(this->factory->createObjectFromSym(sym, {column_count, line_count})));
            }

            column_count++;
        }
        line_count++;
    }

}

std::vector<std::vector<Tile>> Map::getTiles() const {
    return this->tiles;
}

objectPool* Map::getPool() {
    return &this->pool;
}


void Map::drawMap() {
    clear();
    std::string map_matrix = "";
    for ( const auto& line: this->tiles ){
        for ( auto tile: line ){
            map_matrix += tile.sym;
        }
        map_matrix += '\n';
    }
    printw(map_matrix.c_str());
    refresh();
}

void Map::updateObjectsPosTiles() {

    for ( auto &lane: this->tiles ){
        for ( auto &tile: lane ){
            tile.sym = '.';
        }
    }

    for (const auto& map_object: this->pool) {
        for (const auto& object: map_object.second) {
            this->tiles[object->GetPos().y][object->GetPos().x].sym = object->GetSym();
        }
    }
}

void Map::moveObjectSym(const Point &old_pos, const Point &new_pos, const char &sym) {
    this->tiles[old_pos.y][old_pos.x].sym = '.';
    this->tiles[new_pos.y][new_pos.x].sym = sym;
}

std::ostream& operator << (std::ostream &os, const Map &map){
    for ( const auto& line: map.getTiles() ){
        for ( auto tile: line ){
            os << tile.sym;
        }
        os << std::endl;
    }
    return os;
}


