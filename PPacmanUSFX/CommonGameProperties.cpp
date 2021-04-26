#include "CommonGameProperties.h"

int CommonGameProperties::MakeNumberObjects = 0;

CommonGameProperties::CommonGameProperties(int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) {
	posicionX = _posicionX;
	posicionY = _posicionY;
	ancho = _ancho;
	alto = _alto;
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	visible = true;
	MakeNumberObjects++;
	idObjeto = MakeNumberObjects;
}

void CommonGameProperties::render() {};