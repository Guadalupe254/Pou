#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>

int main() {
    // Ventana principal
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pou_Polar - Demo Assets");

    // Cargar fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("assets/fondo.png")) return 1;
    sf::Sprite fondo(fondoTexture);

    // Cargar personaje
    sf::Texture personajeTexture;
    if (!personajeTexture.loadFromFile("assets/imagen.png")) return 1;
    sf::Sprite personaje(personajeTexture);
    personaje.setPosition(350, 350);

    // Cargar sonido de inicio
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/sonido_inicio.wav")) return 1;
    sf::Sound sonidoInicio(buffer);

    // Fuente para texto
    sf::Font font;
    font.loadFromFile("assets/fonts/joystix monospace.otf");

    // Menú de inicio
    bool enMenu = true;
    bool juegoIniciado = false;
    int puntuacion = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (enMenu && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                sonidoInicio.play();
                enMenu = false;
                juegoIniciado = true;
            }
        }
        window.clear();
        if (enMenu) {
            window.draw(fondo);
            sf::Text titulo("Pou Polar", font, 48);
            titulo.setFillColor(sf::Color(30, 30, 60));
            titulo.setPosition(220, 100);
            window.draw(titulo);
            sf::Text boton("Presiona ENTER para iniciar", font, 28);
            boton.setFillColor(sf::Color(40, 80, 120));
            boton.setPosition(180, 400);
            window.draw(boton);
        } else if (juegoIniciado) {
            window.draw(fondo);
            window.draw(personaje);
            // Movimiento básico con WASD
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) personaje.move(-3, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) personaje.move(3, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) personaje.move(0, -3);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) personaje.move(0, 3);
            // Sumar puntos con espacio
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) puntuacion++;
            // Mostrar puntuación
            sf::Text puntos("Puntos: " + std::to_string(puntuacion), font, 28);
            puntos.setFillColor(sf::Color(200, 60, 60));
            puntos.setPosition(20, 20);
            window.draw(puntos);
        }
        window.display();
    }
    return 0;
}
