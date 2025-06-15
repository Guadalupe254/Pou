#include "../include/Game.hpp"

Game::Game() : window(sf::VideoMode(480, 320), "Pou_Polar") {}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        polarBear.draw(window);
        window.display();
    }
}
