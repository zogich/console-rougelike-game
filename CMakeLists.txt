cmake_minimum_required(VERSION 3.23)
project(console_rougelike_game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(console_rougelike_game
        main.cpp objects/structures.h objects/source/Knight.cpp objects/source/Princess.cpp objects/source/Zombie.cpp objects/source/Dragon.cpp objects/source/Wall.cpp
        Map.cpp Map.h GameLoop.h GameLoop.cpp Factorys.cpp Factorys.h objects/Objects.h)
