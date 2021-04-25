#include "Fantasma.h"
#include <iostream>

using namespace std;

Fantasma::Fantasma(Texture* _fantasmaTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla, int _velocidadPatron) :
	CommonGameProperties(_posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	//start properties
	velocidadX = 1;
	velocidadY = 1;
	
	velocidadPatron = _velocidadPatron;

	fantasmaTexture = _fantasmaTexture;

	numeroFrame = 0;
	contadorFrames = 0;

	RandMove = 0;
}



void Fantasma::move()
{
	if (RandMove == 1) {
		//movement on X axis
		if (incrementoPosicionX > 0) {
			if (posicionX >= posicionXDestino || (posicionX + ancho) >= anchoPantalla) {
				posicionXDestino = 1 + rand() % (anchoPantalla - ancho);
				//random movement
				RandMove = rand() % 2;
				if (posicionX > posicionXDestino) {
					incrementoPosicionX = -1;
				}
				else {
					incrementoPosicionX = 1;
				}

			}
			else {
				posicionX = posicionX + incrementoPosicionX * velocidadX;
			}
		}
		else {
			if (posicionX <= posicionXDestino || (posicionX <= 0)) {
				posicionXDestino = 1 + rand() % (anchoPantalla - ancho);
				//random movement
				RandMove = rand() % 2;
				if (posicionX > posicionXDestino) {
					incrementoPosicionX = -1;
				}
				else {
					incrementoPosicionX = 1;
				}
			}
			else {
				posicionX = posicionX + incrementoPosicionX * velocidadX;
			}
		}
	}
	else {
		//movement on Y axis
		if (incrementoPosicionY > 0) {
			if (posicionY >= posicionYDestino || (posicionY + alto) >= altoPantalla) {
				posicionYDestino = 1 + rand() % (altoPantalla - alto);
				//random movement
				RandMove = rand() % 2;
				if (posicionY > posicionYDestino) {
					incrementoPosicionY = -1;
				}
				else {
					incrementoPosicionY = 1;
				}
			}
			else {
				posicionY = posicionY + incrementoPosicionY * velocidadY;
			}
		}
		else {
			if (posicionY <= posicionYDestino || (posicionY <= 0)) {
				posicionYDestino = 1 + rand() % (altoPantalla - alto);
				//random movement
				RandMove = rand() % 2;
				if (posicionY > posicionYDestino) {
					incrementoPosicionY = -1;
				}
				else {
					incrementoPosicionY = 1;
				}
			}
			else {
				posicionY = posicionY + incrementoPosicionY * velocidadY;
			}
		}
	}
	
}

void Fantasma::render()
{
	
	SDL_Rect renderQuad = { 25 * numeroFrame, 0, ancho, alto };

	//Render to screen
	fantasmaTexture->render( posicionX, posicionY, &renderQuad);
}

void Fantasma::update() {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	}

}

