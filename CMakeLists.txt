cmake_minimum_required(VERSION 3.26)

project(VisualNovelDice)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GAME_SOURCES
        src/Game.cpp
        src/Board.cpp
        src/Dice.cpp
        src/Player.cpp
        src/GamblingEvent.cpp
        src/TrapEvent.cpp
        src/CorpseEvent.cpp
        src/PillEvent.cpp
        src/InsiderTradingEvent.cpp
        src/BossEvent.cpp
)

add_executable(VisualNovelDice
        src/main.cpp
        ${GAME_SOURCES}
        include/Exceptions.h
        include/CorpseEvent.h
        include/PillEvent.h
        include/BossEvent.h
)
target_include_directories(VisualNovelDice PRIVATE include)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests
        tests/test.cpp
        ${GAME_SOURCES}
)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)