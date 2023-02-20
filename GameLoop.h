

#ifndef CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#define CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#include <vector>
#include <memory>
#include "Map.h"
#include "events/Events.h"


class GameLoop {
private:
    std::unique_ptr<Map> map;
    objectPool *pool;
    std::unique_ptr<GameTick> game_tick;
public:
    GameLoop();
    void startLoop();
    
};


#endif //CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
