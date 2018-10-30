#include "Game.h"
#include <string>
#include "Texture.h"

using namespace std;
typedef unsigned int uint;

Game::Game() {
	Vector2D origen(0, 0);

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	//Inicializacion de las texturas
	for (int i = 0; i < NUM_TEXTURES; i++) {
		texturas[i] = new Texture(renderer, (RUTA + atributos[i].nombre), atributos[i].row, atributos[i].col);
	}
	//muro izq
	wallleft = new Wall(origen, anchoW, WIN_HEIGHT, texturas[SideText]);

	//muro drch
	Vector2D poswallright((WIN_WIDTH - anchoW), 0);
	wallright = new Wall(poswallright, anchoW, WIN_HEIGHT, texturas[SideText]);

	//muro arriba
	wallarriba = new Wall(origen, WIN_WIDTH, anchoW, texturas[TopsideText]);

	//mapa de bloques
	mapa = new BlockMap(texturas[BricksText], "..\\mapas\\level01.ark");

	//Paddle
	Vector2D posPaddle(WIN_HEIGHT*0.75, WIN_WIDTH/2);
	paddlecentro = new Paddle(posPaddle, 10, 60, origen, texturas[PaddleText]);

	//Ball
	Vector2D posBall(WIN_HEIGHT*0.75, WIN_WIDTH /2);
	ballpaddle = new Ball(posBall, 10, 10, origen, texturas[BallText]);

}

void Game::render() const{
	SDL_RenderClear(renderer);
	wallleft->render();
	wallright->render();
	wallarriba->render();
	mapa->render();
	paddlecentro->render();
	ballpaddle->render();
	SDL_RenderPresent(renderer);
}

Game::~Game() {
	for (int i = 0; i < NUM_TEXTURES; i++) {delete texturas[i];}
	delete wallleft;
	delete wallright;
	delete mapa;
	delete wallarriba;
	delete paddlecentro;
	delete ballpaddle;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}