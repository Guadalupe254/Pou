#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball();
    void draw(sf::RenderWindow& window);
    void move(float dx, float dy);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void update(const sf::RenderWindow& window, float dt);
    void setVelocity(float vx, float vy);
    float getRadius() const {
        return (texture.getSize().x * sprite.getScale().x) / 2.0f;
    }
private:
    sf::Sprite sprite;
    sf::Texture texture;
    float x, y;
    float vx = 0, vy = 0;
    float damping = 0.98f; // factor de frenado
};
