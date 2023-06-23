#ifndef TEXT_H
#define TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Text {
private:
    sf::Font font;
    sf::Text text;
    sf::FloatRect textRect;

public:
    Text(const std::string &fontFileName, unsigned int charSize, sf::Color fillColour, sf::Color outlineColour, float outlineThickness);
    Text(const std::string &fontFileName, unsigned int charSize, sf::Color wholeColour);

    void Update(const sf::String &textString, unsigned int charSize, sf::Vector2f position);
    void Update(const sf::String &textString, sf::Vector2f position);
    void UpdateColor(sf::Color colour);
    
    void Draw(sf::RenderWindow &window);
};

#endif