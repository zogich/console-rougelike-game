

#ifndef CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#define CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#include <memory>
#include "Map.h"
#include "events/Events.h"


class GameLoop {
private:
    std::unique_ptr<Map> map;
    objectPool *pool;
    std::unique_ptr<GameTick> game_tick;
    std::unique_ptr<SignalForUpdateObjectPositionOnMap> signal_upd_obj_pos;
public:
    GameLoop();
    void startLoop();
    
};


#endif //CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
