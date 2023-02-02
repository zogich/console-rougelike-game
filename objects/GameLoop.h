

#ifndef CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#define CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
#include <vector>
#include <memory>
#include "Character.h"
#include "Knight.h"
#include "Princess.h"
#include "Map.h"

class GameLoop {
private:
    std::vector<std::unique_ptr<Character>> monsters;
    std::unique_ptr<Knight> knight;
    std::unique_ptr<Princess> princess;
    std::unique_ptr<Map> map;
public:
    GameLoop();
    void startLoop();
};


#endif //CONSOLE_ROUGELIKE_GAME_GAMELOOP_H
