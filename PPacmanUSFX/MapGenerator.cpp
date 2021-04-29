#include "MapGenerator.h"

MapGenerator::MapGenerator(int _anchoPantalla, int _altoPantalla)
{
	anchoPantalla = _anchoPantalla;
	altoPantalla = _altoPantalla;

	pacmanTexture = new Texture();
	pacmanTexture->loadFromImage(pathPacman);
	fantasma1Texture = new Texture();
	fantasma1Texture->loadFromImage(pathFantasma1);
	fantasma2Texture = new Texture();
	fantasma2Texture->loadFromImage(pathFantasma2);
	fantasma3Texture = new Texture();
	fantasma3Texture->loadFromImage(pathFantasma3);
	fantasma4Texture = new Texture();
	fantasma4Texture->loadFromImage(pathFantasma4);
	frutasTextures = new Texture();
	frutasTextures->loadFromImage(pathFrutas);
	coinTexture = new Texture();
	coinTexture->loadFromImage(pathCoin);
	wallTexture = new Texture();
	wallTexture->loadFromImage(pathWall);
	wallTexture2 = new Texture();
	wallTexture2->loadFromImage(pathWall2);
	wallTexture3 = new Texture();
	wallTexture3->loadFromImage(pathWall3);
	wallTexture4 = new Texture();
	wallTexture4->loadFromImage(pathWall4);
	wallTexture5 = new Texture();
	wallTexture5->loadFromImage(pathWall5);
	wallTexture6 = new Texture();
	wallTexture6->loadFromImage(pathWall6);
}

bool MapGenerator::load(string path)
{
	// Crea un flujo a un archivo
	fstream file;

	// Abre el archivo y verifica si tuvo exito
	file.open(path.c_str(), ios::in);

	// Retorna false si falla la apertura del archivo
	if (file.is_open() == false)
		return false;

	string line;

	int x = 0;
	int y = 0;

	// Lee el archivo linea por linea
	while (getline(file, line)) {
		// Divide la linea leida y la guarda en un vector de caracteres
		vector<char> chars(line.begin(), line.end());

		for (unsigned int x = 0; x < chars.size(); x++) {
			CommonGameProperties* newObject = nullptr;

			// Se verifica que letra es la que se lee y en funcion a ello se crea un tipo de objeto
			switch (chars[x])
			{

			case 'p':
				newObject = new Pacman(pacmanTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla, 5);
				newObject->setParametrosAnimacion(0);
				break;
			case 'b':
				newObject = new Fantasma(fantasma1Texture, 0, 0, 25, 25, anchoPantalla, altoPantalla, 3);
				newObject->setParametrosAnimacion(4);
				break;
			case 'f':
				newObject = new Fruta(frutasTextures, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(4);
				break;
			case 'q':
				newObject = new Wall(wallTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(0);
				break;
			case 'x':
				newObject = new Wall(wallTexture2, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(0);
				break;
			case 'y':
				newObject = new Wall(wallTexture3, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(0);
				break;
			case 'w':
				newObject = new Wall(wallTexture4, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(0);
				break;
			case 'z':
				newObject = new Wall(wallTexture5, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(0);
				break;
			case 'v':
				newObject = new Wall(wallTexture6, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(0);
				break;
			case '.':
				newObject = new Coin(coinTexture, x * 25, y * 25, 25, 25, anchoPantalla, altoPantalla);
				newObject->setParametrosAnimacion(10);
				break;
			
			}

			// If the object was created, add it to the vector
			if (newObject != nullptr)
				vectorObjetosJuego.push_back(newObject);
		}

		y++;
	}

	// Close the file
	file.close();

	return true;
}

void MapGenerator::populate(std::vector<CommonGameProperties*>& _vectorObjetosJuegoGM)
{
	for (unsigned int i = 0; i < vectorObjetosJuego.size(); i++) {
		_vectorObjetosJuegoGM.push_back(vectorObjetosJuego[i]);
	}
}