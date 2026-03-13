#pragma once
#include <stdexcept>
#include <string>
class CursedException : public std::runtime_error {
public:
    explicit CursedException(const std::string& message)
        : std::runtime_error(message) {}
};
class InsufficientFundsException : public std::runtime_error {
public:
    explicit InsufficientFundsException(const std::string& message)
        : std::runtime_error(message) {}
};
class GameOverException : public std::runtime_error {
public:
    explicit GameOverException(const std::string& message)
        : std::runtime_error(message) {}
};