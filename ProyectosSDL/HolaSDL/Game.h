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
#include "checkML.h"

const enum TexturesName{BallText, PaddleText, BricksText, SideText, TopsideText};
const enum WallName {WallLeft, WallUp, WallRight};
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 5;
const uint anchoW = 20;
const string RUTA = "..\\images\\";
const uint32_t FRAME_RATE = 5;
const uint ballAA = 18;
const uint largoP = 100;
const int NUM_MUROS = 3;



class Game {
private:
	int numvidas = 3;
	SDL_Window * window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Wall* walls [NUM_MUROS];
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
	Vector2D wallColl(SDL_Rect dimball, const Vector2D& vel);
	void handleEvents();
	Vector2D collides(SDL_Rect dimball, const Vector2D& vel);
};
#endif