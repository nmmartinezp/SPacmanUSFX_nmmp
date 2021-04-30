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

	MenuComponent[0] = new MenuComponents(titleTexture, 100, 100, 300, 80, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuComponent[1] = new MenuComponents(logoTexture, 225, 185, 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuComponent[2] = new MenuComponents(botonTexture, 200, 245, 100, 30, SCREEN_WIDTH, SCREEN_HEIGHT);

	LevelGameGernerator = new MapGenerator(SCREEN_WIDTH, SCREEN_HEIGHT);
	LevelGameGernerator->load("Resources/mapa.txt");
	LevelGameGernerator->populate(actores);

    SDL_Event Event;

    while (juego_en_ejecucion) {
        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			optionSelect(Event);
			if (option == 1) {
				for (int i = 0; i < actores.size(); i++) {
					actores[i]->handleEvent(Event);
				}
			}
        }

		if (option == 1) {
			for (int i = 0; i < actores.size(); i++) {
				actores[i]->move();
				actores[i]->mostrar();
			}
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
		
		titleTexture = new Texture();
		titleTexture->loadFromImage("Resources/title.png");
		logoTexture = new Texture();
		logoTexture->loadFromImage("Resources/fantasma01_v1.png");
		botonTexture = new Texture();
		botonTexture->loadFromImage("Resources/boton-start.png");
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
	
	if (option == 2) {
		for (int i = 0; i < 3; i++) {
			MenuComponent[i]->render();
		}
		
	}

	if (option == 1) {
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->update();
			actores[i]->render();
		}
	}
};

void GameManager::optionSelect(SDL_Event& e)
{
	// Si se ha precionado una tecla
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		// Se ajusta la velocidad
		switch (e.key.keysym.sym)
		{
		case SDLK_RETURN: option = 1; break;
		case SDLK_SPACE: option = 2; break;
		/*case SDLK_ESCAPE:; break;*/
			//case SDLK_LEFT: velocidadX -= velocidadPatron; break;
			//case SDLK_RIGHT: velocidadX += velocidadPatron; break;
		}
	}
	//// Si se ha soltado una tecla
	//else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	//{
	//	// Se ajusta la velocidad
	//	switch (e.key.keysym.sym)
	//	{
	//	case SDLK_UP: velocidadY += velocidadPatron; break;
	//	case SDLK_DOWN: velocidadY -= velocidadPatron; break;
	//	case SDLK_LEFT: velocidadX += velocidadPatron; break;
	//	case SDLK_RIGHT: velocidadX -= velocidadPatron; break;
	//	}
	//}
}

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	
	SDL_Quit();
};