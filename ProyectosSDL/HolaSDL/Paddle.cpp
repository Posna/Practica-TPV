#include "Paddle.h"
#include <string>
#include "Game.h"

using namespace std;

void Paddle::render()
{
	SDL_Rect destRect;
	destRect.w = this-> anch;
	destRect.h = this-> alt;

	destRect.x = this->pos.getx();
	destRect.y = this->pos.gety();
	p->render(destRect);

}void Paddle::update() {
	if(pos.getx() > anchoW && pos.getx() < (WIN_HEIGHT - anchoW))
		pos = pos + veldir;
}

void Paddle::handleEvents(SDL_Event& event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) {
			veldir = Vector2D(-2, 0);
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			veldir = Vector2D(2, 0);
		}
		else {//if(event.key.keysym.sym != SDLK_RIGHT && event.key.keysym.sym != SDLK_LEFT)
			veldir = Vector2D(0, 0);
		}
	}else
		veldir = Vector2D(0, 0);

}







