#include "MenuComponents.h"

MenuComponents::MenuComponents(Texture* _componentTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) 
{
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;
	alto = _alto;
	ancho = _ancho;
	posicionX = _posicionX;
	posicionY = _posicionY;
	componentTexture = _componentTexture;
}

void MenuComponents::render() {
	SDL_Rect renderQuad = { 0, 0, ancho, alto };

	//Render to screen
		componentTexture->render(posicionX, posicionY, &renderQuad);
};