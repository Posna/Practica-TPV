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
const string TextureAtributes[NUM_TEXTURES] = { "ball.png", "paddle.png", "bricks.png", "side.png", "topside.png" };
const uint anchoW = 20;



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
	Texture** texturas = new Texture*[NUM_TEXTURES];
	Texture* blocks = nullptr;
	Texture* wallsides = nullptr;
	Texture* walltop = nullptr;
	Texture* paddleRend = nullptr;
	Texture* ballRend = nullptr;

public:
	Game();
	~Game();
	void run();
	void render() const;
	void update();
	void handleEvents();
};
#endif