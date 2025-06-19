#include "../include/Ball.hpp"

Ball::Ball() : x(400), y(500), vx(0), vy(0) {
    if (!texture.loadFromFile("assets/image/Pelota.png")) {
        texture.create(40, 40);
    }
    sprite.setTexture(texture);
    sprite.setScale(0.3f, 0.3f); // Más pequeña
    sprite.setPosition(x, y);
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Ball::move(float dx, float dy) {
    x += dx;
    y += dy;
    sprite.setPosition(x, y);
}

void Ball::setPosition(float nx, float ny) {
    x = nx;
    y = ny;
    sprite.setPosition(x, y);
}

sf::Vector2f Ball::getPosition() const {
    return sf::Vector2f(x, y);
}

void Ball::setVelocity(float nvx, float nvy) {
    vx = nvx;
    vy = nvy;
}

void Ball::update(const sf::RenderWindow& window, float dt) {
    x += vx * dt;
    y += vy * dt;
    // Rebote en bordes
    float radio = (texture.getSize().x * 0.3f) / 2.0f;
    if (x < 0) { x = 0; vx = -vx; }
    if (y < 0) { y = 0; vy = -vy; }
    if (x + radio * 2 > window.getSize().x) { x = window.getSize().x - radio * 2; vx = -vx; }
    if (y + radio * 2 > window.getSize().y) { y = window.getSize().y - radio * 2; vy = -vy; }
    // Frenado
    vx *= damping;
    vy *= damping;
    if (std::abs(vx) < 1) vx = 0;
    if (std::abs(vy) < 1) vy = 0;
    sprite.setPosition(x, y);
}
