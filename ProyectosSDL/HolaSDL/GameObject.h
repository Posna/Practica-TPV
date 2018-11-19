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
	void render(Texture* t, SDL_Rect desRect) const;
	void update(Vector2D& pos, const Vector2D& veldir);
	void handleEvents(SDL_Event& event);
};
#endif