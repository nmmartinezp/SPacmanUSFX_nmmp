#include "Fruta.h"
#include <iostream>

using namespace std;

int cambioDeFruta;

Fruta::Fruta() {
	posicionX = 50;
	posicionY = 50;
	ancho = 20;
	alto = 20;
	anchoPantalla = 640;
	altoPantalla = 480;

	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
}

Fruta::Fruta(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutasTextures[4], int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla)
{
	// Inicializa propiedade de la fruta
	posicionX = _posicionX;
	posicionY = _posicionY;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	ancho = 25;
	alto = 25;
	
	tipoFruta = TIPO_FRUTA_GUINDA;

	visible = false;

	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;

	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;

	for (int i = 0; i <= 3; i++) {
		frutasTextures[i] = _frutasTextures[i];
	}
}


void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) {
		visible = false;
		if (visible == false) {
			cambioDeFruta = rand() % 4;
		}
		if (contadorTiempoNoVisible >= tiempoNoVisible) {
			posicionX = 1 + rand() % anchoPantalla;
			posicionY = 1 + rand() % altoPantalla;
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
		}
		else {
			contadorTiempoNoVisible++;
		}
	}
	else {
		contadorTiempoVisible++;
	}
}

void Fruta::render()
{
	if (visible) {
		
		SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };
		SDL_RenderCopyEx(renderer, frutasTextures[cambioDeFruta], nullptr, &renderQuad, 0.0, nullptr, SDL_FLIP_NONE);
	}
}