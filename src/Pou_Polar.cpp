#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

void mostrarMenuSFML(sf::RenderWindow &window, sf::Font &font, char &opcion) {
    window.clear(sf::Color(220, 240, 255));
    sf::Text titulo("Menu principal de Oso Polar", font, 30);
    titulo.setFillColor(sf::Color(30, 30, 60));
    titulo.setPosition(40, 25);

    sf::Text menuX("X. Empezar juego", font, 22);
    menuX.setFillColor(sf::Color(40, 80, 120));
    menuX.setPosition(70, 90);

    sf::Text menuY("Y. Informacion", font, 22);
    menuY.setFillColor(sf::Color(40, 80, 120));
    menuY.setPosition(70, 140);

    sf::Text menuZ("Z. Cerrar aplicacion", font, 22);
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

int obtenerEdad(int anioNacimiento) {
    const int ANIO_ACTUAL = 2025;
    return ANIO_ACTUAL - anioNacimiento;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(480, 320), "Pou_Polar");
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/CHERI___.TTF")) {
        return 1;
    }
    int anioNacimiento = 0;
    std::string input = "";
    bool edadValida = false;
    std::string opciones = "Selecciona un anio entre 1990 y 2025";
    while (!edadValida && window.isOpen()) {
        window.clear(sf::Color(240, 248, 255));
        sf::Text pregunta("Introduce tu anio de nacimiento:", font, 24);
        pregunta.setFillColor(sf::Color(60, 60, 120));
        pregunta.setPosition(40, 60);
        sf::Text rango(opciones, font, 18);
        rango.setFillColor(sf::Color(80, 80, 80));
        rango.setPosition(40, 100);
        sf::Text respuesta(input, font, 24);
        respuesta.setFillColor(sf::Color(0, 100, 200));
        respuesta.setPosition(40, 140);
        window.draw(pregunta);
        window.draw(rango);
        window.draw(respuesta);
        window.display();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return 0;
            }
            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode >= '0' && event.text.unicode <= '9' && input.size() < 4) {
                    input += static_cast<char>(event.text.unicode);
                }
                if (event.text.unicode == 8 && !input.empty()) { // Backspace
                    input.pop_back();
                }
                if (event.text.unicode == 13 && input.size() == 4) { // Enter
                    anioNacimiento = std::stoi(input);
                    if (anioNacimiento < 1990 || anioNacimiento > 2025) {
                        window.clear(sf::Color(240, 248, 255));
                        sf::Text msg("El anio debe estar entre 1990 y 2025", font, 20);
                        msg.setFillColor(sf::Color(200, 40, 40));
                        msg.setPosition(40, 180);
                        window.draw(pregunta);
                        window.draw(rango);
                        window.draw(msg);
                        window.display();
                        sf::sleep(sf::seconds(2));
                        input = "";
                    } else {
                        int edad = obtenerEdad(anioNacimiento);
                        if (edad < 18) {
                            window.clear(sf::Color(240, 248, 255));
                            sf::Text msg("Acceso solo para mayores de edad", font, 20);
                            msg.setFillColor(sf::Color(200, 40, 40));
                            msg.setPosition(40, 180);
                            window.draw(pregunta);
                            window.draw(rango);
                            window.draw(msg);
                            window.display();
                            sf::sleep(sf::seconds(2));
                            window.close();
                            return 0;
                        } else {
                            edadValida = true;
                        }
                    }
                }
            }
        }
    }
    char opcion = 0;
    do {
        mostrarMenuSFML(window, font, opcion);
        switch(opcion) {
            case 'X':
                window.clear(sf::Color(220, 240, 255));
                {
                    sf::Text msg("Tu aventura con el oso polar inicia!", font, 20);
                    msg.setFillColor(sf::Color(30, 30, 60));
                    msg.setPosition(40, 120);
                    window.draw(msg);
                    window.display();
                    sf::sleep(sf::seconds(2));
                }
                break;
            case 'Y':
                window.clear(sf::Color(220, 240, 255));
                {
                    sf::Text msg("Creado por Lupitaaaaaaaaa", font, 18);
                    msg.setFillColor(sf::Color(30, 30, 60));
                    msg.setPosition(40, 120);
                    window.draw(msg);
                    window.display();
                    sf::sleep(sf::seconds(2));
                }
                break;
            case 'Z':
                window.close();
                break;
            default:
                break;
        }
    } while(opcion != 'Z' && window.isOpen());
    return 0;
}
