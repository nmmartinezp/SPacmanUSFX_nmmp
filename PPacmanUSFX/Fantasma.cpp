#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedades del fantasma
	velocidadX = 0;
	velocidadY = 0;
	ancho = 25;
	alto = 25;

	posicionX = _posicionX;
	posicionY = _posicionY;
	
	velocidadPatron = _velocidadPatron;
	
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	window = _window;
	renderer = _renderer;
	screenSurface = _screenSurface;
	fantasmaTexture = _fantasmaTexture;
}

void Fantasma::move()
{

	if (posicionX >= posicionXDestino) {
		if (posicionY >= posicionYDestino) {
			posicionXDestino = 1 + rand() % anchoPantalla;
			posicionYDestino = 1 + rand() % altoPantalla;
			
			if (posicionX > posicionXDestino) {
				incrementoPosicionX = -1;
			}
			else
			{
				incrementoPosicionX = 1;
			}

			if (posicionY > posicionXDestino) {
				incrementoPosicionY = -1;
			}
			else
			{
				incrementoPosicionY = 1;
			}
		}
		else {
			posicionY = posicionY + incrementoPosicionY;

			// Mover el fantasma arriba o abajo
			posicionY += velocidadY;

			// Verificar si la posicion del fantasma no salio de los bordes superior e inferior
			if ((posicionY < 0) || (posicionY + alto > altoPantalla))
			{
				// Mover fantasma atras
				posicionXDestino = 1 + rand() % anchoPantalla;
				posicionYDestino = 1 + rand() % altoPantalla;
			}
		}
	}
	else {
		posicionX = posicionX + incrementoPosicionX;

		// Mover el fantasma a la izquierda o derecha
		posicionX += velocidadX;

		// Verificar si la posicion del fantasma no salio de los bordes izquierdo o derecho
		if ((posicionX < 0) || (posicionX + ancho > anchoPantalla))
		{
			// Mover fantasma atras
			posicionXDestino = 1 + rand() % anchoPantalla;
			posicionYDestino = 1 + rand() % altoPantalla;
		}
	}

}

void Fantasma::render()
{
	SDL_Rect renderQuad = { posicionX, posicionY, ancho, alto };

	//Render to screen
	SDL_RenderCopyEx(renderer, fantasmaTexture, NULL, &renderQuad, 0.0, NULL, SDL_FLIP_NONE);
}