#ifndef GAME
#define GAME
#include "ArkanoidObject.h"
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Ball.h"
#include "Paddle.h"
#include "checkML.h"
#include <list>
#include <iterator>
#include <fstream>
#include <string>
#include "Reward.h"

const enum TexturesName{BallText, PaddleText, BricksText, SideText, TopsideText, RewardText};
const enum WallName {WallLeft, WallUp, WallRight};
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 6;
const uint anchoW = 20;
const string RUTA = "..\\images\\";
const string MAPAS = "..\\mapas\\level";
const uint32_t FRAME_RATE = 5;
const uint ballAA = 18;
const uint largoP = 100;
const int NUM_MUROS = 3;
const int MAX_MAPAS = 3;



class Game {
private:
	int numvidas = 3;
	SDL_Window * window = nullptr;
	SDL_Renderer* renderer = nullptr;
	list<ArkanoidObject*> objetos;
	std::list<ArkanoidObject*>::iterator it;
	//std::list<ArkanoidObject*>::iterator movObj;
	//Wall* walls [NUM_MUROS];
	BlockMap* mapa = nullptr;
	//Paddle* paddlecentro = nullptr;
	//Ball* ballpaddle = nullptr;
	bool exit = false;
	bool reward = true;
	//ArkanoidObject* objects [15];
	int numBolas = 0;
	int numRewards = 0;
	int numMapa = 1;
	struct TexturesAtributes {
		string nombre;
		int row;
		int col;
	};
	Texture* texturas[NUM_TEXTURES];
	TexturesAtributes atributos[NUM_TEXTURES] = { "ball.png", 1, 1, "paddle.png", 1, 1, "bricks.png", 2, 3, "side.png", 1, 1, "topside.png", 1, 1, "rewards.png", 10, 8};
	void saveGame(string name);
	void loadGame(string name);
	void itMov(int num);
	bool hayBolas();
public:
	Game();
	~Game();
	int CollDead(SDL_Rect p);
	void run();
	void render();
	void update();
	Vector2D wallColl(SDL_Rect dimball, const Vector2D& vel);
	void handleEvents();
	Vector2D collides(SDL_Rect dimball, const Vector2D& vel);
	void crearReward(Vector2D pos);
	void cargaNumMapa();
	void eliminaObj(std::list<ArkanoidObject*>::iterator iterator);
	void tipoReward(int i);
};
#endif