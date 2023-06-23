#include "fpscounter.hpp"
#include "game.hpp"
#include "menu.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);

    FpsCounter fps;
    Game game;
    Menu menu;

    window.setFramerateLimit(60);
    while(window.isOpen()) {
        sf::Event event;

        fps.Update();

        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }

            menu.ShowMenu(event);

            if(menu.isMenuUp)
                game.SetPlayer(menu, event);
            else 
                game.RunGame(event);
        }

        window.clear(sf::Color(99, 102, 106));
        
        game.Draw(window);
        menu.Draw(window);
        fps.Draw(window);
        
        window.display();
    }

    return 0;
}