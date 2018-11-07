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

Vector2D Paddle::coll(SDL_Rect dimball, Vector2D vel) {
	double paso1, paso2, paso3;
	Vector2D centro = { (double)(dimball.x + dimball.w / 2), (double)(dimball.y + dimball.h / 2) };
	if ((centro.getX() >= pos.getX()) && (centro.getX() <= (pos.getX() + anch)) && (centro.getY() >= pos.getY()) && (centro.getY() <= (pos.getY() + alt))) {  //&& pos.getY() == centro.getY())
		paso1 = pos.getX() + (anch / 2);
		paso2 = centro.getX() - paso1;
		paso3 = paso2 / (anch / 2);
		if (vel.getX() > 0) {
			if (((centro.getY() - pos.getY()) <= (centro.getX() - pos.getX()))) {
				return Vector2D(paso3, -1);
			}
			else { return Vector2D(-1, 0); }
		}
		else {
			if (((centro.getY() - pos.getY()) <= (pos.getX() + anch - centro.getX()))) {
				return Vector2D(paso3, -1);
			}
			else { return Vector2D(-1, 0); }
		}
		//return Vector2D(paso3, -1);
	}
	//else if (centro.getX() >= pos.getX() && (centro.getX() < pos.getX() + anch/4 ) && pos.getY() < centro.getY() && (centro.getY() < pos.getY() + alt)) { return Vector2D(-1, 0); }
	//mirar ocmo esta hecho lo bloques para que por los lados rebote normal
	//seguir investigando para que rebota de esa forma "rara" en el paddle
	return Vector2D(0, 0);

}







