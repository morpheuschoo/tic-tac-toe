#include "board.hpp"

Board::Board() {
    winner = NOWINNER;

    for(int i = 0; i != 9; i++)
        board[i] = i;
}

char Board::GetPosition(int position) const {
    return board[position];
}

void Board::Copy(const Board &mainBoard) {
    for(int i = 0; i != 9; i++)
        board[i] = mainBoard.GetPosition(i);
}

bool Board::LegalMove(int position) {
    if(position >= 0 && position <= 8) {
        if(board[position] != 'X' && board[position] != 'O')
            return true;
    }

    return false;
}

void Board::Move(int position, char currentPlayer) {
    board[position] = currentPlayer;
}

char Board::CheckWinner() {
    bool spaceEmpty = false;

    // check horizontal winners
    for(int i = 0; i < 9; i += 3) {
        if(board[i] == board[i + 1] && board[i + 1] == board[i + 2]) {
            return board[i];
        }
    }

    // check vertical winners
    for(int i = 0; i < 3; i++) {
        if(board[i] == board[i + 3] && board[i + 3] == board[i + 6]) {
            return board[i];
        }
    }
    
    // check diagonal winners
    if((board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6])) {
        return board[4];
    }

    // check tie
    for(const auto &value : board) {
        if(value != 'X' && value != 'O')
            spaceEmpty = true;
    }

    if(!spaceEmpty)
        return 'T';
    
    return NOWINNER;
}

void Board::CheckAndSetWinner() {
    winner = CheckWinner();
}

char Board::GetWinner() const {
    return winner;
}

void Board::ResetBoard() {
    for(int i = 0; i != 9; i++) {
        board[i] = i;
    }
    
    winner = NOWINNER;
}