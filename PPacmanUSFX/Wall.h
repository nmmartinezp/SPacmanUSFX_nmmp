#pragma once
#include <SDL.h>
#include "CommonGameProperties.h"

class Wall : public CommonGameProperties
{
public:
	Wall(Texture* _wallTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);
};

