#include "GameLoop.h"
#include <string>
#include <ncurses.h>

GameLoop::GameLoop() {
    this->map = std::make_unique<Map>("/Users/ivan/Desktop/egor_learning/github/console-rougelike-game/map.txt");
    this->pool = this->map->getPool();

    this->game_tick = std::make_unique<GameTick>();
    this->signal_upd_obj_pos = std::make_unique<SignalForUpdateObjectPositionOnMap>();
    this->signal_upd_obj_pos->subscribe(&(*this->map));
    Character::setSignalUpdPos(&*this->signal_upd_obj_pos);

    for (auto &one_map: *this->pool){
        for ( auto &object: one_map.second ){
            this->game_tick->subscribe(&(*object));
        }
    }

    this->startLoop();
}

void GameLoop::startLoop() {
    initscr();
    noecho();
    this->map->drawMap();
    while (true){
        this->game_tick->callEvent();
        this->map->drawMap();
    }
    endwin();
}