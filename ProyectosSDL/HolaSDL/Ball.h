#ifndef BALL
#define BALL
#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"

class Game;

class Ball {
private:
	Vector2D posini;
	Vector2D pos;
	int anch = 0;
	int alt = 0;
	Vector2D veldir;
	Vector2D veldirini;
	Game* game;
	

	Texture* b = nullptr;
public:

	Ball(Vector2D pos, int anch, int alt, Vector2D veldir, Texture* p, Game* game) :
		pos(pos), alt(alt), anch(anch), veldir(veldir), b(p), game(game) {
		posini = pos;
		veldirini = veldir;
	}
	void render();
	void update();
	void coll();
	bool muerto();
	Vector2D collWall();
	SDL_Rect dimball();
};
#endif
