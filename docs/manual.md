# Manual de Usuario - Pou Polar

## Introducción
Bienvenidos a Polar!

Pou Polar es un juego interactivo donde cuidas a un oso polar virtual. Puedes alimentarlo, jugar con él y mantenerlo feliz. El juego cuenta con un menú de inicio, sistema de puntuación y controles intuitivos.

![alt text](image.png)

## Requisitos
Para dispositivo:
- Windows 10/11
- Teclado
- Tarjeta gráfica compatible con OpenGL
- Archivos de assets en la carpeta `assets/`:
  - `fondo.png` (fondo del juego)
  - `imagen.png` (oso polar)
  - `sonido_inicio.wav` (sonido de inicio)
  - Fuente: `joystix monospace.otf`

Para persona:
Edad: Aunque no hay una restricción de edad oficial, Pou es un juego apto para todas las edades, por lo que lo pueden jugar tanto niños como adultos. Es especialmente adecuado para jugadores jóvenes debido a su simplicidad y jugabilidad relajada.

Paciencia: El juego se basa en cuidar a un pequeño personaje llamado Pou, que necesita alimentación, limpieza y otras actividades. Si disfrutas de juegos relajantes y de "mascotas virtuales", este es el juego ideal. Se necesita un poco de paciencia para completar todas las tareas.

Tiempo para dedicarle: Aunque no es necesario jugar todo el tiempo, Pou requiere tiempo para interactuar con el personaje. Si eres alguien que disfruta de juegos que no tienen un "objetivo" específico, solo relajante y de cuidado continuo, este juego es perfecto.

Interacción constante: A diferencia de otros juegos de aventuras, Pou requiere que interactúes regularmente con el personaje para que se mantenga feliz y saludable. Así que, si te gusta ese tipo de interacción con los juegos, Pou será adecuado.

## Instalación y Ejecución
1. Descarga y descomprime el proyecto.
2. Asegúrate de tener todos los archivos en las carpetas correspondientes.
3. Compila el proyecto con el comando:
   ```
   mingw32-make
   ```
4. Ejecuta el juego:
   ```
   bin\Pou_Polar.exe
   ```

## Menú de Inicio
- Al iniciar el juego, verás el fondo y el título.
- Presiona **ENTER** para comenzar. Se reproducirá un sonido de inicio.

## Controles del Juego
- **WASD** o **Flechas**: Mover al oso polar.
- **ESPACIO**: Sumar puntos (simula una acción de juego).
- **ESC**: Salir del juego.

## Sistema de Puntuación
- La puntuación se muestra en la esquina superior izquierda.
- Cada vez que presionas **ESPACIO**, tu puntuación aumenta.

## Consejos
- Mantén el oso dentro de la ventana para evitar que desaparezca.
- Puedes personalizar los assets en la carpeta `assets/` para cambiar la apariencia del juego.

## Créditos
- Proyecto académico desarrollado con SFML.
- Assets y código por el equipo de desarrollo.

---
¡Disfruta cuidando a tu Pou Polar!
