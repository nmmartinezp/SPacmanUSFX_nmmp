#include "Fantasma2.h"
#include <iostream>

using namespace std;

Fantasma2::Fantasma2(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasma2Texture, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedade del fantasma2
	velocidadX = 0;
	velocidadY = 0;
	ancho = 25;
	alto = 25;

	velocidadPatron = _velocidadPatron;

	posicionX = _posicionX;
	posicionY = _posicionY;

	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	fantasma2Texture = _fantasma2Texture;
}

void Fantasma2::move()
{

	if (posicionX >= posicionXDestino || posicionX + ancho > anchoPantalla || posicionX < 0) {
		if (posicionY >= posicionYDestino || posicionY + alto > altoPantalla || posicionY < 0) {
			posicionXDestino = rand() % anchoPantalla + 1;
			posicionYDestino = rand() % altoPantalla + 1;

			if (posicionX > posicionXDestino) {
				incrementoPosicionX = -1;
			}
			else
			{
				incrementoPosicionX = 1;
			}

			if (posicionY > posicionYDestino) {
				incrementoPosicionY = -1;
			}
			else
			{
				incrementoPosicionY = 1;
			}
		}
		else {
			posicionY = posicionY + incrementoPosicionY;

			// Mover el fantasma2 arriba o abajo
			//posicionY += velocidadY;

			// Verificar si la posicion del fantasma2 no salio de los bordes superior e inferior
			if ((posicionY < 0) || (posicionY + alto > altoPantalla))
			{
				// Mover fantasma2 atras
				posicionY -= velocidadY;
			}
		}
	}
	else {
		posicionX = posicionX + incrementoPosicionX;

		// Mover el fantasma2 a la izquierda o derecha
		//posicionX += velocidadX;

		// Verificar si la posicion del fantasma2 no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma2 atras
			posicionX -= velocidadX;
		}
	}

}

void Fantasma2::render()
{
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	//Render to screen
	SDL_RenderCopyEx(renderer, fantasma2Texture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}

