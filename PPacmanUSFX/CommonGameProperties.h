#pragma once
#include <iostream>
#include <string>
#include "Texture.h"

using namespace std;

class CommonGameProperties
{
public:
	string nombre;
protected:

	int idObjeto;
	int posicionX;
	int posicionY;

	int ancho;
	int alto;

	int anchoPantalla;
	int altoPantalla;

	bool visible;

	Texture* texturaObjeto;
public:
	static int MakeNumberObjects;

public:

	CommonGameProperties( int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

	int getIdObjeto() { return idObjeto; }
	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setVisible(bool _visible) { visible = _visible; }

	virtual void render();
	virtual void move() {};
	virtual void update() {};
	virtual void mostrar() {};
};

