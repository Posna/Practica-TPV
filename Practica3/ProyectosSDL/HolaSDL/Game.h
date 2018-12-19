#pragma once
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <list>
#include <iterator>
#include <fstream>
#include <string>
#include <stack>

#include "GameStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const string RUTA = "..\\images\\";
const int NUM_TEXTURES = 1;
const uint FRAME_RATE = 5;

class Game {
private:
	int numvidas = 3;
	bool exit = false;
	bool reward = true;
	int numBolas = 0;
	int numRewards = 0;
	int numMapa = 1;
	int puntuacion = 0;

	GameStateMachine* maquinaEstados;

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	struct TexturesAtributes {
		string nombre;
		int row;
		int col;
	};
	Texture* texturas[NUM_TEXTURES];
	TexturesAtributes atributos[NUM_TEXTURES] = { "ball.png", 1, 1 };// , "paddle.png", 1, 1, "bricks.png", 2, 3, "side.png", 1, 1, "topside.png", 1, 1, "rewards.png", 10, 8, "Load_Game_Sprite.png", 1, 1, "Start_Game_Sprite.png", 1, 1


	/*void saveGame();
	void loadGame(string name);*/
public:
	Game();
	~Game();

	void callPlayState();
	void callPauseState();
	void callEndState();



	void run();
	void render();
	void update();
	void handleEvents();
};