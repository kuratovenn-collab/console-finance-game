//
// Created by ASUS on 09.03.2026.
//
#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE   = "\033[34m";
const std::string BOLD   = "\033[1m";
const std::string GOLD = "\033[33m";
inline void printLine() {
    std::cout << BOLD << "------------------------------------------" << RESET << "\n";
}

inline void clearConsole() {
    for (int i = 0; i < 10; ++i) std::cout << "\n";
}
inline void drawBoard(int playerPos, int totalCells) {
    std::cout << BOLD << "\n BOARD: " << RESET;
    for (int i = 0; i < totalCells; ++i) {
        if (i == playerPos) {
            std::cout << BLUE << "[P]" << RESET;
        } else {
            std::cout << "[ ]";
        }
    }
    std::cout << "\n";
}
inline void typeWrite(const std::string& text, int delayMs = 30) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << std::endl;
}

#endif