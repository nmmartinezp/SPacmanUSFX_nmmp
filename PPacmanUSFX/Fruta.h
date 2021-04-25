#pragma once
#include <SDL.h>

class Fruta
{
private:
	// Ubicacion donde aparece la fruta
	int posicionX;
	int posicionY;
	
	int ancho;
	int alto;

	int anchoPantalla;
	int altoPantalla;

	int cambioDeFruta;
	
	bool visible;
	int tiempoVisible;
	int tiempoNoVisible;

	int contadorTiempoVisible;
	int contadorTiempoNoVisible;

public:
	// Ventana en la que se realizara el tratamiento grafico de renderizacion
	SDL_Window* window = nullptr;

	// Renderizador de la ventana
	SDL_Renderer* renderer = nullptr;

	// La superficie grafica (surface) que contiene la ventana
	SDL_Surface* screenSurface = nullptr;

	// Array de las texturas de las diferentes frutas;
	SDL_Texture* frutasTextures[4];


public:
	//Constructores y destructores
	Fruta(SDL_Window* _window, SDL_Renderer* _renderer, SDL_Surface* _screenSurface, SDL_Texture* _frutasTextures[4], int _posicionX, int _posicionY, int _anchoPantalla, int _altoPantalla);
	//~Fruta();

	//Metodos accesores

	int getPosicionX() { return posicionX; }
	int getPosicionY() { return posicionY; }
	int getAncho() { return ancho; }
	int getAlto() { return alto; }
	int getAnchoPantalla() { return anchoPantalla; }
	int getAltoPantalla() { return altoPantalla; }
	bool getVisible() { return visible; }
	int getTiempoVisible() { return tiempoVisible; }
	int getTiempoNoVisible() { return tiempoNoVisible; }
	
	void setPosicionX(int _posicionX) { posicionX = _posicionX; }
	void setPosicionY(int _posicionY) { posicionY = _posicionY; }
	void setAncho(int _ancho) { ancho = _ancho; }
	void setAlto(int _alto) { alto = _alto; }
	void setAnchoPantalla(int _anchoPantalla) { anchoPantalla = _anchoPantalla; }
	void setAltoPantalla(int _altoPantalla) { altoPantalla = _altoPantalla; }
	void setVisible(bool _visible) { visible = _visible; }
	void setTiempoVisble(int _tiempoVisible) { tiempoVisible = _tiempoVisible; }
	void setTiempoNoVisble(int _tiempoNoVisible) { tiempoNoVisible = _tiempoNoVisible; }

	// Metodos varios

	// Manejador de eventos de la fruta
	//void handleEvent(SDL_Event& e);

	// Mostrar u ocultar fruta
	void mostrar();
	// Renderizar imagen fruta
	void render();

};

