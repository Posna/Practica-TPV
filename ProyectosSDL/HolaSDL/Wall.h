#ifndef WALL
#define WALL
#include <string>
#include "Vector2D.h"
#include "Texture.h"

typedef unsigned int uint;

class Wall {
private:
	Vector2D pos;
	uint w = 0;
	uint h = 0;
	Texture* t = nullptr;
public:
	Wall(Vector2D pos, uint w, uint h, Texture* t):
		pos(pos), h(h), w(w) {
		this->t = t;
	}
	~Wall();
	void render();
};
#endif