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
        include/Exceptions.h
        src/CorpseEvent.cpp
        include/CorpseEvent.h
        src/PillEvent.cpp
        include/PillEvent.h
        src/InsiderTradingEvent.cpp
        include/BossEvent.h
        src/BossEvent.cpp
)
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        tests
        tests/test.cpp
        src/Player.cpp
        src/Dice.cpp
)

target_link_libraries(
        tests
        gtest_main
)

include(GoogleTest)

gtest_discover_tests(tests)