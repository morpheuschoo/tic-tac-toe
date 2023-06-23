#include "fpscounter.hpp"

FpsCounter::FpsCounter() : fpsText("pricedown.otf", 30, sf::Color::Black) {}

void FpsCounter::Update() {
    currentTime = clock.restart().asSeconds();

    std::string currentFps = std::to_string(static_cast<int>(1.0f / currentTime));
    fpsText.Update(currentFps, sf::Vector2f(30.0f, 20.0f));
}

void FpsCounter::Draw(sf::RenderWindow &window) {
    fpsText.Draw(window);
}