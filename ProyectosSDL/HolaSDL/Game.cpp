#include "Game.h"
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

	//Paddle
	Vector2D posPaddle((WIN_WIDTH / 2), WIN_HEIGHT*0.85);
	objetos.push_back(new Paddle(posPaddle, largoP / 4, largoP, origen, texturas[PaddleText]));

	//muro izq
	//objects[0] = new Wall(origen, texturas[SideText], anchoW, WIN_HEIGHT);
	objetos.push_back(new Wall(origen, texturas[SideText], anchoW, WIN_HEIGHT));

	//muro drch
	Vector2D poswallright((WIN_WIDTH - anchoW), 0);
	//objects[1] = (new Wall(poswallright, texturas[SideText], anchoW, WIN_HEIGHT));
	objetos.push_back(new Wall(poswallright, texturas[SideText], anchoW, WIN_HEIGHT));

	//muro arriba
	//objects[2] = (new Wall(origen, texturas[TopsideText], WIN_WIDTH, anchoW));
	objetos.push_back(new Wall(origen, texturas[TopsideText], WIN_WIDTH, anchoW));

	//mapa de bloques
	mapa = new BlockMap(texturas[BricksText], "..\\mapas\\level1.ark", this);
	objetos.push_back(mapa);

	//Ball
	Vector2D posBall(WIN_HEIGHT*0.75, WIN_WIDTH /2);
	//objects[3] = new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this);
	objetos.push_back(new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this));
	numBolas++;

	

}

void Game::render(){
	SDL_RenderClear(renderer);
	for (it = objetos.begin(); it != objetos.end(); ++it)
	{
		(*it)->render();
	}
	SDL_RenderPresent(renderer);
}

void Game::update() {
	for (it = objetos.begin(); it != objetos.end();)
	{
		auto next = it;
		++next;
		(*it)->update();
		it = next;
	}
	//paddlecentro->update();
	//objects[3]->update();
}

//Existe advance(iterator, numero de puestos)
//void Game::itMov(int num) {
//	it = objetos.begin();
//	for (int i = 0; i < num; i++) {
//		++it;
//	}
//}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (numvidas > 0 && !exit && numMapa != MAX_MAPAS+1) {
		cout << "Numero de vidas:" << numvidas << endl;
		//preguntar sobre la pelota y la muerte de la misma
		while (!exit && !mapa->nobloques() && hayBolas() && reward) {
			handleEvents();
			frameTime = SDL_GetTicks() - startTime; // Tiempo desde última actualización
			if (frameTime >= FRAME_RATE) {
				update(); // Actualiza el estado de todos los objetos del juego
				startTime = SDL_GetTicks();
			}
			render();
		}
		if (!hayBolas()) {
			numvidas--;
			resetBall();
		}
		if(mapa->nobloques()) {
			numMapa++;
			cargaNumMapa();
			resetBall();
		}if(numrewards > 0)
			eliminaRewards();
		reward = true;
	}
	if (numvidas == 0) {
		cout << "Has Muerto" << endl;
	}

}

void Game::handleEvents() {
	SDL_Event event;
	//saveGame("prueba");
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		static_cast<Paddle*>(objetos.front())->handleEvents(event);
		if (event.key.keysym.sym == SDLK_s)
			saveGame("prueba");
		if (event.key.keysym.sym == SDLK_r)
			loadGame("prueba");
	}
}

void Game::resetBall() {
	resetFirstReward();
	static_cast<Ball*>(*movObj)->ballIni();
}

void Game::saveGame(string name) {
	cout << "Escribe el nombre de la partida: ";
	cin >> name;
	it = objetos.begin();
	ofstream archivo;
	archivo.open(name + ".txt");
	archivo << numMapa << endl;
	for (ArkanoidObject* o : objetos) {
		o->saveToFile(archivo);
	}
	//mapa->saveToFile(archivo);
	archivo.close();
}

void Game::loadGame(string name) {
	it = objetos.begin();
	ifstream archivo;
	archivo.open(name + ".txt");
	archivo >> numMapa;
	for (ArkanoidObject* o : objetos) {
		o->loadFromFile(archivo);
	}
	archivo.close();
}

void Game::eliminaRewards(){
	it = objetos.begin();
	
	for (advance(it, 3 + NUM_MUROS); it != objetos.end(); ) {
		//auto aux = it;
		it = objetos.erase(it);
	}
	numRewards = 0;
}

//comprueba si en la lista hay alguna bola o no para poder continuar con el juego
bool Game::hayBolas() {
	resetFirstReward();
	return !static_cast<Ball*>(*movObj)->muerto();
}


//Comprueba si algun objeto(pelota o reward) esta por debajo o esta en colision con el paddle
int Game::CollDead(SDL_Rect p) {
	if (p.y < WIN_HEIGHT) {
		if (static_cast<Paddle*>(objetos.front())->inPaddle(p)) {
			return 1;
		}
		return 0;
	}
	else {
		return 2;
	}
}

void Game::eliminaObj(std::list<ArkanoidObject*>::iterator iterator) {
	//delete *iterator;
	//objetos.erase(iterator);
	it = iterator;
	objetos.erase(it);
	//delete *iterator;
	numRewards--;
}

void Game::cargaNumMapa() {
	char mapanum = numMapa + '0';
	string a = MAPAS + mapanum + ".ark";
	ifstream fich(a);
	mapa->leeMapa(fich);
	fich.close();
	it = objetos.begin();
	advance(it, 5);
	static_cast<Ball*>(*it)->ballIni();
}

Vector2D Game::wallColl(SDL_Rect dimball, const Vector2D& vel) {
	Vector2D col = { 0,0 };
	int i = 0;
	it = objetos.begin();
	++it;
	while(col.getX() == 0 && col.getY() == 0 && i < NUM_MUROS) {
		col = static_cast<Wall*>(*it)->collWall(dimball, vel); //cambiar este array por un iterador que apunte al primer muro y siga hasta el ultimo (NUM_MUROS)
		i++;
		++it;
	}
	return col;
}

Vector2D Game::collides(SDL_Rect dimball, const Vector2D& vel) {
	Vector2D col(0, 0);
	Block* bloque = mapa->collides(dimball, vel, col);
	if (bloque != nullptr) {
		if ((rand() % 100) < PROB_REWARD) {
			crearReward(bloque->getPos());
		}
		mapa->destroyblock(bloque);
	}
	else{
		col = static_cast<Paddle*>(objetos.front())->coll(dimball, vel);
	}
	if (col.getX() == 0 && col.getY() == 0)
		col = wallColl(dimball, vel);
	return col;
}

void Game::ultimoreward() {
	resetFirstReward();
	advance(movObj, numRewards);
}

void Game::resetFirstReward() {
	it = objetos.begin();
	movObj = it;
	advance(movObj, 2 + NUM_MUROS);
}

void Game::crearReward(Vector2D pos) {
	objetos.push_back(new Reward(pos, ballAA * 2.5, ballAA, texturas[RewardText], this));
	numRewards++;
	ultimoreward();
	static_cast<Reward*>(objetos.back())->addIt(movObj);	
}

void Game::tipoReward(int i) {
	if (i == 0) {
		reward = false;
		numMapa++;
		cargaNumMapa();
	}
	else if (i == 1) {
		static_cast<Paddle*>(objetos.front())->cambTam(2);
	}
	else if (i == 3) {
		static_cast<Paddle*>(objetos.front())->cambTam(0.5);
	}
	else {
		numvidas++;
	}
}

Game::~Game() {
	for (int i = 0; i < NUM_TEXTURES; i++) {delete texturas[i];}
	//for (int i = 0; i < NUM_MUROS; i++) { walls[i] = nullptr; }
	//delete mapa;
	/*for (it = objetos.begin(); it != objetos.end(); ++it)
	{
		delete (*it);
	}*/
	objetos.clear();
	//delete paddlecentro;
	//delete ballpaddle;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}