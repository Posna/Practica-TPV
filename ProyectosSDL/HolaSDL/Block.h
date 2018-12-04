#ifndef BLOCK
#define BLOCK
#include <string>
#include "Vector2D.h"
#include "Texture.h"
#include "checkML.h"
#include "ArkanoidObject.h"

class Block: public ArkanoidObject{
private:
	int color;
	uint fila;
	uint columna;
	//Texture* textura = nullptr;
public:
	Block(Vector2D pos, int color, uint fila, uint columna, Texture* t, uint w, uint h): ArkanoidObject(pos, t, w, h, (color-1)%3, (color - 1) % 2),
		color(color), fila(fila), columna(columna){}
	int getH();
	int getW();
	int getY();
	int getX();
	int getF();
	int getC();
	int getColor();
	Vector2D getPos();
};
#endif