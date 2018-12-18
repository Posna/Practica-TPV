#include "Game.h"
#include "Texture.h"


using namespace std;
typedef unsigned int uint;

Game::Game() {
	Vector2D origen(0, 0);

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw SDLError("Error loading the SDL window or renderer");

	try {
		//Inicializacion de las texturas
		for (int i = 0; i < NUM_TEXTURES; i++) {
			texturas[i] = new Texture(renderer, (RUTA + atributos[i].nombre), atributos[i].row, atributos[i].col);
		}
	}
	catch(FileNotFoundError& e){
		cout << e.what() << endl;
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
	mapa = new BlockMap(texturas[BricksText], (MAPAS + to_string(numMapa) + ".ark"), this);
	objetos.push_back(mapa);

	//Ball
	Vector2D posBall(WIN_HEIGHT*0.75, WIN_WIDTH /2);
	//objects[3] = new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this);
	objetos.push_back(new Ball(posBall, ballAA, ballAA, Vector2D(0, -1), texturas[BallText], this));
	numBolas++;

	//Buttons
	int w = 300; int h = 100;
	start = new Button(Vector2D((WIN_WIDTH / 2) - (w / 2), WIN_HEIGHT / 3), texturas[StartText], w, h, 0, 0);
	load = new Button(Vector2D((WIN_WIDTH / 2) - (w / 2), WIN_HEIGHT * 2 / 3), texturas[LoadText], w, h, 0, 0);

	maquinaEstados = new GameStateMachine();
}
//
//
// METODOS RELACIONADOS CON EL JUEGO
//
//

void Game::render(){
	SDL_RenderClear(renderer);
	/*for (it = objetos.begin(); it != objetos.end(); ++it)
	{
		(*it)->render();
	}*/
	maquinaEstados->currentState()->render();

	SDL_RenderPresent(renderer);
}

void Game::update() {
	/*for (it = objetos.begin(); it != objetos.end();)
	{
		auto next = it;
		++next;
		(*it)->update();
		it = next;
	}*/
	maquinaEstados->currentState()->update();
}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (numvidas > 0 && !exit && numMapa < MAX_MAPAS+1) {
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
			muestraPuntuacion(100);
		}if(numrewards > 0)
			eliminaRewards();
		static_cast<Paddle*>(objetos.front())->resetSize();
		reward = true;
	}
	if (numvidas == 0) {
		cout << "Has Muerto" << endl;
	}

}

//muestra el menu del juego
void Game::showmenu() {
	bool fuera = false;
	while (!fuera) {
		SDL_RenderClear(renderer);
		start->render();
		load->render();
		SDL_RenderPresent(renderer);
		if (start->clicked()) {
			fuera = true;
		}
		if (load->clicked()) {
			string name;
			cout << "Nombre de la partida: ";
			cin >> name;
			loadGame(name);
			fuera = true;
		}
	}
}

//carga el siguiente mapa que toque
void Game::cargaNumMapa() {
	//char mapanum = numMapa + '0';
	string a = MAPAS + to_string(numMapa) + ".ark";
	ifstream fich(a);
	mapa->vaciaMapa();
	mapa->leeMapa(fich);
	fich.close();
	it = objetos.begin();
	advance(it, 5);
	static_cast<Ball*>(*it)->ballIni();
}


void Game::muestraPuntuacion(int suma) {
	puntuacion += suma;
	cout << "Puntuacion: " << to_string(puntuacion) << endl;
}


void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		static_cast<Paddle*>(objetos.front())->handleEvents(event);
		if (event.type == SDL_KEYUP) {
			if(event.key.keysym.sym == SDLK_s)
				saveGame();
		}
	}
}

void Game::saveGame() {
	string name;
	cout << "Escribe el nombre de la partida: ";
	cin >> name;
	it = objetos.begin();
	ofstream archivo;
	archivo.open(name + ".txt");
	archivo << numMapa << " " << puntuacion << endl;
	for (ArkanoidObject* o : objetos) {
		o->saveToFile(archivo);
	}
	archivo.close();
}

void Game::loadGame(string name) {
	it = objetos.begin();
	mapa->vaciaMapa();
	ifstream archivo;
	archivo.open(name + ".txt");
	try {
		if (!archivo.is_open()) {
			throw FileNotFoundError(name);
		}
		archivo >> numMapa >> puntuacion;
		for (ArkanoidObject* o : objetos) {
			o->loadFromFile(archivo);
		}
	}
	catch(FileNotFoundError& e){
		cout << e.what() << endl;
		archivo.close();
	}
}

//
//
// METODOS RELACIONADOS CON LA PELOTA
//
//

void Game::resetBall() {
	resetFirstReward();
	static_cast<Ball*>(*movObj)->ballIni();
}

//comprueba si en la lista hay alguna bola o no para poder continuar con el juego
bool Game::hayBolas() {
	resetFirstReward();
	return !static_cast<Ball*>(*movObj)->muerto();
}

//
//
// METODOS RELACIONADOS CON LOS REWARDS
//
//

void Game::eliminaRewards(){
	it = objetos.begin();
	
	for (advance(it, 3 + NUM_MUROS); it != objetos.end();) {
		rewardElimina.push_back(*it);
		it = objetos.erase(it);
	}
	for (ArkanoidObject* o : rewardElimina)
	{
		delete o;
	}
	rewardElimina.clear();
	numRewards = 0;
}

//elimina un rewards de la lista principal y lo envia a la lista de ser eliminado
void Game::eliminaObj(std::list<ArkanoidObject*>::iterator iterator) {
	it = iterator;
	rewardElimina.push_back(*iterator);
	objetos.erase(it);
	numRewards--;
}

//mueve un iterador a la posicion en la que se encuentra el ultimo reward
void Game::ultimoreward() {
	resetFirstReward();
	advance(movObj, numRewards);
}

//mueve el iterador hasta la posicion del primer reward
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

//segun un numero dado aleatoriamente cuando se crea el reward, se le asocia
//una funcionalidad que se aplica cuando se llama a este metodo
void Game::tipoReward(int i) {
	static_cast<Paddle*>(objetos.front())->resetSize();
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
	else if (i == 2){
		numvidas++;
		cout << "Numero de vidas:" << numvidas << endl;
	}
}

//
//
// METODOS RELACIONADOS CON LAS COLISIONES
//
//



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

//comprueba la colision con los muros
Vector2D Game::wallColl(SDL_Rect dimball, const Vector2D& vel) {
	Vector2D col = { 0,0 };
	int i = 0;
	it = objetos.begin();
	++it;
	while(col.getX() == 0 && col.getY() == 0 && i < NUM_MUROS) {
		col = static_cast<Wall*>(*it)->collWall(dimball, vel); 
		i++;
		++it;
	}
	return col;
}

//comprueba la colision de la bola con cualquier otro objeto y devuelve un 
//vector con el cual se hara una reflexion
Vector2D Game::collides(SDL_Rect dimball, const Vector2D& vel) {
	Vector2D col(0, 0);
	Block* bloque = mapa->collides(dimball, vel, col);
	if (bloque != nullptr) {
		if ((rand() % 100) < PROB_REWARD) {
			crearReward(bloque->getPos());
		}
		muestraPuntuacion(10);
		mapa->destroyblock(bloque);
	}
	else{
		col = static_cast<Paddle*>(objetos.front())->coll(dimball, vel);
	}
	if (col.getX() == 0 && col.getY() == 0)
		col = wallColl(dimball, vel);
	return col;
}




Game::~Game() {
	for (int i = 0; i < NUM_TEXTURES; i++) {delete texturas[i];}
	for (it = objetos.begin(); it!=objetos.end();it++)
	{
		delete (*it);
	}
	for (it = rewardElimina.begin(); it != rewardElimina.end(); it++)
	{
		delete (*it);
	}

	delete start;
	delete load;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}