#include "ArkanoidObject.h"

using namespace std;

void ArkanoidObject::loadFromFile() {


}

void ArkanoidObject::saveToFile() {


}

SDL_Rect ArkanoidObject::getRect() {
	SDL_Rect desRect;
	desRect.x = this->pos.getX();
	desRect.y = this->pos.getY();
	desRect.w = this->w;
	desRect.h = this->h;
	return desRect;
}

void ArkanoidObject::render() {
	this->t->renderFrame(getRect(), fY, fX);
}