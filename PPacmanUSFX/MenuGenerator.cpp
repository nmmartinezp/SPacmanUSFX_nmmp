#include "MenuGenerator.h"

MenuGenerator::MenuGenerator(int _anchoPantalla, int _altoPantalla){
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	titleTexture = new Texture();
	titleTexture->loadFromImage(pathTitle);
	logoTexture = new Texture();
	logoTexture->loadFromImage(pathLogo);
	bottonTexture = new Texture();
	bottonTexture->loadFromImage(pathBotton);
	pauseTexture = new Texture();
	pauseTexture->loadFromImage(pathPause);
	barraTexture = new Texture();
	barraTexture->loadFromImage(pathBarra);
}

void MenuGenerator::load(){
	MenuComponent[0] = new MenuComponents(titleTexture, 50, 100, 400, 100, anchoPantalla, altoPantalla);
	MenuComponent[1] = new MenuComponents(logoTexture, 225, 210, 50, 50, anchoPantalla, altoPantalla);
	MenuComponent[2] = new MenuComponents(bottonTexture, 175, 270, 150, 70, anchoPantalla, altoPantalla);
	MenuComponent[3] = new MenuComponents(barraTexture, 0, 450, 500, 30, anchoPantalla, altoPantalla);
	MenuComponent[4] = new MenuComponents(pauseTexture, 125, 200, 250, 80, anchoPantalla, altoPantalla);

	for (int i=0 ; i < 5; i++) {
		vectorObjetosMenu.push_back(MenuComponent[i]);
	}
}

void MenuGenerator::Pop(vector<MenuComponents*>& _vectorObjetosMenuGV){
	for (unsigned int i = 0; i < vectorObjetosMenu.size(); i++) {
		_vectorObjetosMenuGV.push_back(vectorObjetosMenu[i]);
	}
}