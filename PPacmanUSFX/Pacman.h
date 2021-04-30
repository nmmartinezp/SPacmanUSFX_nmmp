
//CLASE HIJA DE COMMONGAMEPROPERTIES
#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "CommonGameProperties.h"

using namespace std;

class Pacman : public CommonGameProperties
{
private:
	// Velocidad en eje X
	int velocidadX;
	// Velocidad en el eje Y
	int velocidadY;
	// Velocidad a la que mueve el fantasma en cualquier eje
	int velocidadPatron;
public:
	//Constructores y destructores
	Pacman(Texture* _pacmanTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//Metodos accesores
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	
	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);
	// Mover pacman
	void move();
};

