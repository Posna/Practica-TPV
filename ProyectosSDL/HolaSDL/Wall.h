#ifndef WALL
#define WALL
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "ArkanoidObject.h"
#include "checkML.h"

typedef unsigned int uint;

class Wall: public ArkanoidObject {
private:
	bool enWall(Vector2D p);
public:
	Wall(Vector2D pos, Texture* t, uint w, uint h) : ArkanoidObject(pos, t, w, h, 0, 0) {};
	Vector2D collWall(const SDL_Rect& ballRect, const Vector2D& ballVel);
	virtual void handleEvents() {};
};
#endif