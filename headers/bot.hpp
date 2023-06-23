#ifndef BOT_H
#define BOT_H

#include "board.hpp"
#include <iostream>
#include <chrono>
#include <random>

class Bot {
private:
    char human;
    char bot;
    bool firstMove;
    
    Board board;

    int Minimax(int depth, int alpha, int beta, char currentPlayer);

public:
    static const int NOPLAYER = 100;

    Bot();

    void SetBot(char bot);
    int ReturnMove(const Board &board);
    void ResetBot();

};

#endif