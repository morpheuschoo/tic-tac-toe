#include "drawing.hpp"

Drawing::Drawing(const Board &_board) 
    : board(_board),
      title("luckiestguy.ttf", 100, sf::Color::Black),
      endText("pricedown.otf", 240, sf::Color::Red, sf::Color::Black, 7.0f),
      endSubtext("pricedown.otf", 30, sf::Color::Red, sf::Color::Black, 5.0f) {}

void Drawing::RenderObjects() {
    boardTexture.loadFromFile("assets/textures/board.png");
    playerTexture.loadFromFile("assets/textures/players.png");

    boardSprite.setTexture(boardTexture);
    playerSprite.setTexture(playerTexture);

    boardSprite.setPosition(sf::Vector2f(100.0f, 150.0f));

    uvRect.top = 0;
    uvRect.width = playerTexture.getSize().x / 2;
    uvRect.height = playerTexture.getSize().y;

    playerSprite.setOrigin((float)uvRect.width / 2, (float)uvRect.height / 2);

    title.Update("TIC-TAC-TOE", sf::Vector2f(400.0f, 50.0f));
    endSubtext.Update("press any key to continue", sf::Vector2f(400.0f, 480.0f));
}

void Drawing::Draw(sf::RenderWindow &window) {
    char winner;
    char value;
    sf::Vector2f posOnBoard;

    title.Draw(window);
    window.draw(boardSprite);

    for(int i = 0; i != 9; i++) {
        value = board.GetPosition(i);
        
        if(value == 'O' || value == 'X') {
            if(value == 'O')
                uvRect.left = 0;
            else 
                uvRect.left = uvRect.width;
            
            playerSprite.setTextureRect(uvRect);

            posOnBoard.x = 200 + 200 * (i % 3);
            posOnBoard.y = 250 + 200 * static_cast<int>(i / 3);

            playerSprite.setPosition(posOnBoard);

            window.draw(playerSprite);
        }
    }

    winner = board.GetWinner();

    if(winner != Board::NOWINNER) {
        if(winner == 'X') 
            endText.Update("X WINS!", sf::Vector2f(400.0f, 300.0f));
        else if(winner == 'O')
            endText.Update("O WINS!", sf::Vector2f(400.0f, 300.0f));
        else
            endText.Update("TIE!", sf::Vector2f(400.0f, 300.0f));
        
        endText.Draw(window);
        endSubtext.Draw(window);
    }
}