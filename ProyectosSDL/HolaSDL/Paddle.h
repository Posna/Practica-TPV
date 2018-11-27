#ifndef PADDLE
#define PADDLE
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include "checkML.h"
#include "Vector2D.h"
#include "ArkanoidObject.h"

const int velocity = 2;

class Paddle: public ArkanoidObject {
private:
	Vector2D veldir;
	Texture* p = nullptr;

public:

	Paddle(Vector2D pos, uint h, uint w,  Vector2D veldir, Texture* t) : ArkanoidObject(pos, t, w, h, 0, 0),
	veldir(veldir), p(p) {}
	void update();
	void handleEvents(SDL_Event& event);
	Vector2D coll(SDL_Rect dimball, Vector2D vel);


};
#endif
