#pragma once
#include <SDL.h>
#include "Texture.h"

class MenuComponents
{
private:
	int anchoPantalla;
	int altoPantalla;
	int alto;
	int ancho;
	int posicionX;
	int posicionY;
	Texture* componentTexture;
public:
	MenuComponents(Texture* _componentTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

	void render();
};

