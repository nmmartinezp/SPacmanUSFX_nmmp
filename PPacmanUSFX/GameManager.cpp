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
	srand(time(NULL));

	LevelGameGernerator = new MapGenerator(SCREEN_WIDTH, SCREEN_HEIGHT);
	LevelGameGernerator->load("Resources/mapa.txt");
	LevelGameGernerator->populate(actores);

    SDL_Event Event;

    while (juego_en_ejecucion) {
        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			for (int i = 0; i < actores.size(); i++) {
				actores[i]->handleEvent(Event);
			}
			//pacman->handleEvent(Event);
        }

		for (int i = 0; i < actores.size(); i++) {
			actores[i]->move();
			actores[i]->mostrar();
		}

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
	for (int i = 0; i < actores.size(); i++) {
		actores[i]->update();
		actores[i]->render();
	}
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	
	SDL_Quit();
};