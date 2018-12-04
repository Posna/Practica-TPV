#pragma once
#include "ArkanoidError.h"

class SDLError: public ArkanoidError
{
public:
	void SDL_GetError();
	void IMG_GetError();
	void TTF_GetError();
	SDLError(const string& m) : ArkanoidError(m) {};
};