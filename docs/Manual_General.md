# Manual General - Pou Polar

## Introducción
Pou Polar es un juego de mascota virtual desarrollado en C++ con SFML, donde el usuario cuida, alimenta y juega con un oso polar. El proyecto está diseñado para ser educativo, entretenido y fácil de usar, con una estructura orientada a objetos y recursos gráficos originales.

---

## Estructura del Proyecto
- **src/**: Código fuente principal (C++).
- **include/**: Archivos de cabecera (.hpp).
- **assets/**: Recursos gráficos, sonidos y fuentes.
- **bin/**: Ejecutable generado.
- **docs/**: Manuales, diagramas y documentación.
- **Makefile**: Script para compilar el proyecto.

---

## Principales Clases y Responsabilidades
- **Juego (Game):** Controla el ciclo principal, inicialización y gestión de objetos.
- **OsoPolar (PolarBear):** Representa la mascota virtual, maneja sprites, estados y animaciones.
- **Pelota (Ball):** Objeto interactivo con física básica y arrastre.
- **Comida (Food):** Gestiona los tipos de comida, arrastre y colisión con el oso.
- **Menu:** Dibuja y gestiona el menú principal.

Consulta el diagrama de clases (`docs/diagrama_plantuml.puml`) para visualizar relaciones y métodos.

---

## Instalación y Ejecución
1. Descarga y descomprime el proyecto.
2. Verifica que todos los archivos estén en las carpetas correspondientes.
3. Compila el proyecto con:
   ```
   mingw32-make
   ```
4. Ejecuta el juego con:
   ```
   .\bin\Pou_Polar.exe
   ```

---

## Cómo Jugar
1. Al iniciar, el juego solicita tu año de nacimiento (debes tener al menos 6 años).
2. Navega el menú principal usando las teclas X (empezar juego), Y (información) o Z (cerrar aplicación).
3. Sigue las instrucciones en pantalla para interactuar con tu oso polar:
   - Usa WASD o flechas para moverte por los menús.
   - Arrastra la comida hasta el oso para alimentarlo.
   - Juega con la pelota arrastrándola o lanzándola con el mouse.
   - Observa cómo cambia el estado de ánimo del oso según tus acciones.

---

## Controles
- **WASD o Flechas:** Navegar por los menús.
- **Enter:** Seleccionar opción en menús.
- **Mouse:** Arrastrar comida y pelota.
- **ESC:** Salir del juego o cerrar ventanas de información.

---

## Consejos y Personalización
- Puedes personalizar los assets en la carpeta `assets/` para cambiar la apariencia del juego.
- Consulta el manual de usuario y el manual del programador para detalles específicos de uso y desarrollo.

---

## Créditos
- Proyecto académico desarrollado con SFML.
- Assets y código por el equipo de desarrollo.
- Inspirado en el clásico juego Pou.


¡Disfruta cuidando a tu Pou Polar y explora todas las posibilidades del código!
