#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../include/Game.hpp"

void mostrarMenuSFML(sf::RenderWindow &window, sf::Font &font, char &opcion) {
    sf::Vector2u winSize = window.getSize();
    window.clear(sf::Color(220, 240, 255));
    // Fondo del menú principal con Menu_Principal.png (abarca 1024x1024 y centrado)
    sf::Texture menuPrincipalTexture;
    if (menuPrincipalTexture.loadFromFile("assets/image/Menu_Principal.png")) {
        sf::Sprite menuPrincipalSprite(menuPrincipalTexture);
        float scaleX = static_cast<float>(winSize.x) / 1024.f;
        float scaleY = static_cast<float>(winSize.y) / 1024.f;
        menuPrincipalSprite.setScale(scaleX, scaleY);
        menuPrincipalSprite.setPosition(0, 0);
        window.draw(menuPrincipalSprite);
    }

    // Dibuja el menú principal (capa superior)
    // Centrar título y dimensionar
    sf::Text titulo(L"Menú principal de Oso Polar", font, std::min(winSize.x, winSize.y) / 18);
    titulo.setFillColor(sf::Color(30, 30, 60));
    sf::FloatRect tBounds = titulo.getLocalBounds();
    titulo.setOrigin(tBounds.left + tBounds.width / 2.0f, tBounds.top + tBounds.height / 2.0f);
    titulo.setPosition(winSize.x / 2, winSize.y / 8);
    window.draw(titulo);

    // Opciones dimensionadas y centradas
    std::vector<std::wstring> opcionesTxt = {L"X. Empezar juego", L"Y. Información", L"Z. Cerrar aplicación"};
    int fontSize = std::min(winSize.x, winSize.y) / 22;
    int menuW = winSize.x / 3;
    int menuH = fontSize * 2;
    int startY = winSize.y / 3;
    int stepY = menuH + winSize.y / 30;
    for (int i = 0; i < 3; ++i) {
        int boxX = winSize.x / 2 - menuW / 2;
        int boxY = startY + i * stepY;
        // Fondo rectangular simulando redondeo con outline más grueso y color suave
        sf::RectangleShape caja(sf::Vector2f(menuW, menuH));
        caja.setPosition(boxX, boxY);
        caja.setFillColor(sf::Color(255, 255, 255, 220));
        caja.setOutlineColor(sf::Color(120, 180, 220, 180));
        caja.setOutlineThickness(menuH * 0.18f); // Outline grueso para simular suavidad
        window.draw(caja);
        // Rectángulo interior para dar efecto de borde más suave
        sf::RectangleShape inner(sf::Vector2f(menuW - menuH * 0.18f, menuH - menuH * 0.18f));
        inner.setPosition(boxX + menuH * 0.09f, boxY + menuH * 0.09f);
        inner.setFillColor(sf::Color(255, 255, 255, 240));
        inner.setOutlineThickness(0);
        window.draw(inner);
        // Texto centrado en la caja y ajustado para no salirse
        sf::Text txt(opcionesTxt[i], font, fontSize);
        txt.setFillColor(sf::Color(40, 80, 120));
        sf::FloatRect oBounds = txt.getLocalBounds();
        float maxTextWidth = menuW - menuH * 0.25f;
        float scale = 1.0f;
        if (oBounds.width > maxTextWidth) {
            scale = maxTextWidth / oBounds.width;
            txt.setScale(scale, scale);
        }
        txt.setOrigin(oBounds.left + oBounds.width / 2.0f, oBounds.top + oBounds.height / 2.0f);
        txt.setPosition(boxX + menuW / 2, boxY + menuH / 2);
        window.draw(txt);
    }

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
    sf::Vector2u winSize = window.getSize();
    window.clear(sf::Color(220, 240, 255));
    sf::Text titulo(L"¿En qué año naciste?", font, std::min(winSize.x, winSize.y) / 24);
    titulo.setFillColor(sf::Color(30, 30, 60));
    sf::FloatRect bounds = titulo.getLocalBounds();
    titulo.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
    titulo.setPosition(winSize.x / 2, winSize.y / 10);

    std::vector<int> fechas = {2000, 2005, 2010, 2015, 2020};
    int seleccion = 0;
    bool menuAbierto = false;
    bool elegido = false;
    int menuW = std::min(winSize.x, winSize.y) / 4;
    int menuH = std::min(winSize.x, winSize.y) / 16;
    int menuX = winSize.x / 2 - menuW / 2;
    int menuY = winSize.y / 3;
    int maxMenuHeight = winSize.y - menuY - 40; // margen inferior
    int visibleOptions = std::min((int)fechas.size(), maxMenuHeight / menuH);

    while (!elegido && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
            if (event.type == sf::Event::KeyPressed) {
                if (!menuAbierto && (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::S)) {
                    menuAbierto = true;
                } else if (menuAbierto) {
                    if ((event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) && seleccion > 0) seleccion--;
                    if ((event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) && seleccion < (int)fechas.size() - 1) seleccion++;
                    if (event.key.code == sf::Keyboard::Enter) {
                        fechaNacimiento = fechas[seleccion];
                        elegido = true;
                    }
                    if (event.key.code == sf::Keyboard::Escape) {
                        menuAbierto = false;
                    }
                }
            }
        }
        window.clear(sf::Color(220, 240, 255));
        window.draw(titulo);

        // Caja principal del menú centrada y dimensionada
        sf::RectangleShape caja(sf::Vector2f(menuW, menuH));
        caja.setPosition(menuX, menuY);
        caja.setFillColor(sf::Color(255, 255, 255, 230));
        caja.setOutlineColor(sf::Color(40, 80, 120));
        caja.setOutlineThickness(3);
        window.draw(caja);

        // Texto de la opción seleccionada centrado
        sf::Text seleccionTxt(std::to_wstring(fechas[seleccion]), font, menuH * 0.6f);
        sf::FloatRect selBounds = seleccionTxt.getLocalBounds();
        seleccionTxt.setOrigin(selBounds.left + selBounds.width / 2.0f, selBounds.top + selBounds.height / 2.0f);
        seleccionTxt.setPosition(menuX + menuW / 2, menuY + menuH / 2);
        seleccionTxt.setFillColor(sf::Color(40, 80, 120));
        window.draw(seleccionTxt);

        // Flecha de despliegue centrada
        sf::ConvexShape flecha;
        flecha.setPointCount(3);
        flecha.setPoint(0, sf::Vector2f(menuX + menuW - menuH / 2, menuY + menuH / 2 - menuH / 6));
        flecha.setPoint(1, sf::Vector2f(menuX + menuW - menuH / 6, menuY + menuH / 2 - menuH / 6));
        flecha.setPoint(2, sf::Vector2f(menuX + menuW - menuH / 3, menuY + menuH / 2 + menuH / 4));
        flecha.setFillColor(sf::Color(40, 80, 120));
        window.draw(flecha);

        // Si el menú está abierto, mostrar las opciones centradas y dimensionadas
        if (menuAbierto) {
            int desplegableH = menuH * visibleOptions;
            float pill = menuH * 0.45f;
            // Fondo del menú desplegable con efecto pill
            sf::RectangleShape fondo(sf::Vector2f(menuW - pill, desplegableH));
            fondo.setPosition(menuX + pill/2, menuY + menuH);
            fondo.setFillColor(sf::Color(245, 245, 245, 245));
            fondo.setOutlineColor(sf::Color(40, 80, 120));
            fondo.setOutlineThickness(2);
            window.draw(fondo);
            // Opciones centradas y dimensionadas con efecto pill
            for (size_t i = 0; i < fechas.size(); ++i) {
                if ((int)i < visibleOptions) {
                    sf::RectangleShape fondoOpcion(sf::Vector2f(menuW - pill, menuH));
                    fondoOpcion.setPosition(menuX + pill/2, menuY + menuH + menuH * (int)i);
                    if ((int)i == seleccion) {
                        fondoOpcion.setFillColor(sf::Color(210, 230, 255, 255));
                        fondoOpcion.setOutlineColor(sf::Color(200, 60, 60));
                    } else {
                        fondoOpcion.setFillColor(sf::Color(245, 245, 245, 230));
                        fondoOpcion.setOutlineColor(sf::Color(40, 80, 120));
                    }
                    fondoOpcion.setOutlineThickness(3);
                    window.draw(fondoOpcion);
                    // Texto ajustado
                    sf::Text opcion(std::to_wstring(fechas[i]), font, menuH * 0.55f);
                    sf::FloatRect oBounds = opcion.getLocalBounds();
                    float maxTextWidth = menuW - menuH * 0.25f;
                    float scale = 1.0f;
                    if (oBounds.width > maxTextWidth) {
                        scale = maxTextWidth / oBounds.width;
                        opcion.setScale(scale, scale);
                    }
                    opcion.setOrigin(oBounds.left + oBounds.width / 2.0f, oBounds.top + oBounds.height / 2.0f);
                    opcion.setPosition(menuX + menuW / 2, menuY + menuH + menuH / 2 + menuH * (int)i);
                    opcion.setFillColor((int)i == seleccion ? sf::Color(200, 60, 60) : sf::Color(40, 80, 120));
                    window.draw(opcion);
                }
            }
        }
        window.display();
    }
}

int obtenerEdad(int fechaNacimiento) {
    const int ANIO_ACTUAL = 2025;
    return ANIO_ACTUAL - fechaNacimiento;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pou_Polar");
    sf::Font font;
    font.loadFromFile("assets/fonts/joystix monospace.otf");
    int fechaNacimiento = 0;
    mostrarFechaNacimiento(window, font, fechaNacimiento);
    if (!window.isOpen() || fechaNacimiento == 0) return 0;
    int edad = obtenerEdad(fechaNacimiento);
    if (edad < 6) {
        sf::Text advertencia(L"Debes tener al menos 6 años\npara jugar.", font, 32);
        advertencia.setFillColor(sf::Color(200, 60, 60));
        advertencia.setPosition(200, 300);
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
        // Pantalla de instrucciones antes de iniciar el juego
        bool mostrarInstrucciones = true;
        while (mostrarInstrucciones && window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return 0;
                }
                if (event.type == sf::Event::KeyPressed) {
                    mostrarInstrucciones = false;
                }
            }
            window.clear(sf::Color(220, 240, 255));
            sf::Vector2u winSize = window.getSize();
            sf::Text titulo(L"Instrucciones", font, std::min(winSize.x, winSize.y) / 22);
            titulo.setFillColor(sf::Color(30, 30, 60));
            sf::FloatRect tBounds = titulo.getLocalBounds();
            titulo.setOrigin(tBounds.left + tBounds.width / 2.0f, tBounds.top + tBounds.height / 2.0f);
            titulo.setPosition(winSize.x / 2, winSize.y / 8);
            window.draw(titulo);
            sf::Text instrucciones(L"- Usa WASD o flechas para navegar los menús\n- Selecciona con Enter\n- Cuida a tu oso polar: aliméntalo, juega y mantenlo feliz\n- Presiona cualquier tecla para continuar", font, std::min(winSize.x, winSize.y) / 32);
            instrucciones.setFillColor(sf::Color(40, 80, 120));
            sf::FloatRect iBounds = instrucciones.getLocalBounds();
            instrucciones.setOrigin(iBounds.left + iBounds.width / 2.0f, iBounds.top);
            instrucciones.setPosition(winSize.x / 2, winSize.y / 4);
            window.draw(instrucciones);
            window.display();
        }
        window.close();
        Game game;
        game.run();
    } else if (opcion == 'Y') {
        window.close();
        sf::RenderWindow infoWindow(sf::VideoMode(600, 400), "Información");
        sf::Font infoFont;
        infoFont.loadFromFile("assets/fonts/joystix monospace.otf");
        while (infoWindow.isOpen()) {
            sf::Event event;
            while (infoWindow.pollEvent(event)) {
                if (event.type == sf::Event::Closed ||
                    (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                    infoWindow.close();
                }
            }
            infoWindow.clear(sf::Color(240, 248, 255));
            sf::Text infoText(L"Cuida a tu oso polar virtual.\n\n- Aliméntalo\n- Juega con él\n- Manténlo feliz y saludable\n\nPresiona ESC para volver", infoFont, 26);
            infoText.setFillColor(sf::Color(30, 30, 60));
            infoText.setPosition(60, 80);
            infoWindow.draw(infoText);
            infoWindow.display();
        }
    } else {
        window.close();
    }
    return 0;
}
