#ifndef BOARD_H
#define BOARD_H

#include "text.hpp"
#include <SFML/Graphics.hpp>

class Board {
private:
    char board[9];
    char winner;

public:
    const static int NOWINNER = 100;

    Board();

    char GetPosition(int position) const;
    void Copy(const Board &mainBoard);
    bool LegalMove(int position);
    void Move(int position, char currentPlayer);
    char CheckWinner();
    void CheckAndSetWinner();
    char GetWinner() const ;
    void ResetBoard();

};

#endif