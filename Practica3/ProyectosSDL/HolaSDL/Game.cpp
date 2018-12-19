#include "Game.h"

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	//Inicializacion de las texturas
	for (int i = 0; i < NUM_TEXTURES; i++) {
		texturas[i] = new Texture(renderer, (RUTA + atributos[i].nombre), atributos[i].row, atributos[i].col);
	}

	maquinaEstados = new GameStateMachine();
	maquinaEstados->pushState(new MenuState(texturas[0], this));
	callPlayState();
}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit) {
		handleEvents();
		frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
		if (frameTime >= FRAME_RATE) {
			update(); // Actualiza el estado de todos los objetos del juego
			startTime = SDL_GetTicks();
		}
		render();
	}

}

void Game::render() {
	SDL_RenderClear(renderer);
	maquinaEstados->currentState()->render();
	SDL_RenderPresent(renderer);
}

void Game::update() {
	maquinaEstados->currentState()->update();

}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		maquinaEstados->currentState()->handleEvents(/*event*/);
	}

}

void Game::callPlayState() {
	maquinaEstados->changeState(new PlayState(texturas[0], this));
}

