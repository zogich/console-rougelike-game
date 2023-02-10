

#ifndef CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#define CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#include <vector>
#include <memory>
#include "Map.h"

class GameLoop {
private:
    std::unique_ptr<Map> map;
    objectPool *pool;
public:
    GameLoop();
    void startLoop();

};


#endif //CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
