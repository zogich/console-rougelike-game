#ifndef CONSOLE_ROUGELIKE_GAME_MAP_H
#define CONSOLE_ROUGELIKE_GAME_MAP_H
#include <vector>
#include <memory>
#include "objects/structures.h"
#include "Factory.h"

typedef std::map<char, std::vector<std::unique_ptr<GameObject>>> objectPool;

class Map {
private:
    std::vector<std::vector<Tile>> tiles;
    std::unique_ptr<Factory> factory;
    objectPool pool;
public:
    Map(const std::string &path_to_config_file);
    std::vector<std::vector<Tile>> getTiles() const;
    objectPool* getPool();
    void drawMap();
};
std::ostream& operator << (std::ostream &os, const Map &map);

#endif //CONSOLE_ROUGELIKE_GAME_MAP_H
