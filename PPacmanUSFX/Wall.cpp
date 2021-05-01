#include "Wall.h"

Wall::Wall(Texture* _wallTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) : 
	CommonGameProperties(_wallTexture, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla) 
{activador_update = 0;}
