#include "ArkanoidObject.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ArkanoidObject::loadFromFile() {


}

void ArkanoidObject::saveToFile(ofstream file, string mapa) {
	//file.open(NAME_FILE + ".txt");
	file << mapa << endl;
	file << (int)(pos.getX()) + " " << (int)(pos.getY()) + " " << w + " " << h + " " << endl;
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