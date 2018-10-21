#pragma once
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;
const int NUM_TEXTURES = 3;

class Game {
private:
	SDL_Window * window = nullptr;
	SDL_Renderer* renderer = nullptr;

	bool exit = false;
	Texture* textureDog = nullptr;

public:
	Game();
	~Game();
	void run();
	void render() const;
	void update();
	void handleEvents();
};