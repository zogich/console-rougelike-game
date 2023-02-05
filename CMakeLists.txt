cmake_minimum_required(VERSION 3.23)
project(console_rougelike_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(console_rougelike_game
        main.cpp objects/GameObject.h objects/structures.h objects/Character.h objects/Knight.cpp objects/Knight.h objects/Princess.cpp objects/Princess.h objects/Zombie.cpp objects/Zombie.h objects/Dragon.cpp objects/Dragon.h objects/Wall.cpp objects/Wall.h
        objects/Map.cpp objects/Map.h objects/GameLoop.h objects/GameLoop.cpp Factorys.cpp Factorys.h)
