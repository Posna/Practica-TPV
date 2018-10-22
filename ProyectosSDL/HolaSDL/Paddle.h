#pragma once
#include <iostream>
#include <string>
#ifndef PADDLE
#define PADDLE
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include "Vector2D.h"

class Paddle {
private:
	Vector2D pos;
	int alt;
	int anch;
	Vector2D dir;
	int x;
	int y;
	Vector2D vel;

	Texture* p = nullptr;

public:

	Paddle(Vector2D pos, int alt, int anch, Vector2D dir, int x, int y, Vector2D vel, Texture* p) :
		pos(pos), alt(alt), anch(anch), dir(dir), x(x), y(y), vel(vel) {}
	~Paddle();
	void render();


};
#endif
