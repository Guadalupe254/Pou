#pragma once
#include <SFML/Graphics.hpp>

class Food {
public:
    Food();
    void draw(sf::RenderWindow& window);
    void feed();
    bool estaSiendoArrastrada() const;
    void setArrastrando(bool arrastrando);
    bool contienePunto(float px, float py) const;
    void setPosicion(float x, float y);
    sf::Vector2f getPosicion() const;
    sf::FloatRect getBounds() const;
    void dibujar(sf::RenderWindow& window);
    void cambiarAAssetHuevo();
    void cambiarAAssetPollo();
    void reiniciarAsset(); // Nuevo método para reiniciar la secuencia de comida
    std::string getAssetActual() const { return assetActual; } // Nuevo método para obtener el asset actual
    // Otros métodos
private:
    sf::Sprite sprite;
    sf::Texture textura;
    float x = 30, y = 440;
    bool arrastrando = false;
    std::string assetActual = "filete"; // Nuevo atributo para rastrear el asset actual
};
