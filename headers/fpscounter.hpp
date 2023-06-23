#ifndef FPSCOUNTER_H
#define FPSCOUNTER_H

#include "text.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class FpsCounter {
private:
    Text fpsText;

    sf::Clock clock;
    float currentTime;
    
public:
    FpsCounter();

    void Update();
    void Draw(sf::RenderWindow &window);
};

#endif