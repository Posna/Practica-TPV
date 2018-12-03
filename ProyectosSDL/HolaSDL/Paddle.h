#ifndef PADDLE
#define PADDLE
#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Vector2D.h"
#include "MovingObject.h"

const int velocity = 2;

class Paddle: public MovingObject {
private:
	//Texture* p = nullptr;
	bool enPaddle = false; //false si la pelota no esta dentro del paddle
public:
	Paddle(Vector2D pos, uint h, uint w,  Vector2D veldir, Texture* t) : MovingObject(pos, t, w, h, 0, 0, veldir){}
	virtual void update();
	virtual void handleEvents(SDL_Event& event);
	Vector2D coll(SDL_Rect dimball, Vector2D vel);
	bool inPaddle(SDL_Rect p);
	void cambTam(double cant);
};
#endif
