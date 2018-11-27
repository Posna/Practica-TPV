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
	objects[0] = new Wall(origen, texturas[SideText], anchoW, WIN_HEIGHT);
	objetos.push_back(new Wall(origen, texturas[SideText], anchoW, WIN_HEIGHT));

	//muro drch
	Vector2D poswallright((WIN_WIDTH - anchoW), 0);
	objects[1] = (new Wall(poswallright, texturas[SideText], anchoW, WIN_HEIGHT));
	objetos.push_back(new Wall(poswallright, texturas[SideText], anchoW, WIN_HEIGHT));

	//muro arriba
	objects[2] = (new Wall(origen, texturas[TopsideText], WIN_WIDTH, anchoW));
	objetos.push_back(new Wall(origen, texturas[TopsideText], WIN_WIDTH, anchoW));

	//mapa de bloques
	mapa = new BlockMap(texturas[BricksText], "..\\mapas\\level01.ark");
	objetos.push_back(new BlockMap(texturas[BricksText], "..\\mapas\\level01.ark"));

	//Paddle
	Vector2D posPaddle((WIN_WIDTH/2), WIN_HEIGHT*0.75);
	paddlecentro = new Paddle(posPaddle, largoP/4, largoP, origen, texturas[PaddleText]);
	objetos.push_back(new Paddle(posPaddle, largoP / 4, largoP, origen, texturas[PaddleText]));

	//Ball
	Vector2D posBall(WIN_HEIGHT*0.75, WIN_WIDTH /2);
	objects[3] = new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this);
	objetos.push_back(new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this));
}

void Game::render(){
	SDL_RenderClear(renderer);
	it = objetos.begin();
	//for (int i = 0; i < NUM_MUROS; i++) {
	//	walls[i]->render();
	//}
	for (ArkanoidObject* o: objetos)
	{
		o->render();
	}
	//for (int i = 0; i < 4; i++) {
	//	objects[i]->render();
	//}
	//mapa->render();
	//paddlecentro->render();
	////ballpaddle->render();
	SDL_RenderPresent(renderer);
}

void Game::update() {
	paddlecentro->update();
	objects[3]->update();
}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (numvidas > 0 && !exit && !mapa->nobloques()) {
		cout << "Numero de vidas:" << numvidas << endl;
		while (!exit && !mapa->nobloques() && static_cast<Ball*>(objects[3])->muerto()) {
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

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddlecentro->handleEvents(event);
	}
}


Vector2D Game::wallColl(SDL_Rect dimball, const Vector2D& vel) {
	Vector2D col = { 0,0 };
	int i = 0;
	while(col.getX() == 0 && col.getY() == 0 && i < 3) {
		col = static_cast<Wall*>(objects[i])->collWall(dimball, vel);
		i++;
	}
	return col;
}

Vector2D Game::collides(SDL_Rect dimball, const Vector2D& vel) {
	Vector2D col(0, 0);
	Block* bloque = mapa->collides(dimball, vel, col);
	if (bloque != nullptr) {
		mapa->destroyblock(bloque);
	}
	else{
		col = paddlecentro->coll(dimball, vel);
	}
	if (col.getX() == 0 && col.getY() == 0)
		col = wallColl(dimball, vel);
	return col;
}

Game::~Game() {
	for (int i = 0; i < NUM_TEXTURES; i++) {delete texturas[i];}
	for (int i = 0; i < 4; i++) { delete objects[i];}
	delete mapa;
	//delete paddlecentro;
	//delete ballpaddle;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}