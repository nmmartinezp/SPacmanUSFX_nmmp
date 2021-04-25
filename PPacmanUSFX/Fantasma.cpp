#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron)
{
	// Inicializa propiedades del fantasma
	velocidadX = 0;
	velocidadY = 0;

	ancho = _ancho;
	alto = _alto;

	posicionX = _posicionX;
	posicionY = _posicionY;
	
	velocidadPatron = _velocidadPatron;
	
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	fantasmaTexture = _fantasmaTexture;

	numeroFrame = 0;
	contadorFrames = 0;
}

void Fantasma::move()
{
	numeroAnimacion++;
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
				posicionY = -velocidadY;
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
			posicionX = -velocidadX;
		}
	}
	

}

void Fantasma::render()
{
	
	SDL_Rect renderQuad = { 25 * numeroFrame, 0, getAncho(), getAlto() };

	//Render to screen
	fantasmaTexture->render( getPosicionX(), getPosicionY(), &renderQuad);
}

void Fantasma::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}

