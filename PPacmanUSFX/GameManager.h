#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"

#include "Fantasma.h"
#include "Texture.h"

#include "Fruta.h"

using namespace std;


//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class GameManager
{
private:
    bool juego_en_ejecucion;

    //The window we'll be rendering to
    SDL_Window* gWindow;

    //The window renderer
    SDL_Renderer* gRenderer;

    //The surface contained by the window
    SDL_Surface* gScreenSurface;

    Texture* frutasTextures[4];

    Texture* fantasmaTexture = nullptr;
    Texture* fantasma1Texture = nullptr;
    Texture* fantasma2Texture = nullptr;
    Texture* fantasma3Texture = nullptr;
    Texture* pacmanTexture = nullptr;
 
public:
    Pacman* pacman;
    Fantasma* fantasma;
    Fantasma* fantasma1;
    Fantasma* fantasma2;
    Fantasma* fantasma3;
    Fruta* fruta;

public:
    GameManager();
    int onExecute();
    
    bool onInit();

    void onEvent(SDL_Event* Event);
    void onLoop();
    void onRender();
    void onCleanup();
    SDL_Texture* loadTexture(string path);   
};

    