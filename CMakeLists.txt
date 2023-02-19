cmake_minimum_required(VERSION 3.23)
project(console_rougelike_game)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
include_directories(.)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(console_rougelike_game
        main.cpp objects/structures.h objects/source/Knight.cpp objects/source/Princess.cpp objects/source/Zombie.cpp objects/source/Dragon.cpp objects/source/Wall.cpp
        Map.cpp Map.h GameLoop.h GameLoop.cpp Factory.cpp Factory.h objects/Objects.h events/Events.h)

target_link_libraries(console_rougelike_game ${CURSES_LIBRARIES})