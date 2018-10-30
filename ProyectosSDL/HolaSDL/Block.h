#ifndef BLOCK
#define BLOCK
#include <string>
#include "Vector2D.h"
#include "Texture.h"


class Block {
private:
	Vector2D pos;
	int color;
	uint w;
	uint h;
	uint fila;
	uint columna;
	Texture* textura = nullptr;
public:
	Block(Vector2D pos, int color, uint fila, uint columna, Texture* t, uint w, uint h) :
		pos(pos), color(color), fila(fila), columna(columna), textura(t), w(w), h(h) {}
	void render() const;
};
#endif