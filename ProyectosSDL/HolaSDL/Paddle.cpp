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
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) {
			veldir = Vector2D(-velocity, 0);
		}
		if (event.key.keysym.sym == SDLK_RIGHT) {
			veldir = Vector2D(velocity, 0);
		}
	}
	if (event.type == SDL_KEYUP) {
		if(event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT)
			veldir = Vector2D(0, 0);
	}
}

Vector2D Paddle::coll(SDL_Rect dimball, Vector2D& vel) {
	double paso1, paso2, paso3;
	Vector2D centroinf = { (double)(dimball.x + dimball.w / 2), (double)(dimball.y + dimball.h) };
	if ((centroinf.getX() >= pos.getX()) && (centroinf.getX() <= (pos.getX() + anch)) && (centroinf.getY() >= pos.getY()) && (centroinf.getY() <= (pos.getY() + alt))) {  //&& pos.getY() == centro.getY())
		paso1 = pos.getX() + (anch / 2);
		paso2 = centroinf.getX() - paso1;
		paso3 = paso2 / (anch / 2);
		if (vel.getX() > 0) {
			if (((centroinf.getY() - pos.getY()) <= (centroinf.getX() - pos.getX()))) {
				if (paso3 < 0.2 && paso3 > -0.2)
					return Vector2D(0, -1);
				else
					vel = Vector2D(paso3, -1);
			}
			else { return Vector2D(-1, 0); }
		}
		else {
			if (((centroinf.getY() - pos.getY()) <= (pos.getX() + anch - centroinf.getX()))) {
				if (paso3 < 0.2 && paso3 > -0.2)
					return Vector2D(0, -1);
				else
					vel =  Vector2D(paso3, -1);
			}
			else { return Vector2D(1, 0); }
		}
	}
	return Vector2D(0, 0);

}







