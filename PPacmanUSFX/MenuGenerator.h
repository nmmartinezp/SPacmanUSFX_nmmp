#pragma once
#include<iostream>
#include <vector>
#include <string>
#include "Texture.h"
#include "MenuComponents.h"

using namespace std;

class MenuGenerator
{
private:
	MenuComponents* MenuComponent[5];
	vector<MenuComponents*> vectorObjetosMenu;

	const string pathTitle = "Resources/title2.png";
	const string pathLogo = "Resources/fantasma01_v1.png";
	const string pathBotton = "Resources/start_neon1.png";
	const string pathPause = "Resources/pause_neon2.png";
	const string pathBarra = "Resources/barra_menu.png";

	Texture* titleTexture = nullptr;
	Texture* logoTexture = nullptr;
	Texture* bottonTexture = nullptr;
	Texture* pauseTexture = nullptr;
	Texture* barraTexture = nullptr;

	int anchoPantalla;
	int altoPantalla;
public:
	MenuGenerator(int _anchoPantalla, int _altoPantalla);

	void load();
	void Pop(vector<MenuComponents*>& _vectorObjetosMenuGV);
};

