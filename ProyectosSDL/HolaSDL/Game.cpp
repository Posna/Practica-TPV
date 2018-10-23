#include "Game.h"
#include <string>
#include "Texture.h"

using namespace std;
typedef unsigned int uint;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	//textura muro lados
	wallsides = new Texture(renderer, "..\\images\\side.png");
	
	//textura muro arriba
	walltop = new Texture(renderer, "..\\images\\topside.png");
	//uint anchoWT = walltop->getH();

	//textura bloques
	blocks = new Texture(renderer, "..\\images\\bricks.png", 2, 3);

	//muro izq
	Vector2D poswallleft(0, 0);
	wallleft = new Wall(poswallleft, anchoW, WIN_HEIGHT, wallsides);

	//muro drch
	Vector2D poswallright((WIN_WIDTH - anchoW), 0);
	wallright = new Wall(poswallright, anchoW, WIN_HEIGHT, wallsides);

	//muro arriba
	wallarriba = new Wall(poswallleft, WIN_WIDTH, anchoW, walltop);

	//mapa de bloques
	mapa = new BlockMap(blocks, "..\\mapas\\level01.ark");
}

void Game::render() const{
	SDL_RenderClear(renderer);
	wallleft->render();
	wallright->render();
	wallarriba->render();
	mapa->render();
	SDL_RenderPresent(renderer);
}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}