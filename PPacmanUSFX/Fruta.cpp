#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Texture* _frutasTextures[], int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	CommonGameProperties(_frutasTextures[4], _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	visible = false;
	for (int i = 0; i <= 3; i++) { frutasTextures[i] = _frutasTextures[i]; }	
}

void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) 
	{
		visible = false;
		if (visible == false) { cambioDeFruta = rand() % 4; }
		if (contadorTiempoNoVisible >= tiempoNoVisible) 
		{
			posicionX = 1 + rand() % (anchoPantalla - ancho);
			posicionY = 1 + rand() % (altoPantalla - alto);
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
		}
		else { contadorTiempoNoVisible++; }
	}
	else { contadorTiempoVisible++; }
}

void Fruta::render()
{
	if (visible) {
		SDL_Rect renderQuad = { 0, 0, ancho, alto };
		frutasTextures[cambioDeFruta]->render(posicionX, posicionY, &renderQuad);
	}
}