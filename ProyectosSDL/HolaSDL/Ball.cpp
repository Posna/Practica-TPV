#include "Ball.h"
#include "Game.h"
#include <string>


using namespace std;



void Ball::coll() {
	Vector2D norm = { 0,0 };
	norm = game->collides(dimball(), veldir);
	norm.normaliza();
	veldir = veldir - (norm * 2 * (norm*veldir));
}

void Ball::update() {
	coll();
	MovingObject::update();
}

SDL_Rect Ball::dimball() {
	return this->getRect();
}

void Ball::ballIni() {
	pos = posini;
	veldir = veldirini;
}

bool Ball::muerto() {
	return game->CollDead(getRect()) == 2;
}