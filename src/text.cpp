#include "text.hpp"

Text::Text(const std::string &fontFileName, unsigned int charSize, sf::Color fillColour, sf::Color outlineColour, float outlineThickness) {
    font.loadFromFile("assets/fonts/" + fontFileName);

    text.setFont(font);
    text.setFillColor(fillColour);
    text.setOutlineColor(outlineColour);
    text.setOutlineThickness(outlineThickness);
    text.setCharacterSize(charSize);
}

Text::Text(const std::string &fontFileName, unsigned int charSize, sf::Color wholeColour) {
    font.loadFromFile("assets/fonts/" + fontFileName);

    text.setFont(font);
    text.setFillColor(wholeColour);
    text.setCharacterSize(charSize);
}

void Text::Update(const sf::String &textString, unsigned int charSize, sf::Vector2f position) {
    text.setString(textString);
    text.setCharacterSize(charSize);

    textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    
    text.setPosition(position);
}

void Text::Update(const sf::String &textString, sf::Vector2f position) {
    text.setString(textString);

    textRect = text.getLocalBounds();
    text.setOrigin(textRect.width / 2, textRect.height / 2);
    
    text.setPosition(position);
}

void Text::UpdateColor(sf::Color colour) {
    text.setFillColor(colour);
}

void Text::Draw(sf::RenderWindow &window) {
    window.draw(text);
}