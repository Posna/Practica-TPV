#pragma once
#ifndef ARKANOID_OBJECT
#define ARKANOID_OBJECT
#include "SDLGameObject.h"
#include "Vector2D.h"
#include <iostream>
#include <fstream>
#include "checkML.h"
#include <string>


class ArkanoidObject : public SDLGameObject {
public:
	ArkanoidObject(Vector2D pos, Texture* t, uint w, uint h, uint fX, uint fY) : SDLGameObject(pos, t, w, h, fX, fY) {}
	virtual void loadFromFile(ifstream& file);
	virtual void saveToFile(ofstream& file);
	
};
#endif