#pragma once
#include "ArkanoidError.h"

class FileNotFoundError:public ArkanoidError
{
public:
	FileNotFoundError(const string& m) : ArkanoidError("Error al leer el Mapa " + m + ". Se ha empezado una nueva partida") {}
};