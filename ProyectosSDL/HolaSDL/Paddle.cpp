#include "Paddle.h"
#include <string>
#include "Game.h"

using namespace std;

void Paddle::render()
{
	SDL_Rect destRect;
	destRect.w = this-> anch;
	destRect.h = this-> alt;

	destRect.x = this->pos.getX();
	destRect.y = this->pos.getY();
	p->render(destRect);

}void Paddle::update() {
	if(((pos + veldir).getX() > anchoW) && (((pos + veldir).getX() + anch) < (WIN_WIDTH - anchoW)))
		pos = pos + veldir;
}

void Paddle::handleEvents(SDL_Event& event) {
	if (event.key.keysym.sym == SDLK_LEFT) {
		veldir = Vector2D(-1, 0);
	}
	if (event.key.keysym.sym == SDLK_RIGHT) {
		veldir = Vector2D(1, 0);
	}
	if (event.type == SDL_KEYUP) {
		veldir = Vector2D(0, 0);
	}
}







