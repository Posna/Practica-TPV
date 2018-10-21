#include "Wall.h"
#include <string>

using namespace std;

void Wall::render() {
	SDL_Rect destRect;
	destRect.w = this->w;
	destRect.h = this->h;
	this->t->render(destRect);
}