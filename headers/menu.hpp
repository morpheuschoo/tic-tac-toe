#ifndef MENU_H
#define MENU_H

#include "text.hpp"
#include <SFML/Graphics.hpp>

class Menu {
private:
    Text title;
    Text top;
    Text bottom;

    sf::Vector2f topButtonPos;
    sf::Vector2f bottomButtonPos;
    sf::Vector2f buttonSize;

    sf::RectangleShape topButton;
    sf::RectangleShape bottomButton;
    sf::RectangleShape background;
    
public:
    int selection;
    bool isMenuUp;
    static const int NOSELECTION = 100;

    Menu();
    
    bool ObtainSelection(sf::Event &event);
    void ShowMenu(sf::Event &event);
    void Draw(sf::RenderWindow &window);
};

#endif