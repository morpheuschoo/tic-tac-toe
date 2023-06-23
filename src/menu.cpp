#include "menu.hpp"

Menu::Menu() 
    : top("luckiestguy.ttf", 60, sf::Color::Black),
      bottom("luckiestguy.ttf", 60, sf::Color::Black),
      title("luckiestguy.ttf", 150, sf::Color::Black)
{
    background.setSize(sf::Vector2f(800.0f, 800.0f));
    background.setPosition(sf::Vector2f(0.0f, 0.0f));
    background.setFillColor(sf::Color(234, 114, 114, 200));
    
    topButtonPos = sf::Vector2f(400.0f, 300.0f);
    bottomButtonPos = sf::Vector2f(400.0f, 500.0f);
    buttonSize = sf::Vector2f(350.0f, 150.0f);
    
    title.Update("PAUSED", sf::Vector2f(400.0f, 50.0f));
    top.Update("1 PLAYER", sf::Vector2f(topButtonPos.x, topButtonPos.y - 10.0f));
    bottom.Update("2 PLAYER", sf::Vector2f(bottomButtonPos.x, bottomButtonPos.y - 10.0f));

    topButton.setSize(buttonSize);
    bottomButton.setSize(buttonSize);
    
    topButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);
    bottomButton.setOrigin(buttonSize.x / 2, buttonSize.y / 2);

    topButton.setPosition(topButtonPos);
    bottomButton.setPosition(bottomButtonPos);

    topButton.setOutlineColor(sf::Color::Black);
    bottomButton.setOutlineColor(sf::Color::Black);

    topButton.setOutlineThickness(10.0f);
    bottomButton.setOutlineThickness(10.0f);

    isMenuUp = true;
    selection = NOSELECTION;
}

bool Menu::ObtainSelection(sf::Event &event) {
    if(event.type == sf::Event::MouseButtonPressed) {
        if(event.mouseButton.x > 225 &&
            event.mouseButton.x < 225 + buttonSize.x &&
            event.mouseButton.y > 225 &&
            event.mouseButton.y < 225 + buttonSize.y)
        {
            selection = 1;
            
            topButton.setOutlineColor(sf::Color::Green);
            bottomButton.setOutlineColor(sf::Color::Black);

            top.UpdateColor(sf::Color::Green);
            bottom.UpdateColor(sf::Color::Black);
            
            isMenuUp = false;
            
            return true;
        }

        if(event.mouseButton.x > 225 &&
        event.mouseButton.x < 225 + buttonSize.x &&
        event.mouseButton.y > 425 &&
        event.mouseButton.y < 425 + buttonSize.y)
        {
            selection = 2;

            topButton.setOutlineColor(sf::Color::Black);
            bottomButton.setOutlineColor(sf::Color::Green);
            
            top.UpdateColor(sf::Color::Black);
            bottom.UpdateColor(sf::Color::Green);

            isMenuUp = false;

            return true;
        }
    }

    return false;
}

void Menu::ShowMenu(sf::Event &event) {
    if(selection != NOSELECTION) {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == 36) {
                isMenuUp = isMenuUp ? false : true;
            }
        }
    }
}

void Menu::Draw(sf::RenderWindow &window) {
    if(isMenuUp) {
        window.draw(background);
        title.Draw(window);
        window.draw(topButton);
        window.draw(bottomButton);
        top.Draw(window);
        bottom.Draw(window);
    }
}