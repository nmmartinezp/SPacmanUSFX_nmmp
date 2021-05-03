
//CLASE PADRE DE LOS ACTORES DE JUEGO
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
	bool activador_update;
	bool disable_change;
	bool activate_change;

	int numeroFramex;
	int numeroFramey;
	int contadorFrames;
	int framesMovimiento;

	Texture* ObjectTexture;
public:
	static int MakeNumberObjects;

public:
	
	CommonGameProperties(Texture* _ObjectTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	~CommonGameProperties();

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

	void setParametrosAnimacion(int _framesMovimiento) { framesMovimiento = _framesMovimiento; }

	//render de imagen
	virtual void render();
	//movimiento de objeto
	virtual void move() {};
	//actualizacion de datos
	virtual void update();
	//visibilidad de objeto
	virtual void mostrar() {};

	virtual void handleEvent(SDL_Event& e) {};
	virtual void destroyer();
};

