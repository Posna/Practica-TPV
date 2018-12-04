#include "ArkanoidObject.h"


using namespace std;

void ArkanoidObject::loadFromFile(ifstream& file) {
	double x, y;
	file >> x >> y >> w >> h;
	pos = Vector2D(x, y);
}

void ArkanoidObject::saveToFile(ofstream& file) {
	//int a = (int)(pos.getX());
	//cout << a << endl;
	file << (int)(pos.getX()) << " " << (int)(pos.getY()) << " " << w << " " << h << endl;
}

SDL_Rect ArkanoidObject::getRect() {
	SDL_Rect desRect;
	desRect.x = this->pos.getX();
	desRect.y = this->pos.getY();
	desRect.w = this->w;
	desRect.h = this->h;
	return desRect;
}

void ArkanoidObject::render() {
	this->t->renderFrame(getRect(), fY, fX);
}