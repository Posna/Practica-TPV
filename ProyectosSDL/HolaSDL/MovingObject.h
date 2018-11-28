#pragma once
#ifndef MOVING_OBJECT
#define MOVING_OBJECT
#include "ArkanoidObject.h"
#include "Vector2D.h"

class MovingObject : public ArkanoidObject {
protected:
	Vector2D veldir;
public:
	MovingObject(Vector2D veldir) : veldir(veldir){}

	void saveToFile(s);
	void loadFromFile();
};
#endif