#include "Game.h"
#include <string>
#include "Texture.h"
#include "Wall.h"

using namespace std;
typedef unsigned int uint;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	//textura muro lados
	wallsides = new Texture(renderer, "..\\images\\side.png");
	uint anchoWS = wallsides->getW();

	//textura muro arriba
	walltop = new Texture(renderer, "..\\images\\topside.png");
	uint anchoWT = walltop->getH();

	//muro izq
	Vector2D poswallleft(0, 0);
	wallleft = new Wall(poswallleft, anchoWS, WIN_HEIGHT, wallsides);

	//muro drch
	Vector2D poswallright((WIN_WIDTH - anchoWS), 0);
	wallright = new Wall(poswallright, anchoWS, WIN_HEIGHT, wallsides);

	//muro arriba
	wallarriba = new Wall(poswallleft, WIN_WIDTH, anchoWT, walltop);
}

void Game::render() const{
	SDL_RenderClear(renderer);
	wallleft->render();
	wallright->render();
	wallarriba->render();
	SDL_RenderPresent(renderer);
}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}