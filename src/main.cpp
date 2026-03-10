#include "Game.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    #endif
    std::string name;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    Game game(name);
    game.run();
    return 0;
}