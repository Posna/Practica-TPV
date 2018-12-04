#pragma once
#include "ArkanoidError.h"

class FileNotFounError:public ArkanoidError
{
public:
	FileNotFounError(const string& m) : ArkanoidError("Error al leer el Mapa " + m + ". Se ha empezado una nueva partida") {}
};