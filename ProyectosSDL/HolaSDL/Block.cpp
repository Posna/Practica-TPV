#include "Block.h"
#include <string>

using namespace std;

void Block::render() const{
	SDL_Rect destRect;
	destRect.w = this->w;
	destRect.h = this->h;
	destRect.x = this->pos.getX();
	destRect.y = this->pos.getY();
	textura->renderFrame(destRect, (color-1)%2, (color-1)%3);
}

int Block::getH() { return this->h; }

int Block::getW() { return this->w; }

int Block::getX() { return this->pos.getX(); }

int Block::getY() { return this->pos.getY(); }

int Block::getF() { return this->fila; }

int Block::getC() { return this->columna; }

Vector2D Block::getPos() { return pos; }