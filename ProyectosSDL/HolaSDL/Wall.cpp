#include "Wall.h"
#include <string>

using namespace std;


void Wall::render() const{
	SDL_Rect destRect;
	destRect.w = this->w;
	destRect.h = this->h;
	destRect.x = this->pos.getX();
	destRect.y = this->pos.getY();
	t->render(destRect);
}