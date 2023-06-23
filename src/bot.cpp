#include "bot.hpp"

Bot::Bot() {
    human = NOPLAYER;
    bot = NOPLAYER;
    firstMove = true;
}

void Bot::SetBot(char bot) {
    this->bot = bot;
    human = (bot == 'X') ? 'O' : 'X';
}

int Bot::Minimax(int depth, int alpha, int beta, char currentPlayer) {
    char winner;
    int bestScore;
    int score;
    int bestMove;
    
    // checks for a winner
    winner = board.CheckWinner();

    if(winner == bot) {
        return 10;
    }
    else if(winner == human) {
        return -10;
    }
    else if(winner == 'T') {
        return 0;
    }

    if(currentPlayer == bot)
        bestScore = -100;
    else
        bestScore = 100;

    for(int i = 0; i < 9; i++) {
        if(board.LegalMove(i)) {
            if(currentPlayer == bot) {
                board.Move(i, bot);
                score = Minimax(depth + 1, alpha, beta, human);
                score = score - depth;
                board.Move(i, i);
                
                if(score > bestScore) {
                    bestScore = score;
                    bestMove = i;
                }

                // alpha-beta pruning
                if(score > alpha) {
                    alpha = score;
                }
                if(beta <= alpha)
                    break;
            } 
            else {
                board.Move(i, human);
                score = Minimax(depth + 1, alpha, beta, bot);
                score = score + depth;
                board.Move(i, i);

                if(score < bestScore) {
                    bestScore = score;
                }

                // alpha-beta pruning
                if(score < beta) {
                    beta = score;
                }
                if(beta <= alpha)
                    break;
            }
        }
    }

    if(depth == 0) {
        return bestMove;
    }
    else {
        return bestScore;
    }
}

int Bot::ReturnMove(const Board &mainBoard) {
    if(human != NOPLAYER && bot != NOPLAYER) {
        if(firstMove) {
            std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
            std::uniform_int_distribution<int> distribution(0, 9);

            firstMove = false;

            return distribution(generator);
        }
        else {
            board.Copy(mainBoard);
            return Minimax(0, -100, 100, bot);
        } 
    }

    return 100; 
}

void Bot::ResetBot() {
    firstMove = true;
}

