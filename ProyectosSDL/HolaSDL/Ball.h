#ifndef BALL
#define BALL
#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"

class Game;

class Ball {
private:
	Vector2D pos;
	int anch = 0;
	int alt = 0;
	Vector2D veldir;
	Game* game;
	

	Texture* b = nullptr;
public:

	Ball(Vector2D pos, int anch, int alt, Vector2D veldir, Texture* p, Game* game) :
		pos(pos), alt(alt), anch(anch), veldir(veldir), b(p), game(game){}
	void render();
	void update();
	void coll();
	Vector2D collWall();
	SDL_Rect dimball();
};
#endif
