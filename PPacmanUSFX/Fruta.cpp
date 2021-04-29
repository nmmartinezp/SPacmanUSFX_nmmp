#include "Fruta.h"
#include <iostream>

using namespace std;

Fruta::Fruta(Texture* _frutasTextures, int _posicionX, int _posicionY, int _ancho, int _alto, int _anchoPantalla, int _altoPantalla) :
	CommonGameProperties(_frutasTextures, _posicionX, _posicionY, _ancho, _alto, _anchoPantalla, _altoPantalla)
{
	tiempoVisible = 100;
	tiempoNoVisible = 150;
	contadorTiempoVisible = 0;
	contadorTiempoNoVisible = 0;
	visible = false;
	activador_update = 0;
}

void Fruta::mostrar()
{
	if (contadorTiempoVisible >= tiempoVisible) 
	{
		visible = false;
		activador_update = 2;
		if (contadorTiempoNoVisible >= tiempoNoVisible) 
		{
			posicionX = rand() % (anchoPantalla - ancho);
			posicionY = rand() % (altoPantalla - alto);
			contadorTiempoVisible = 0;
			contadorTiempoNoVisible = 0;
			visible = true;
			activador_update = 0;
			numeroFramey++;
		}
		else { contadorTiempoNoVisible++; }
	}
	else { contadorTiempoVisible++; }
}