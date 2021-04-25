#pragma once
#include <iostream>
#include <string>

#include <SDL.h>
#include "Texture.h"
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

	int numeroFrame;
	int contadorFrames;
	const int framesMovimiento = 2;

	int posicionXEnTextura;
	int posicionYEnTextura;

	Texture* texture;

public:
	//Constructores y destructores
	Pacman(Texture* _texture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//~Pacman();

	//Metodos accesores

	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	// Metodos varios

	// Manejador de eventos de pacman
	void handleEvent(SDL_Event& e);
	// Mover pacman
	void move();
	// Renderizar imagen pacman
	void render();

};

