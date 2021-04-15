#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>

#include "Pacman.h"

#include "Fantasma.h"
#include "Fantasma2.h"
#include "Fantasma3.h"
#include "Fantasma4.h"

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

    //The images we will load and show on the screen
    SDL_Texture* gPacmanTexture;

    SDL_Texture* gFantasmaTexture;
    SDL_Texture* gFantasma2Texture;
    SDL_Texture* gFantasma3Texture;
    SDL_Texture* gFantasma4Texture;

    SDL_Texture* gFrutasTextures[3];
 
public:
    Pacman* pacman;
    Fantasma* fantasma;
    Fantasma2* fantasma2;
    Fantasma3* fantasma3;
    Fantasma4* fantasma4;
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

    