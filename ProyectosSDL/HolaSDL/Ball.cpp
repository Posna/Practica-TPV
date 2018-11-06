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
	Vector2D norm = collWall();
	if (norm.getX() == 0 && norm.getY() == 0) {
		norm = game->collides(dimball(), veldir);
	}
	norm.normaliza();
	if (norm.getX() != 0 || norm.getY() != 0) {
		veldir = veldir - (norm * 2 * (norm*veldir));
	}
}

Vector2D Ball::collWall() {
	if (pos.getX() <= anchoW)
		return Vector2D(1, 0);
	if ((pos.getX() + anch) >= (WIN_WIDTH - anchoW))
		return Vector2D(-1, 0);
	if (pos.getY() <= anchoW)
		return Vector2D(0, 1);
	if ((pos.getY() + alt) >= (WIN_HEIGHT - anchoW))
		return Vector2D(0, 1);
	return Vector2D(0, 0);
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