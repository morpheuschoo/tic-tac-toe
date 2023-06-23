#ifndef GAME_H
#define GAME_H

#include "board.hpp"
#include "player.hpp"
#include "bot.hpp"
#include "drawing.hpp"
#include "menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game {
private:
    bool withBot;
    char currentPlayer;
    int position;
    bool moveMade;

    Board board;
    Player player;
    Bot bot;
    Drawing drawing;

    sf::SoundBuffer moveSoundBuffer;
    sf::Sound moveSound;

public:
    Game();

    void SetPlayer(Menu &menu, sf::Event &event);
    void RunGame(sf::Event &event);
    void Draw(sf::RenderWindow &window);

};

#endif