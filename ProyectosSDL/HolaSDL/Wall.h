#ifndef WALL
#define WALL
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"

typedef unsigned int uint;

class Wall {
private:
	Vector2D pos;
	uint w = 0;
	uint h = 0;
	Texture* t = nullptr;
public:
	Wall() {};
	Wall(Vector2D pos, uint w, uint h, Texture* t):
		pos(pos), h(h), w(w) {
		this->t = t;
	}
	Vector2D collWall(const SDL_Rect& ballRect, const Vector2D& ballVel);
	void render()const;
	bool enWall(Vector2D p);
};
#endif