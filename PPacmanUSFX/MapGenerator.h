#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>

#include "CommonGameProperties.h"
#include "Texture.h"
#include "Coin.h"
#include "Fantasma.h"
#include "Pacman.h"
#include "Fruta.h"


using namespace std;

class MapGenerator
{
private:
	vector<CommonGameProperties*> vectorObjetosJuego;

	const string pathPacman = "Resources/PacMan_01.bmp";
	const string pathFantasma1 = "Resources/Fantasma01.bmp";
	const string pathFantasma2 = "Resources/Fantasma01.bmp";
	const string pathFantasma3 = "Resources/Fantasma01.bmp";
	const string pathFantasma4 = "Resources/Fantasma01.bmp";
	const string pathFrutas = "Resources/Fantasma02.bmp";
	const string pathCoin = "Resources/monedas-chinas.png";

	//const string pathSuperMoneda = "Resources/Monedas03.jpg";
	//const string pathPared = "Resources/wall_sprite.bmp";

	//Texture* pacmanTexture;
	//Texture* fantasma1Texture;
	//Texture* fantasma2Texture;
	//Texture* fantasma3Texture;
	//Texture* fantasma4Texture;
	//Texture* frutaTexture;
	//Texture* monedaTexture;
	//Texture* superMonedaTexture;
	//Texture* paredTexture;

	Texture* frutasTextures;
	Texture* fantasma1Texture = nullptr;
	Texture* fantasma2Texture = nullptr;
	Texture* fantasma3Texture = nullptr;
	Texture* fantasma4Texture = nullptr;
	Texture* pacmanTexture = nullptr;
	Texture* coinTexture = nullptr;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<CommonGameProperties*>& _vectorObjetosJuegoGM);
};