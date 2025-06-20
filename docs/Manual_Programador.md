# Manual del Programador - Pou Polar

## Introducción
Este manual está dirigido a programadores que deseen entender, modificar o ampliar el proyecto "Pou Polar". Aquí encontrarás la estructura del código, explicación de las clases principales, dependencias, flujo de ejecución y recomendaciones para desarrollo y mantenimiento.

## Estructura del proyecto
```
Pou_Polar/
├── assets/
│   ├── fonts/
│   ├── image/
│   └── sound/
├── bin/
├── docs/
├── include/
├── src/
├── Makefile
└── README.md
```
- **assets/**: Recursos gráficos, fuentes y sonidos.
- **bin/**: Ejecutable generado.
- **docs/**: Manuales y diagramas.
- **include/**: Archivos de cabecera (.hpp).
- **src/**: Código fuente principal (.cpp).
- **Makefile**: Script de compilación.


## Dependencias
- **SFML** (Simple and Fast Multimedia Library) para gráficos, ventanas y eventos.
- Compilador compatible con C++17 o superior.
- Windows 10/11.


## Clases principales
- `Game` (Juego): Controla el ciclo principal, inicialización y gestión de objetos.
- `PolarBear` (OsoPolar): Representa la mascota virtual, maneja sprites, estados y animaciones.
- `Ball` (Pelota): Objeto interactivo con física básica y arrastre.
- `Food` (Comida): Gestiona los tipos de comida, arrastre y colisión con el oso.
- `Menu`: Dibuja y gestiona el menú principal.

Consulta el diagrama de clases (`docs/diagrama_plantuml.puml`) para visualizar relaciones y métodos.


## Flujo de ejecución
1. **main.cpp / Pou_Polar.cpp**: Inicia la ventana, muestra el menú y valida la edad.
2. Si el usuario inicia el juego, se crea una instancia de `Game` y se llama a `run()`.
3. Dentro de `Game::run()`, se gestionan los eventos, actualizaciones y renderizado de objetos (`PolarBear`, `Ball`, `Food`).
4. El usuario puede interactuar con la comida y la pelota mediante el mouse.


## Compilación y ejecución
- Compila el proyecto con:
  mingw32-make
- Ejecuta el binario generado:
  .\bin\Pou_Polar.exe


## Recomendaciones para desarrollo
- Mantén la separación entre lógica de juego y presentación.
- Usa los archivos de cabecera para declarar interfaces y estructuras.
- Agrega nuevos assets en la carpeta correspondiente y actualiza las rutas en el código.
- Para nuevos mini-juegos o funcionalidades, crea nuevas clases en `/src` y `/include`.
- Documenta tus cambios y actualiza el diagrama de clases si modificas la estructura.


## Ampliaciones sugeridas
- Añadir más tipos de comida o animaciones.
- Implementar nuevos mini-juegos.
- Mejorar feedback visual/sonoro.
- Internacionalización (traducción de textos).


## Contacto y soporte
Para dudas técnicas, sugerencias o reportes de bugs, contacta al equipo de desarrollo o revisa la documentación en `/docs`.


¡Feliz programación y contribución a Pou Polar!
