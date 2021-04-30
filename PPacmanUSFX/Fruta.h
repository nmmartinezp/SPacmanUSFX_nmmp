
//CLASE HIJA DE COMMONGAMEPROPERTIES
#pragma once
#include <iostream>
#include <SDL.h>
#include "CommonGameProperties.h"

class Fruta : public CommonGameProperties
{
private:	
	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;
public:
	Fruta(Texture* _frutasTextures, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }

	// Mostrar u ocultar fruta
	void mostrar();
};