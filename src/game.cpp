#include "game.hpp"

Game::Game() : drawing(board) {
    moveMade = false;
    drawing.RenderObjects();
    moveSoundBuffer.loadFromFile("assets/audio/zipclick.flac");
    moveSound.setBuffer(moveSoundBuffer);
}

void Game::SetPlayer(Menu &menu, sf::Event &event) {
    if(menu.ObtainSelection(event)) {
        if(menu.selection == Menu::NOSELECTION)
            return;
        else if(menu.selection == 1)
            withBot = true;
        else
            withBot = false;

        if(withBot) {
            player.SetPlayer('X');
            bot.SetBot('X');
        }
        else {
            player.SetPlayer('X');
            bot.SetBot(Bot::NOPLAYER);
        }

        board.ResetBoard();
        player.ResetPlayer();
        bot.ResetBot();
    }  
}

void Game::RunGame(sf::Event &event) {
    if(board.GetWinner() == Board::NOWINNER) {
        currentPlayer = player.GetCurrentPlayer();

        if(!withBot || (withBot && currentPlayer == 'O')) {
            if(event.type == sf::Event::MouseButtonPressed) {
                position = player.ObtainPosition(event);
                moveMade = true;
            }
        }

        else {
            position = bot.ReturnMove(board);
            moveMade = true;
        }

        if(moveMade && board.LegalMove(position)) {
            board.Move(position, currentPlayer);
            moveSound.play();
            player.Switch();
            board.CheckAndSetWinner();
            moveMade = false;
        }
    }

    else {
        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code != 36) {
                board.ResetBoard();
                player.ResetPlayer();
                bot.ResetBot();
            } 
        }
    } 
}

void Game::Draw(sf::RenderWindow &window) {
    drawing.Draw(window);
}