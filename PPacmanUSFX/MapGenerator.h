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
#include "Wall.h"

using namespace std;

class MapGenerator
{
private:
	vector<CommonGameProperties*> vectorObjetosJuego;

	const string pathPacman = "Resources/pacman_01.png";
	const string pathFantasma1 = "Resources/Fantasma01.png";
	const string pathFantasma2 = "Resources/Fantasma02.png";
	const string pathFantasma3 = "Resources/Fantasma01.bmp";
	const string pathFantasma4 = "Resources/Fantasma01.bmp";
	const string pathFrutas = "Resources/Frutas.png";
	const string pathCoin = "Resources/monedas-chinas.png";
	const string pathWall = "Resources/pared_abajo.png";
	const string pathWall2 = "Resources/pared_arriba.png";
	const string pathWall3 = "Resources/codo1.png";
	const string pathWall4 = "Resources/codo2.png";
	const string pathWall5 = "Resources/codo3.png";
	const string pathWall6 = "Resources/codo4.png";
	const string pathBarra = "Resources/barra_game.png";

	Texture* frutasTextures;
	Texture* fantasma1Texture = nullptr;
	Texture* fantasma2Texture = nullptr;
	Texture* fantasma3Texture = nullptr;
	Texture* fantasma4Texture = nullptr;
	Texture* pacmanTexture = nullptr;
	Texture* coinTexture = nullptr;
	Texture* wallTexture = nullptr;
	Texture* wallTexture2 = nullptr;
	Texture* wallTexture3 = nullptr;
	Texture* wallTexture4 = nullptr;
	Texture* wallTexture5 = nullptr;
	Texture* wallTexture6 = nullptr;
	Texture* barraTexture = nullptr;

	int anchoPantalla;
	int altoPantalla;
public:
	MapGenerator(int _anchoPantalla, int _altoPantalla);

	// carga el archivo con el mapa del nivel y todos los objetos
	bool load(string path);

	// carga los objetos generados por la clase MapGeneratos a un array de punteros a objetos GameObject*
	void populate(vector<CommonGameProperties*>& _vectorObjetosJuegoGM);
};