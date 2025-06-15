#pragma once
#include <SFML/Graphics.hpp>
#include "PolarBear.hpp"
#include "Menu.hpp"
#include "Food.hpp"
#include "Animation.hpp"

class Game {
public:
    Game();
    void run();
private:
    sf::RenderWindow window;
    PolarBear polarBear;
    Menu menu;
    Food food;
    Animation animation;
    // Otros atributos y métodos
};
