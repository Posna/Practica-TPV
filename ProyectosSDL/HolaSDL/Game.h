#ifndef GAME
#define GAME
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Wall.h"
#include "BlocksMap.h"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 3;
const uint anchoW = 20;



class Game {
private:
	SDL_Window * window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Wall* wallleft = nullptr;
	Wall* wallright = nullptr;
	Wall* wallarriba = nullptr;
	BlockMap* mapa = nullptr;
	bool exit = false;
	Texture* blocks = nullptr;
	Texture* wallsides = nullptr;
	Texture* walltop = nullptr;

public:
	Game();
	~Game();
	void run();
	void render() const;
	void update();
	void handleEvents();
};
#endif