#ifndef WALL
#define WALL
#include <string>
#include "Vector2D.h"
#include "Texture.h"

class Wall {
private:
	Vector2D pos;
	int w = 0;
	int h = 0;
	Texture* t = nullptr;
public:
	Wall(Vector2D pos, int w, int h, Texture* t) :
		pos(pos), h(h), w(w), t(t) {}
	~Wall();
	void render();
};
#endif