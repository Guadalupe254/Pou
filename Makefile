# Makefile para compilar y ejecutar Pou_Polar con SFML en Windows

SRC=src/Pou_Polar.cpp
BIN=bin/Pou_Polar.exe
CXX=g++
CXXFLAGS=-std=c++11 -Wall
SFML_LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(SRC) $(SFML_LIBS)

run: all
	.\$(BIN)

clean:
	del /Q bin\*.exe 2>nul || true
