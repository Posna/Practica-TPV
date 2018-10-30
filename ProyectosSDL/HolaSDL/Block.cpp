#include "Block.h"
#include <string>

using namespace std;

void Block::render() const{
	SDL_Rect destRect;
	destRect.w = this->w;
	destRect.h = this->h;
	destRect.x = this->pos.getx();
	destRect.y = this->pos.gety();
	textura->renderFrame(destRect, (color-1)%2, (color-1)%3);
}