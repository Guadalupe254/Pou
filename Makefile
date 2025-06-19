# Makefile para compilar y ejecutar Pou_Polar con SFML en Windows

# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin

SFML := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lbox2d

# Archivos fuente principales
POU_SRC := $(SRC_DIR)/Pou_Polar.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/PolarBear.cpp $(SRC_DIR)/Menu.cpp $(SRC_DIR)/Food.cpp $(SRC_DIR)/Animation.cpp $(SRC_DIR)/Ball.cpp
POU_EXE := $(BIN_DIR)/Pou_Polar.exe

# Regla para compilar el ejecutable principal enlazando todos los .cpp
$(POU_EXE): $(POU_SRC)
	g++ $(POU_SRC) -o $(POU_EXE) $(SFML) -Iinclude

# Regla por defecto
all: $(POU_EXE)

# Ejecutar el juego principal
run: $(POU_EXE)
	./$(POU_EXE)

# Limpiar ejecutables
clean:
	del /Q $(BIN_DIR)\*.exe 2>nul || true

.PHONY: all clean run
