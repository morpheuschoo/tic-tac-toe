#include "player.hpp"

Player::Player() {
    startingPlayer = NOPLAYER;
}

void Player::SetPlayer(char startingPlayer) {
    this->startingPlayer = startingPlayer;
    
}

char Player::GetCurrentPlayer() {
    return currentPlayer;
}

int Player::ObtainPosition(sf::Event &event) {
    int row;
    int column;
    
    for(int i = 0; i != 9; i++) {
        row = static_cast<int>(i / 3);
        column = i % 3;

        if(event.mouseButton.x > 100 + (column * 200) && 
            event.mouseButton.x < 300 + (column * 200) && 
            event.mouseButton.y > 150 + (row * 200)    && 
            event.mouseButton.y < 350 + (row * 200)) 
        {
            return i;
        }
    }

    return INVALIDPOS;
}

void Player::Switch() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void Player::ResetPlayer() {
    currentPlayer = startingPlayer;
}