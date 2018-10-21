#include "Game.h"
#include <string>
#include "Texture.h"
#include "Wall.h"

using namespace std;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";	Texture* wall = new Texture(renderer, "..\\images\\dog.png", 1, 1);
	Wall* wallsides = new Wall[2]()

}