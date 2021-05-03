#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Pacman.h"
#include "Fantasma.h"
#include "Fruta.h"
#include "Coin.h"

#include "CommonGameProperties.h"
#include "Texture.h"
#include "MapGenerator.h"
#include "MenuComponents.h"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 480;

class GameManager
{
private:
    bool juego_en_ejecucion;
    int option, Map, pause, go;
    //The window we'll be rendering to
    SDL_Window* gWindow;
    //The window renderer
    SDL_Renderer* gRenderer;
    //The surface contained by the window
    SDL_Surface* gScreenSurface;

    Texture* titleTexture;
    Texture* logoTexture;
    Texture* botonTexture;
    Texture* pauseTexture;
    Texture* barraTexture;

    Mix_Music* MenuMusic;
public:
    MenuComponents* MenuComponent[5];
    MapGenerator* LevelGameGernerator;
    vector<CommonGameProperties*> actores;
public:
    GameManager();
    int onExecute();
    bool onInit();
    bool playsound();
    void onEvent(SDL_Event* Event);
    void onRender();
    void stopsound();
    void onCleanup();
    void brYdr();
    void optionSelect(SDL_Event& e);
    //SDL_Texture* loadTexture(string path);
    //void onLoop();
};

    