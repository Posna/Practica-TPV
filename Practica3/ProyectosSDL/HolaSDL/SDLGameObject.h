#pragma once
#include "GameObject.h"

class SDLGameObject: public GameObject {
protected:
	Vector2D pos;
	uint w;
	uint h;
	uint fX = 0;
	uint fY = 0;
	Texture* t = nullptr;
	SDL_Rect getRect();

public:
	virtual ~SDLGameObject() {}
	SDLGameObject(Vector2D pos, Texture* t, uint w, uint h, uint fX, uint fY) :
		pos(pos), t(t), w(w), h(h), fX(fX), fY(fY) {}
	SDLGameObject(const SDLGameObject &obj) {
		pos = obj.pos;
		w = obj.w;
		h = obj.h;
		fX = obj.fX;
		fY = obj.fY;
		t = obj.t;
	}
	virtual void render();
	virtual void update() {}
	virtual void handleEvents() {}

};