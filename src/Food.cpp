#include "../include/Food.hpp"

Food::Food() {
    x = 30;
    y = 440; // 600 - 60
    assetActual = "filete";
    if (!textura.loadFromFile("assets/image/Filete.png")) {
        textura.create(40, 40);
    }
    sprite.setTexture(textura);
    sprite.setScale(0.4f, 0.4f);
    sprite.setPosition(x, y);
}

void Food::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Food::feed() {
    // Lógica para alimentar (placeholder)
}

bool Food::estaSiendoArrastrada() const {
    return arrastrando;
}

void Food::setArrastrando(bool arr) {
    arrastrando = arr;
}

bool Food::contienePunto(float px, float py) const {
    return sprite.getGlobalBounds().contains(px, py);
}

void Food::setPosicion(float nx, float ny) {
    x = nx;
    y = ny;
    sprite.setPosition(x, y);
}

sf::Vector2f Food::getPosicion() const {
    return sf::Vector2f(x, y);
}

sf::FloatRect Food::getBounds() const {
    return sprite.getGlobalBounds();
}

void Food::dibujar(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Food::cambiarAAssetHuevo() {
    textura.loadFromFile("assets/image/Huevo.png");
    sprite.setTexture(textura);
    assetActual = "huevo";
}

void Food::cambiarAAssetPollo() {
    textura.loadFromFile("assets/image/Pollo.png");
    sprite.setTexture(textura);
    assetActual = "pollo";
}

void Food::reiniciarAsset() {
    textura.loadFromFile("assets/image/Filete.png");
    sprite.setTexture(textura);
    assetActual = "filete";
}
