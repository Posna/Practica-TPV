#pragma once
#include "ArkanoidError.h"

class SDLError: public ArkanoidError
{
public:
	const char* SDLGetError() { return "Error en libreria SDL"; }
	const char* IMGGetError() { return "Error sobre imagen"; }
	SDLError(const string& m) : ArkanoidError(m) {};
};