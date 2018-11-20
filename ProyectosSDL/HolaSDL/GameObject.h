#pragma once
#ifndef GAME_OBJECT
#define GAME_OBJECT
#include <string>
#include "Vector2D.h"
#include "Texture.h"

typedef unsigned int uint;

class GameObject {
private:


public:
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvents() = 0;
};
#endif