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
#include "SDLError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
#include "MenuButton.h"

const enum TexturesName{BallText, PaddleText, BricksText, SideText, TopsideText, RewardText, LoadText, StartText};
const enum WallName {WallLeft, WallUp, WallRight};
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 8;
const uint anchoW = 20;
const string RUTA = "..\\images\\";
const string MAPAS = "..\\mapas\\level";
const uint32_t FRAME_RATE = 5;
const uint ballAA = 18;
const uint largoP = 100;
const int NUM_MUROS = 3;
const int PROB_REWARD = 20;
const int MAX_MAPAS = 3;



class Game {
private:
	int numvidas = 3;
	SDL_Window * window = nullptr;
	SDL_Renderer* renderer = nullptr;
	list<ArkanoidObject*> objetos;
	std::list<ArkanoidObject*>::iterator it;
	std::list<ArkanoidObject*>::iterator movObj;
	BlockMap* mapa = nullptr;
	Button* start;
	Button* load;
	bool exit = false;
	bool reward = true;
	int numBolas = 0;
	int numRewards = 0;
	int numMapa = 1;
	int puntuacion = 0;
	struct TexturesAtributes {
		string nombre;
		int row;
		int col;
	};
	Texture* texturas[NUM_TEXTURES];
	TexturesAtributes atributos[NUM_TEXTURES] = { "ball.png", 1, 1, "paddle.png", 1, 1, "bricks.png", 2, 3, "side.png", 1, 1, "topside.png", 1, 1, "rewards.png", 10, 8, "Load_Game_Sprite.png", 1, 1, "Start_Game_Sprite.png", 1, 1};
	void saveGame();
	void loadGame(string name);
	void resetFirstReward();
	void ultimoreward();
	void resetBall();
	bool hayBolas();
public:
	Game();
	~Game();
	int CollDead(SDL_Rect p);
	void run();
	void showmenu();// , TTF_Font* font);
	void render();
	void update();
	Vector2D wallColl(SDL_Rect dimball, const Vector2D& vel);
	void eliminaRewards();
	void muestraPuntuacion(int suma);
	void handleEvents();
	Vector2D collides(SDL_Rect dimball, const Vector2D& vel);
	void crearReward(Vector2D pos);
	void cargaNumMapa();
	void eliminaObj(std::list<ArkanoidObject*>::iterator iterator);
	void tipoReward(int i);
};
#endif