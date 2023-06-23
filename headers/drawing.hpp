#ifndef DRAWING_H
#define DRAWING_H

#include "text.hpp"
#include "board.hpp"
#include <SFML/Graphics.hpp>

class Drawing {
private:
    Text title;
    Text endText;
    Text endSubtext;

    sf::Texture boardTexture;
    sf::Texture playerTexture;

    sf::IntRect uvRect;

    sf::Sprite boardSprite;
    sf::Sprite playerSprite;
    
    const Board &board;

public:
    Drawing(const Board &board);

    void RenderObjects();
    void Draw(sf::RenderWindow &window);

};

#endif