#include "Ball.h"
#include "Game.h"
#include <string>


using namespace std;

//void Ball::render() {
//	this->t->render(getRect());
//}

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
	MovingObject::update();
}

SDL_Rect Ball::dimball() {
	/*SDL_Rect destRect;
	destRect.w = anch;
	destRect.h = alt;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	return destRect;*/
	return this->getRect();
}

void Ball::ballIni() {
	pos = posini;
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