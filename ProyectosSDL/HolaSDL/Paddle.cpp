#include "Paddle.h"
#include <string>

using namespace std;

void Paddle::render()
{
	SDL_Rect destRect;
	destRect.w = this-> anch;
	destRect.h = this-> alt;

	destRect.x = this->pos.getx();
	destRect.y = this->pos.gety();
	p->render(destRect);

}





