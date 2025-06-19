#include <iostream>
#include "../include/Game.hpp"
#include "../include/Ball.hpp"
#include <cmath>

Game::Game() : window(sf::VideoMode(800, 600), "Pou_Polar") {}

void Game::run() {
    // Cargar fondo de habitación
    sf::Texture habitacionTexture;
    if (!habitacionTexture.loadFromFile("assets/image/HabitacionPolar.png")) {
        std::cerr << "No se pudo cargar HabitacionPolar.png" << std::endl;
        return;
    }
    // Adaptar la textura al tamaño de la ventana
    sf::Sprite habitacion(habitacionTexture);
    sf::Vector2u texSize = habitacionTexture.getSize();
    sf::Vector2u winSize = window.getSize();
    float scaleX = static_cast<float>(winSize.x) / texSize.x;
    float scaleY = static_cast<float>(winSize.y) / texSize.y;
    habitacion.setScale(scaleX, scaleY);

    // Fuente para texto
    sf::Font font;
    font.loadFromFile("assets/fonts/joystix monospace.otf");

    // Estado del juego
    bool enPantallaInicio = true;
    bool jugando = false;

    Ball ball;
    sf::Clock clock;
    bool dragging = false;
    sf::Vector2f dragOffset;
    bool polarFeliz = false;
    float tiempoFeliz = 0;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds() * 60.0f; // normalizar a 60fps
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (enPantallaInicio && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                enPantallaInicio = false;
                jugando = true;
            }
            // Arrastrar con el mouse
            if (jugando && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::Vector2f ballPos = ball.getPosition();
                float radio = ball.getRadius();
                float dist = std::sqrt(std::pow(mousePos.x - (ballPos.x + radio), 2) + std::pow(mousePos.y - (ballPos.y + radio), 2));
                if (dist < radio) {
                    dragging = true;
                    dragOffset = mousePos - ballPos;
                    ball.setVelocity(0, 0);
                    polarBear.setHappy(true);
                    polarFeliz = true;
                    tiempoFeliz = 120; // 2 segundos a 60fps
                }
            }
            if (jugando && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && dragging) {
                dragging = false;
                // Calcular velocidad inicial según el arrastre
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                sf::Vector2f ballPos = ball.getPosition();
                sf::Vector2f vel = (mousePos - ballPos) * 0.3f;
                ball.setVelocity(vel.x, vel.y);
                polarBear.setHappy(true);
                polarFeliz = true;
                tiempoFeliz = 120; // 2 segundos a 60fps
            }
        }
        if (jugando && dragging) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            ball.setPosition(mousePos.x - dragOffset.x, mousePos.y - dragOffset.y);
        }
        if (polarFeliz) {
            tiempoFeliz--;
            if (tiempoFeliz <= 0) {
                polarBear.setHappy(false);
                polarFeliz = false;
            }
        }
        window.clear();
        if (enPantallaInicio) {
            window.draw(habitacion);
            sf::Text titulo("Pou Polar", font, 48);
            titulo.setFillColor(sf::Color(30, 30, 60));
            titulo.setPosition(220, 100);
            window.draw(titulo);
            sf::Text boton("Presiona ENTER para comenzar", font, 28);
            boton.setFillColor(sf::Color(40, 80, 120));
            boton.setPosition(140, 400);
            window.draw(boton);
        } else if (jugando) {
            window.draw(habitacion);
            polarBear.draw(window);
            ball.update(window, dt);
            ball.draw(window);
            // Aquí irá la lógica de juego
        }
        window.display();
    }
}
