#include "Block.h"
#include <string>

using namespace std;

void Block::render() const{
	if (this->color != 0) {
		SDL_Rect destRect;
		destRect.w = this->w;
		destRect.h = this->h;
		destRect.x = this->pos.getx();
		destRect.y = this->pos.gety();
		textura->renderFrame(destRect, color%2, color%3);
	}
}