#include "CommonGameProperties.h"

int CommonGameProperties::MakeNumberObjects = 0;

CommonGameProperties::CommonGameProperties(Texture* _ObjectTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	activador_update = 1;
	visible = true;
	MakeNumberObjects++;
	idObjeto = MakeNumberObjects;
	ObjectTexture = _ObjectTexture;
	numeroFrame = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
}

void CommonGameProperties::render() {
	SDL_Rect renderQuad = { 25 * numeroFrame, 0, ancho, alto };

	//Render to screen
	if (visible == true) {
		ObjectTexture->render(posicionX, posicionY, &renderQuad);
	}
};

void CommonGameProperties::update() {
	if (activador_update == 1) {
		contadorFrames++;
		numeroFrame = contadorFrames / 8;

		if (numeroFrame > framesMovimiento - 1) {
			numeroFrame = 0;
			contadorFrames = 0;
		}
	}
	if (activador_update == 2) {
		if (numeroFrame > framesMovimiento - 1) {
			numeroFrame = 0;
		}
	}
};
