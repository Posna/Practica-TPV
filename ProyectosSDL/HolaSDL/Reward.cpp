#include "Reward.h"
#include "Game.h"

void Reward::render() {
	int a = (pos.getY()/20);
	fX = a % t->getNumCols();
	ArkanoidObject::render();
}

void Reward::col() {
	if (game->CollDead(getRect()) == 1) {
		efecto();
		game->eliminaObj(it);
	}
}

void Reward::efecto() {
	game->tipoReward(tipoR);
}

void Reward::update() {
	col();
	MovingObject::update();
}