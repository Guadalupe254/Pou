#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../include/Game.hpp"

void mostrarMenuSFML(sf::RenderWindow &window, sf::Font &font, char &opcion) {
    window.clear(sf::Color(220, 240, 255));
    sf::Text titulo(u8"Menu principal de Oso Polar", font, 30);
    titulo.setFillColor(sf::Color(30, 30, 60));
    titulo.setPosition(40, 25);

    sf::Text menuX(u8"X. Empezar juego", font, 22);
    menuX.setFillColor(sf::Color(40, 80, 120));
    menuX.setPosition(70, 90);

    sf::Text menuY(u8"Y. Información", font, 22);
    menuY.setFillColor(sf::Color(40, 80, 120));
    menuY.setPosition(70, 140);

    sf::Text menuZ(u8"Z. Cerrar aplicación", font, 22);
    menuZ.setFillColor(sf::Color(40, 80, 120));
    menuZ.setPosition(70, 190);

    window.draw(titulo);
    window.draw(menuX);
    window.draw(menuY);
    window.draw(menuZ);
    window.display();

    bool seleccion = false;
    while (!seleccion && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                opcion = 'Z';
                seleccion = true;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::X) { opcion = 'X'; seleccion = true; }
                if (event.key.code == sf::Keyboard::Y) { opcion = 'Y'; seleccion = true; }
                if (event.key.code == sf::Keyboard::Z) { opcion = 'Z'; seleccion = true; }
            }
        }
    }
}

void mostrarFechaNacimiento(sf::RenderWindow &window, sf::Font &font, int &fechaNacimiento) {
    window.clear(sf::Color(220, 240, 255));
    sf::Text titulo(u8"¿En qué año naciste?", font, 28);
    titulo.setFillColor(sf::Color(30, 30, 60));
    titulo.setPosition(60, 40);

    std::vector<int> fechas = {2000, 2005, 2010, 2015, 2020};
    std::vector<sf::Text> opciones;
    std::vector<sf::RectangleShape> fondos;
    for (size_t i = 0; i < fechas.size(); ++i) {
        sf::Text opcion(std::to_string(fechas[i]), font, 22);
        opcion.setFillColor(sf::Color(40, 80, 120));
        opcion.setPosition(200, 100 + 40 * i);
        opciones.push_back(opcion);
        // Fondo redondeado para cada opción
        sf::RectangleShape fondo(sf::Vector2f(80, 32));
        fondo.setPosition(190, 95 + 40 * i);
        fondo.setFillColor(sf::Color(255, 255, 255, 180));
        fondo.setOutlineColor(sf::Color(40, 80, 120));
        fondo.setOutlineThickness(2);
        fondos.push_back(fondo);
    }
    int seleccion = 0;
    bool elegido = false;
    while (!elegido && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up && seleccion > 0) seleccion--;
                if (event.key.code == sf::Keyboard::Down && seleccion < (int)fechas.size() - 1) seleccion++;
                if (event.key.code == sf::Keyboard::Enter) {
                    fechaNacimiento = fechas[seleccion];
                    elegido = true;
                }
            }
        }
        window.clear(sf::Color(220, 240, 255));
        window.draw(titulo);
        for (size_t i = 0; i < opciones.size(); ++i) {
            // Fondo con efecto de selección y "redondeo" visual
            if ((int)i == seleccion) {
                fondos[i].setFillColor(sf::Color(200, 60, 60, 220));
                fondos[i].setOutlineColor(sf::Color(120, 30, 30));
            } else {
                fondos[i].setFillColor(sf::Color(255, 255, 255, 180));
                fondos[i].setOutlineColor(sf::Color(40, 80, 120));
            }
            // Simulación de esquinas redondeadas (no nativo en SFML)
            window.draw(fondos[i]);
            // Opcional: dibujar "círculos" en las esquinas para simular más redondeo
            sf::CircleShape esquina(16);
            esquina.setFillColor(fondos[i].getFillColor());
            esquina.setOutlineColor(fondos[i].getOutlineColor());
            esquina.setOutlineThickness(2);
            esquina.setPointCount(30);
            esquina.setPosition(fondos[i].getPosition().x - 8, fondos[i].getPosition().y - 8);
            window.draw(esquina);
            esquina.setPosition(fondos[i].getPosition().x + 72, fondos[i].getPosition().y - 8);
            window.draw(esquina);
            esquina.setPosition(fondos[i].getPosition().x - 8, fondos[i].getPosition().y + 16);
            window.draw(esquina);
            esquina.setPosition(fondos[i].getPosition().x + 72, fondos[i].getPosition().y + 16);
            window.draw(esquina);
            // Texto
            window.draw(opciones[i]);
        }
        window.display();
    }
}

int obtenerEdad(int fechaNacimiento) {
    const int ANIO_ACTUAL = 2025;
    return ANIO_ACTUAL - fechaNacimiento;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(480, 320), "Pou_Polar");
    sf::Font font;
    font.loadFromFile("assets/fonts/Pixeled.ttf");
    int fechaNacimiento = 0;
    mostrarFechaNacimiento(window, font, fechaNacimiento);
    if (!window.isOpen() || fechaNacimiento == 0) return 0;
    int edad = obtenerEdad(fechaNacimiento);
    if (edad < 6) {
        sf::Text advertencia(u8"Debes tener al menos 6 años\npara jugar.", font, 22);
        advertencia.setFillColor(sf::Color(200, 60, 60));
        advertencia.setPosition(60, 120);
        window.clear(sf::Color(220, 240, 255));
        window.draw(advertencia);
        window.display();
        sf::sleep(sf::seconds(2));
        window.close();
        return 0;
    }
    // Aquí puedes mostrar el menú o iniciar el juego
    char opcion = 0;
    mostrarMenuSFML(window, font, opcion);
    if (opcion == 'X') {
        window.close();
        Game game;
        game.run();
    } else if (opcion == 'Y') {
        window.close();
        sf::RenderWindow infoWindow(sf::VideoMode(400, 220), "Informacion");
        sf::Font infoFont;
        infoFont.loadFromFile("assets/fonts/Pixeled.ttf");
        while (infoWindow.isOpen()) {
            sf::Event event;
            while (infoWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                    infoWindow.close();
                }
            }
            infoWindow.clear(sf::Color(240, 248, 255));
            sf::Text infoText(u8"Cuida a tu oso polar virtual.\n\n- Aliméntalo\n- Juega con él\n- Manténlo feliz y saludable\n\nPresiona ESC para volver", infoFont, 18);
            infoText.setFillColor(sf::Color(30, 30, 60));
            infoText.setPosition(20, 30);
            infoWindow.draw(infoText);
            infoWindow.display();
        }
    } else {
        window.close();
    }
    return 0;
}
