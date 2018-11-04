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
	Vector2D normal;
	Texture* p = nullptr;

public:

	Paddle(Vector2D pos, int alt, int anch,  Vector2D veldir, Texture* p) :
		pos(pos), alt(alt), anch(anch), veldir(veldir), p(p) {
		normal = Vector2D(0, -1);
	}
	void render();
	void update();
	void handleEvents(SDL_Event& event);


};
#endif
