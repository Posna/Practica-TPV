#include "Block.h"
#include <string>

using namespace std;

int Block::getH() { return this->h; }

int Block::getW() { return this->w; }

int Block::getX() { return this->pos.getX(); }

int Block::getY() { return this->pos.getY(); }

int Block::getF() { return this->fila; }

int Block::getC() { return this->columna; }

Vector2D Block::getPos() { return pos; }