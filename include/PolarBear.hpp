#pragma once
#include <SFML/Graphics.hpp>

class PolarBear {
public:
    PolarBear();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    void setHappy(bool happy);
    sf::Vector2f getPosicion() const;
    sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
    // Otros métodos relevantes
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float x, y;
};
