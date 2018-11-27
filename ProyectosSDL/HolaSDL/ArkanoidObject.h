#pragma once
#ifndef ARKANOID_OBJECT
#define ARKANOID_OBJECT
#include "GameObject.h"
#include "Vector2D.h"

const string NAME_FILE; //poner nombre del archivo 

class ArkanoidObject : public GameObject {
protected:
	Vector2D veldir;
	Vector2D pos;
	uint w;
	uint h;
	uint fX = 0;
	uint fY = 0;
	Texture* t = nullptr;
	SDL_Rect getRect();
public:
	ArkanoidObject(Vector2D pos, Texture* t, uint w, uint h, uint fX, uint fY) :
		pos(pos), t(t), w(w), h(h), veldir(Vector2D(0, 0)), fX(fX), fY(fY) {}
	void loadFromFile();
	void saveToFile();
	virtual void render();
	virtual void update() {}
	virtual void handleEvents() {}
};
#endif