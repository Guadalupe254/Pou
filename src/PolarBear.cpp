#include "../include/PolarBear.hpp"

PolarBear::PolarBear() : x(0), y(0) {
    // No cargar textura ni assets
}

void PolarBear::draw(sf::RenderWindow& window) {
    // Dibujar un rectángulo simple como placeholder
    sf::RectangleShape bear(sf::Vector2f(60, 60));
    bear.setFillColor(sf::Color(200, 240, 255));
    bear.setPosition(x, y);
    window.draw(bear);
}

void PolarBear::move(float dx, float dy) {
    x += dx;
    y += dy;
}
