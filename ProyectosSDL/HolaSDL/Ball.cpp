#include "Ball.h"
#include "Game.h"
#include <string>


using namespace std;

void Ball::render() {

	SDL_Rect destRect;
	destRect.w = this->anch;
	destRect.h = this->alt;
	destRect.x = this->pos.getX();
	destRect.y = this->pos.getY();
	b->render(destRect);
}

void Ball::coll() {
	Vector2D norm = { 0,0 };
	norm = game->collides(dimball(), veldir);
	norm.normaliza();
	veldir = veldir - (norm * 2 * (norm*veldir));
	//veldir.normaliza();
	//veldir = veldir * 2;
}

void Ball::update() {
	coll();
	pos = pos + veldir;
}

SDL_Rect Ball::dimball() {
	SDL_Rect destRect;
	destRect.w = anch;
	destRect.h = alt;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	return destRect;
}

bool Ball::muerto() {
	if (pos.getY() <= WIN_HEIGHT) {
		return true;
	}
	else {
		pos = posini;
		veldir = veldirini;
		return false;
	}
}