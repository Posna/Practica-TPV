#pragma once
#ifndef MOVING_OBJECT
#define MOVING_OBJECT
#include "ArkanoidObject.h"
#include "checkML.h"

class MovingObject : public ArkanoidObject {
protected:
	Vector2D veldir;
public:
	MovingObject(Vector2D pos, Texture* t, uint w, uint h, uint fX, uint fY, Vector2D veldir): ArkanoidObject(pos, t, w, h, fX, fY), veldir(veldir){}
	void saveToFile(ofstream& file);
	void loadFromFile(ifstream& file);
	virtual void update();
};
#endif