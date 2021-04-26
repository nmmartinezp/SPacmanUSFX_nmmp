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
	fruta = new Fruta(gWindow, gRenderer, gScreenSurface, gFrutasTextures, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT);
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


			if ((gFrutasTextures[0] = loadTexture("Resources/Fruta01.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[1] = loadTexture("Resources/Fruta03.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[2] = loadTexture("Resources/Fruta02.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}
			if ((gFrutasTextures[3] = loadTexture("Resources/Fruta04.png")) == NULL) {
				cout << "Fallo en la carga de la textura aqui" << endl;
				return false;
			}


		}
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
	pacman->renderizar();

	
	fantasma->renderizar();
	fantasma1->renderizar();
	fantasma2->renderizar();
	fantasma3->renderizar();
	fruta->render();
};

void GameManager::onCleanup() {
	SDL_FreeSurface(gScreenSurface);
	
	SDL_Quit();
};


SDL_Texture* GameManager::loadTexture(string path)
{
	// Textura final generada
	SDL_Texture* newTexture = nullptr;

	// Carga una imagen de una ruta especifica
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "No se pudo cargarla imagen, SDL_image Error: " << IMG_GetError() << endl;
	}
	else
	{
		// Crea una textura a partir de una superficie de pixeles
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "No se pudo crear la textura, SDL Error: " << SDL_GetError() << endl;
		}

		// Libera la superficie cargada
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
