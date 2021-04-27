#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;

	juego_en_ejecucion = true;
	
}

int GameManager::onExecute() {
    if (onInit() == false) {
        return -1;
    }

	pacman = new Pacman(pacmanTexture, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fantasma = new Fantasma(fantasmaTexture, 0, 0, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fantasma1 = new Fantasma(fantasma1Texture, 500, 400, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fantasma2 = new Fantasma(fantasma2Texture, 0, 400, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fantasma3 = new Fantasma(fantasma3Texture, 500, 0, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT, 5);
	fruta = new Fruta(frutasTextures, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT);

	int posX = 0;
	for (int i = 0; i < 10; i++)
	{
		cout << "Moneda " << i << " creada" << "///";
		posX = i * 50;
		coin[i] = new Coin(coinTexture, posX, 150, 25, 25, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	
	srand(time(NULL));

    SDL_Event Event;

    while (juego_en_ejecucion) {
        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			pacman->handleEvent(Event);
        }
		// Mover Pacman
		pacman->move();

		// Mover Fantasmas
		fantasma->move();
		fantasma1->move();
		fantasma2->move();
		fantasma3->move();

		//mostrar fruta
		fruta->mostrar();

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

		//Update screen
        onLoop();
        onRender();
		SDL_RenderPresent(gRenderer);
    }
    onCleanup();
    return 0;
}

bool GameManager::onInit() {

	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("Pacman_USFX_nmmp", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}

		Texture::renderer = gRenderer;

		pacmanTexture = new Texture();
		pacmanTexture->loadFromImage("Resources/PacMan_01.bmp");

		fantasmaTexture = new Texture();
		fantasmaTexture->loadFromImage("Resources/Fantasma.bmp");

		fantasma1Texture = new Texture();
		fantasma1Texture->loadFromImage("Resources/Fantasma.bmp");

		fantasma2Texture = new Texture();
		fantasma2Texture->loadFromImage("Resources/Fantasma.bmp");

		fantasma3Texture = new Texture();
		fantasma3Texture->loadFromImage("Resources/Fantasma.bmp");

		frutasTextures[0] = new Texture();
		frutasTextures[0]->loadFromImage("Resources/fruta01.bmp");

		frutasTextures[1] = new Texture();
		frutasTextures[1]->loadFromImage("Resources/fruta02.bmp");

		frutasTextures[2] = new Texture();
		frutasTextures[2]->loadFromImage("Resources/fruta03.bmp");

		frutasTextures[3] = new Texture();
		frutasTextures[3]->loadFromImage("Resources/fruta04.bmp");

		coinTexture = new Texture();
		coinTexture->loadFromImage("Resources/point.bmp");
	}
	
	return success;
};

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};

void GameManager::onLoop() {};

void GameManager::onRender() {
	for (int i = 0; i < 10; i++) {coin[i]->render();}
	fruta->renderizar();
	pacman->render();
	fantasma->render();
	fantasma1->render();
	fantasma2->render();
	fantasma3->render();
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	
	SDL_Quit();
};