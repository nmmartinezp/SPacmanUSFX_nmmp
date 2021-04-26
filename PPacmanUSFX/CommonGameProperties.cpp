#include "CommonGameProperties.h"

int CommonGameProperties::MakeNumberObjects = 0;

CommonGameProperties::CommonGameProperties(Texture* _ObjectTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	MakeNumberObjects++;
	idObjeto = MakeNumberObjects;
	ObjectTexture = _ObjectTexture;
}

void CommonGameProperties::render(int posicionX, int posicionY, int numeroFrame, int ancho, int alto) {
	SDL_Rect renderQuad = { 25 * numeroFrame, 0, ancho, alto };

	//Render to screen
	ObjectTexture->render(posicionX, posicionY, &renderQuad);
};

void CommonGameProperties::update(int contadorFrames, int numeroFrame, int framesMovimiento) {
	contadorFrames++;
	numeroFrame = contadorFrames / 8;

	if (numeroFrame > framesMovimiento - 1) {
		numeroFrame = 0;
		contadorFrames = 0;
	};
};
