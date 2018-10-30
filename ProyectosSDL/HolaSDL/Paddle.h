#ifndef PADDLE
#define PADDLE
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include "Vector2D.h"

class Paddle {
private:
	Vector2D pos;
	int alt;
	int anch;
	Vector2D veldir;

	Texture* p = nullptr;

public:

	Paddle(Vector2D pos, int alt, int anch,  Vector2D veldir, Texture* p) :
		pos(pos), alt(alt), anch(anch), veldir(veldir), p(p){}
	void render();


};
#endif
