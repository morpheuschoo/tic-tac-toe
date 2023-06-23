#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
private:
    char startingPlayer;
    char currentPlayer;
    static const int INVALIDPOS = 100;
    static const int NOPLAYER = 100;

public: 
    Player();

    void SetPlayer(char startingPlayer);
    char GetCurrentPlayer();
    int ObtainPosition(sf::Event &event);
    void Switch();
    void ResetPlayer();
    
};

#endif