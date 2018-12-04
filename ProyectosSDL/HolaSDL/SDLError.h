#pragma once
#include "ArkanoidError.h"

class SDLError: public ArkanoidError
{
public:
	//const char* SDL_GetError() { return "Error en libreria SDL"; }
	//const char* IMG_GetError() { return "Error sobre imagen"; }
	SDLError(const string& m) : ArkanoidError(m) {};
};