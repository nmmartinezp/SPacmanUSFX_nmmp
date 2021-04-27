#pragma once
#include <SDL.h>
#include "CommonGameProperties.h"

class Coin : public CommonGameProperties
{
public:
    Coin(Texture* _coinTexture, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla);

    void renderizar();
};

