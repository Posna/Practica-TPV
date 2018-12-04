#ifndef BALL
#define BALL
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "MovingObject.h"

class Game;

class Ball: public MovingObject {
private:
	Vector2D posini;
	/*Vector2D pos;
	int anch = 0;
	int alt = 0;
	Vector2D veldir;*/
	Vector2D veldirini;
	Game* game;
	

	//Texture* b = nullptr;
public:

	Ball(Vector2D pos, uint w, uint h, Vector2D veldir, Texture* t, Game* game) :
		MovingObject(pos, t, w, h, 0, 0, veldir), game(game) {
		posini = pos;
		veldirini = veldir;
	}
	//virtual void render();
	virtual void update();
	virtual void handleEvents() {};
	void coll();
	void ballIni();
	bool muerto();
	SDL_Rect dimball();
};
#endif
