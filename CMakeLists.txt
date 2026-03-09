cmake_minimum_required(VERSION 3.26)

project(VisualNovelDice)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(VisualNovelDice
        src/main.cpp
        src/Game.cpp
        src/Board.cpp
        src/Dice.cpp
        src/Player.cpp
        src/GamblingEvent.cpp
        src/TrapEvent.cpp
        src/Exceptions.h
)