#pragma once
#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    void draw(sf::RenderWindow& window);
    int handleEvent(sf::Event event);
    // Otros métodos
};
