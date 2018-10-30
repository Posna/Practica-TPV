#ifndef GAME
#define GAME
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Ball.h"
#include "Paddle.h"

const enum TexturesName{BallText, PaddleText, BricksText, SideText, TopsideText};
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 5;
const uint anchoW = 20;
const string RUTA = "..\\images\\";



class Game {
private:
	SDL_Window * window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Wall* wallleft = nullptr;
	Wall* wallright = nullptr;
	Wall* wallarriba = nullptr;
	BlockMap* mapa = nullptr;
	Paddle* paddlecentro = nullptr;
	Ball* ballpaddle = nullptr;
	bool exit = false;
	struct TexturesAtributes {
		string nombre;
		int row;
		int col;
	};
	Texture* texturas[NUM_TEXTURES];
	TexturesAtributes atributos[NUM_TEXTURES] = { "ball.png", 1, 1, "paddle.png", 1, 1, "bricks.png", 2, 3, "side.png", 1, 1, "topside.png", 1, 1};

public:
	Game();
	~Game();
	void run();
	void render() const;
	void update();
	void handleEvents();
};
#endif