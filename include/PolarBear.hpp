#pragma once
#include <SFML/Graphics.hpp>

class PolarBear {
public:
    PolarBear();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    void setHappy(bool happy);
    // Otros métodos relevantes
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float x, y;
};
