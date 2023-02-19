#include "GameLoop.h"
#include <string>
#include <ncurses.h>


GameLoop::GameLoop() {
    this->map = std::make_unique<Map>("/Users/ivan/Desktop/egor_learning/github/console-rougelike-game/map.txt");
    this->pool = this->map->getPool();
    this->startLoop();
}

void GameLoop::startLoop() {
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    this->map->drawMap();
    while (true){
        char key = getch();
    }
    endwin();
}