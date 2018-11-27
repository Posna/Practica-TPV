#include "Paddle.h"
#include <string>
#include "Game.h"

using namespace std;


void Paddle::update() {
	if(((pos + veldir).getX() > anchoW) && (((pos + veldir).getX() + w) < (WIN_WIDTH - anchoW)))
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
	Vector2D centroinf = { (double)(dimball.x + dimball.w / 2), (double)(dimball.y + dimball.h) };
	if ((centroinf.getX() >= pos.getX()) && (centroinf.getX() <= (pos.getX() + w)) && (centroinf.getY() >= pos.getY()) && (centroinf.getY() <= (pos.getY() + h))) { 
		//Cogemos el centro del paddle
		paso1 = pos.getX() + (w / 2);
		//Diferencia entre la posicion de la pelota y el centro del paddle
		//para saber en que lado (izq o drch) esta
		paso2 = centroinf.getX() - paso1;
		//dejamos la posicion en un intervalo entre -1 y 1 que reducimos a -0.1 y 0.1
		paso3 = (paso2 / (w / 2))/10;
		if (vel.getX() > 0) {
			if (((centroinf.getY() - pos.getY()) <= (centroinf.getX() - pos.getX()))) {
				if (paso3 < 0.02 && paso3 > -0.02)
					return Vector2D(0, -1);
				else
					return Vector2D(paso3, -1);
			}
			else { return Vector2D(-1, 0); }
		}
		else {
			if (((centroinf.getY() - pos.getY()) <= (pos.getX() + w - centroinf.getX()))) {
				if (paso3 < 0.02 && paso3 > -0.02)
					return Vector2D(0, -1);
				else
					return Vector2D(paso3, -1);
			}
			else { return Vector2D(1, 0); }
		}
	}
	return Vector2D(0, 0);
}







