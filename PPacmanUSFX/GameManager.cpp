#include "GameManager.h"

using namespace std;

GameManager::GameManager() {
	option = MENU;
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

	playsound();
    SDL_Event Event;

	Lobby = new MenuGenerator(SCREEN_WIDTH, SCREEN_HEIGHT);
	Lobby->load();
	Lobby->Pop(obs);

    while (juego_en_ejecucion) {
        while (SDL_PollEvent(&Event)) {
            onEvent(&Event);
			optionSelect(Event);
			if (option == MAP || option == GO) {
				for (int i = 0; i < actores.size(); i++) {
					actores[i]->handleEvent(Event);
				}
			}
        }
		
		if (option == MAP || option == GO) {
			for (int i = 0; i < actores.size(); i++) {
				actores[i]->move();
				actores[i]->mostrar();
			}
		}

		stopsound();
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);
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
	}
	
	return success;
};

bool GameManager::playsound() {
	int success = true;
	MenuMusic = Mix_LoadMUS("sound/Pacman_theme.mp3");
	if (MenuMusic == nullptr)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	Mix_PlayMusic(MenuMusic, -1);
	return success;
}

void GameManager::stopsound() {
	if (option != MENU) {
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
	
	if (option == MENU) {
		for (int i = 0; i < obs.size()-1; i++) {
			obs[i]->render();
		}
	}

	if (option == MAP || option == GO) {
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->update();
			actores[i]->render();
		}
	}

	if (option == PAUSE) {
		
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->update();
			actores[i]->render();
		}
		obs[4]->render();
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
			if (option == MENU) {
				option = MAP;
				brYdr();
			}
			break;
		case SDLK_ESCAPE:
			if (option == MAP || option == PAUSE || option == GO) {
				playsound();
				option = MENU;
				brYdr();
				break;
			}
			if (option == MENU) {
				onCleanup();
			}
		case SDLK_SPACE:
			if (option == MAP || option == GO) {
				option = PAUSE;
				brYdr();
				break;
			}
			if (option == PAUSE) {
				option = GO;
				brYdr();
				break;
			}
		}
	}
}

void GameManager::brYdr() {
	if (option == MAP) {
		LevelGameGernerator = new MapGenerator(SCREEN_WIDTH, SCREEN_HEIGHT - 30);
		LevelGameGernerator->load("Resources/mapa.txt");
		LevelGameGernerator->populate(actores);
	}

	if (option == MENU) {
		for (int i = 0; i < actores.size(); i++) {
			actores[i]->~CommonGameProperties();
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