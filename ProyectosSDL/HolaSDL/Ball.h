#ifndef BALL
#define BALL
#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"

class Ball {
private:
	Vector2D pos;
	int anch = 0;
	int alt = 0;
	Vector2D veldir;
	

	Texture* b = nullptr;
public:

	Ball(Vector2D pos, int anch, int alt, Vector2D veldir, Texture* p) :
		pos(pos), alt(alt), anch(anch), veldir(veldir), b(p){}
	~Ball();
	void render();

};
#endif
