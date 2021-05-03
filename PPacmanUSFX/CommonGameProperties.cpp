#include "CommonGameProperties.h"

int CommonGameProperties::MakeNumberObjects = 0;

CommonGameProperties::CommonGameProperties(Texture* _ObjectTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	disable_change = false;
	activate_change = true;
	activador_update = activate_change;
	visible = true;
	MakeNumberObjects++;
	idObjeto = MakeNumberObjects;
	ObjectTexture = _ObjectTexture;
	numeroFramex = 0;
	numeroFramey = 0;
	contadorFrames = 0;
	framesMovimiento = 1;
}

CommonGameProperties::~CommonGameProperties() {
	destroyer();
};

void CommonGameProperties::render() {
	SDL_Rect renderQuad = { 25 * numeroFramex, 25 * numeroFramey, ancho, alto };

	//Render to screen
	if (visible == true) {
		ObjectTexture->render(posicionX, posicionY, &renderQuad);
	}
};

void CommonGameProperties::update() {
	if (activador_update == activate_change) {
		contadorFrames++;
		numeroFramex = contadorFrames / 8;

		if (numeroFramex > framesMovimiento - 1) {
			numeroFramex = 0;
			contadorFrames = 0;
		}
	}
};

void CommonGameProperties::destroyer() {
	ObjectTexture->free();
}
