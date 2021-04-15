#pragma once
#include <SDL.h>

class Fantasma3 {
private:
	//Posicion actual del fantasma3 en la pantalla
	int posicionX;
	int posicionY;

	//Velocidad en eje X
	int velocidadX;

	//Velocidad en el eje Y
	int velocidadY;

	//Velocidad a la que mueve el fantasma3 en cualquier eje
	int velocidadPatron;

	int ancho;
	int alto;

	int anchoPantalla;
	int altoPantalla;

	int posicionXDestino;
	int posicionYDestino;

	int incrementoPosicionX;
	int incrementoPosicionY;

	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Superficie grafica del fantasma3
	SDL_Surface* fantasma3Surface = nullptr;

	// Textura de la grafica del fantasma3
	SDL_Texture* fantasma3Texture = nullptr;

public:
	//Constructores y destructores
	Fantasma3(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _fantasma3Texture, int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla, int _velocidadPatron);

	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getVelocidadX() { return velocidadX; }
	int getVelocidadY() { return velocidadY; }
	int getVelocidadPatron() { return velocidadPatron; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }

	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setVelocidadX(int _velocidadX) { velocidadX = _velocidadX; }
	void setVelocidadY(int _velocidadY) { velocidadY = _velocidadY; }
	void setVelocidadPatron(int _velocidadPatron) { velocidadPatron = _velocidadPatron; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }


	// Metodos varios

	// Mover fantasma3
	void move();
	// Renderizar imagen fantasma3
	void render();


};