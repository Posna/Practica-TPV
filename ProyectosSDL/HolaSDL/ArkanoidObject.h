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
	Texture* t = nullptr;
	SDL_Rect getRect();
public:
	ArkanoidObject(Vector2D pos, Texture* t, uint w, uint h) :
		pos(pos), t(t), w(w), h(h), veldir(Vector2D(0, 0)) {}
	ArkanoidObject(Vector2D pos, Texture* t, uint w, uint h, Vector2D veldir) :
		pos(pos), t(t), w(w), h(h), veldir(veldir) {}
	void loadFromFile();
	void saveToFile();

	/*Texture* getTexture();*/

};
#endif