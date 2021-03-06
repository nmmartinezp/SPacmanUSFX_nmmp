
//CLASE HIJA DE COMMONGAMEPROPERTIES
#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include "CommonGameProperties.h"

class Fantasma : public CommonGameProperties{
private:
	//Velocity on axis X
	int velocidadX;
	//Velocity on axis Y
	int velocidadY;
	//gosht Velocity on any axis
	int velocidadPatron;

	int posicionXDestino;
	int posicionYDestino;

	int incrementoPosicionX;
	int incrementoPosicionY;

	int RandMove;
public:
	// Builders and destroyers
	Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY,int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	// Accesor Methods 
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }

	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }

	// Various methods

	// Move gosht
	void move();
};