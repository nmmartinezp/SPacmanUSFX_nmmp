#include "Coin.h"

Coin::Coin(Texture* _coinTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	CommonGameProperties(_coinTexture, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	ObjectTexture = _coinTexture;
}

void Coin::renderizar() {
	render( posicionX, posicionY, 0, ancho, alto);
}
