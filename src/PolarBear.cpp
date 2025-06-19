#include "../include/PolarBear.hpp"

PolarBear::PolarBear() : x(370), y(480) {
    // Cargar textura del personaje principal
    if (!texture.loadFromFile("assets/image/AdolescentePolar_Serio.png")) {
        // Si falla, usar color de relleno
        texture.create(60, 60);
    }
    sprite.setTexture(texture);
    // Redimensionar el sprite a la mitad de su tamaño original
    sprite.setScale(0.5f, 0.5f);
    // Centrar horizontalmente y ubicar en la parte inferior
    sf::Vector2u texSize = texture.getSize();
    float ancho = texSize.x * 0.5f;
    float alto = texSize.y * 0.5f;
    x = 400 - ancho / 2; // ventana 800x600
    y = 600 - alto - 20; // 20px de margen inferior
    sprite.setPosition(x, y);
}

void PolarBear::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void PolarBear::move(float dx, float dy) {
    x += dx;
    y += dy;
    sprite.setPosition(x, y);
}

void PolarBear::setHappy(bool happy) {
    if (happy) {
        texture.loadFromFile("assets/image/AdolescentePolar_Feliz.png");
    } else {
        texture.loadFromFile("assets/image/AdolescentePolar_Serio.png");
    }
    sprite.setTexture(texture);
}
