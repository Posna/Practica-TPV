#include "SDLGameObject.h"

SDL_Rect SDLGameObject::getRect() {
	SDL_Rect desRect;
	desRect.x = this->pos.getX();
	desRect.y = this->pos.getY();
	desRect.w = this->w;
	desRect.h = this->h;
	return desRect;
}

void SDLGameObject::render() {
	this->t->renderFrame(getRect(), fY, fX);
}