#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	gScreenSurface = nullptr;
	MenuMusic = nullptr;
	juego_en_ejecucion = true;
	
}

int GameManager::onExecute() {
    if (onInit() == false) {
        return -1;
    }
	srand(time(NULL));
	loadsound();
	Mix_PlayMusic(MenuMusic, -1);
	MenuComponent[0] = new MenuComponents(titleTexture, 50, 100, 400, 100, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuComponent[1] = new MenuComponents(logoTexture, 225, 210, 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuComponent[2] = new MenuComponents(botonTexture, 175, 270, 150, 70, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuComponent[3] = new MenuComponents(barraTexture, 0, 450, 500, 30, SCREEN_WIDTH, SCREEN_HEIGHT);
	MenuComponent[4] = new MenuComponents(pauseTexture, 125, 200, 250, 80, SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Event Event;

    while (juego_en_ejecucion) {
        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			optionSelect(Event);
			if (option == Map || option == go) {
				for (int i = 0; i < actores.size(); i++) {
					actores[i]->handleEvent(Event);
				}
			}
        }
		
		if (option == Map || option == go) {
			for (int i = 0; i < actores.size(); i++) {
				actores[i]->move();
				actores[i]->mostrar();
			}
		}

		stopmusic();
		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);
		//Update screen
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
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
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

				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}
			}
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}

		Texture::renderer = gRenderer;
		
		titleTexture = new Texture();
		titleTexture->loadFromImage("Resources/title2.png");
		logoTexture = new Texture();
		logoTexture->loadFromImage("Resources/fantasma01_v1.png");
		botonTexture = new Texture();
		botonTexture->loadFromImage("Resources/start_neon1.png");
		pauseTexture = new Texture();
		pauseTexture->loadFromImage("Resources/pause_neon2.png");
		barraTexture = new Texture();
		barraTexture->loadFromImage("Resources/barra_menu.png");
	}
	
	return success;
};

bool GameManager::loadsound() {
	int success = true;
	MenuMusic = Mix_LoadMUS("sound/Pacman_theme.mp3");
	if (MenuMusic == nullptr)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	return success;
}

void GameManager::stopmusic() {
	if (option != 0) {
		Mix_HaltMusic();
		Mix_FreeMusic(MenuMusic);
		MenuMusic = nullptr;
	}
}

void GameManager::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		juego_en_ejecucion = false;
	}
};

void GameManager::onRender() {
	
	if (option == 0) {
		for (int i = 0; i < 4; i++) {
			MenuComponent[i]->render();
		}
	}

	if (option == Map || option == go) {
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->update();
			actores[i]->render();
		}
	}

	if (option == pause) {
		
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->update();
			actores[i]->render();
		}
		MenuComponent[4]->render();
	}
};

void GameManager::optionSelect(SDL_Event& e)
{
	// Si se ha precionado una tecla
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		// Se selecciona una accion
		switch (e.key.keysym.sym)
		{
		case SDLK_RETURN:
			if (option == 0) {
				option = Map;
				brYdr();
			}
			break;
		case SDLK_ESCAPE:
			if (option == Map || option == pause || option == go) {
				loadsound();
				Mix_PlayMusic(MenuMusic, -1);
				option = 0;
				brYdr();
				break;
			}
			if (option == 0) {
				SDL_FreeSurface(gScreenSurface);
				SDL_Quit();
			}
		case SDLK_SPACE:
			if (option == Map || option == go) {
				option = pause;
				brYdr();
				break;
			}
			if (option == pause) {
				option = go;
				brYdr();
				break;
			}
		}
	}
}

void GameManager::brYdr() {
	if (option == Map) {
		LevelGameGernerator = new MapGenerator(SCREEN_WIDTH, SCREEN_HEIGHT);
		LevelGameGernerator->load("Resources/mapa.txt");
		LevelGameGernerator->populate(actores);
	}

	if (option == 0) {
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->~CommonGameProperties();
			actores[i]->destroyer();
		}
	}
}

void GameManager::onCleanup() {
	Mix_FreeMusic(MenuMusic);
	MenuMusic = nullptr;
	SDL_FreeSurface(gScreenSurface);
	Mix_Quit();
	SDL_Quit();
};