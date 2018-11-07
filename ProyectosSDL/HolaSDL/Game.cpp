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

	try {
		//Inicializacion de las texturas
		for (int i = 0; i < NUM_TEXTURES; i++) {
			texturas[i] = new Texture(renderer, (RUTA + atributos[i].nombre), atributos[i].row, atributos[i].col);
		}
	}
	catch(exception e){
		cout << "Fichero de imagen no encontrado";
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
	Vector2D posPaddle((WIN_WIDTH/2), WIN_HEIGHT*0.75);
	paddlecentro = new Paddle(posPaddle, largoP/4, largoP, origen, texturas[PaddleText]);

	//Ball
	Vector2D posBall(WIN_HEIGHT*0.75, WIN_WIDTH /2);
	ballpaddle = new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this);

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

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddlecentro->handleEvents(event);
	}
}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (numvidas > 0 && !exit && !mapa->nobloques()) {
		cout << "Numero de vidas:" << numvidas << endl;
		while (!exit && !mapa->nobloques() && ballpaddle->muerto()) {
			handleEvents();
			frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
			if (frameTime >= FRAME_RATE) {
				update(); // Actualiza el estado de todos los objetos del juego
				startTime = SDL_GetTicks();
			}
			render();
		}
		numvidas--;
	}
	if (numvidas == 0) {
		cout << "Has Muerto" << endl;
	}

}

void Game::update() {
	paddlecentro->update();
	ballpaddle->update();
}

Vector2D Game::collides(SDL_Rect dimball, Vector2D& vel) {
	Vector2D col(0, 0);
	Block* bloque = mapa->collides(dimball, vel, col);
	if (bloque != nullptr) {
		mapa->destroyblock(bloque);
	}
	else{
		col = paddlecentro->coll(dimball, vel);
	}
	return col;
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