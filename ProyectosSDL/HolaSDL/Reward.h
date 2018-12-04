#pragma once

#include "MovingObject.h"
#include <list>
#include "checkML.h"
#include <stdlib.h>
#include <iterator>

const int numrewards = 4;

class Game;

class Reward : public MovingObject {
private:
	Game* game = nullptr;
	std::list<ArkanoidObject*>::iterator it;
	int tipoR = 0;
public:
	Reward(Vector2D pos, uint w, uint h, Texture* t, Game* game) : 
		MovingObject(pos, t, w, h, 0, 0, Vector2D(0, 1)), game(game) {
		tipoR = rand() % numrewards;
		fY = tipoR;
	}
	void addIt(std::list<ArkanoidObject*>::iterator iterator) { it = iterator; }
	virtual void render();
	virtual void update();

	void col();
	void efecto();
};