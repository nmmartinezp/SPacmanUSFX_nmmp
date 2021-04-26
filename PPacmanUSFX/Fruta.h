#pragma once
#include <SDL.h>
#include "Texture.h"
#include "CommonGameProperties.h"

class Fruta : public CommonGameProperties
{
private:
	int cambioDeFruta;
	
	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

	Texture* frutasTextures[4];
public:

	Fruta(Texture* _frutasTextures[], int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
	
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }

	// Metodos varios

	// Mostrar u ocultar fruta
	void mostrar();
	// Renderizar imagen fruta
	void renderizar();

};