#include "BlocksMap.h"
#include <iostream>
#include "Game.h"
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include "FileNotFoundError.h"


BlockMap::BlockMap(Texture* t, string archivo, Game* game): ArkanoidObject(Vector2D(0, 0), nullptr, 0, 0, 0, 0), game(game) {
	ifstream fich;
	fich.open(archivo);
	if (!fich.is_open()) {
		throw FileNotFoundError(archivo);
		
	}
	else {
		this->t = t;
		leeMapa(fich);
	}
}

void BlockMap::leeMapa(ifstream& file) {
	int color;
	numbloques = 0;
	file >> dimy >> dimx;
	wB = (WIN_WIDTH - (anchoW * 2)) / dimx;
	hB = (WIN_HEIGHT / 2) / dimy;
	bloques = new Block**[dimy];
	for (int i = 0; i < dimy; i++) {
		bloques[i] = new Block*[dimx];
		for (int j = 0; j < dimx; j++) {
			Vector2D pos(((j*wB) + anchoW), ((i*hB) + anchoW));
			file >> color;
			if (color == 0) {
				bloques[i][j] = nullptr;
			}
			else {
				bloques[i][j] = new Block(pos, color, i, j, this->t, wB, hB);
				numbloques++;
			}
		}
	}
}

void BlockMap::saveToFile(ofstream& file) {
	ArkanoidObject::saveToFile(file);
	file << dimy << " " << dimx << endl;
	for (int i = 0; i < dimy; i++) {
		for (int j = 0; j < dimx; j++) {
			if (bloques[i][j] != nullptr)
				file << bloques[i][j]->getColor() << " ";
			else
				file << "0" << " ";
		}
		file << endl;
	}
	file << numbloques << endl;
}

void BlockMap::loadFromFile(ifstream& file) {
	ArkanoidObject::loadFromFile(file);
	leeMapa(file);
	file >> numbloques;

}

void BlockMap::render() {
	for (int i = 0; i < dimy; i++) {
		for (int j = 0; j < dimx; j++) {
			if(bloques[i][j] != nullptr)
				bloques[i][j]->render();
		}
	}
}

BlockMap::~BlockMap() {
	for (int i = 0; i < dimy; i++) {
		for (int j = 0; j < dimx; j++) {
			if(bloques[i][j] != nullptr)
				delete bloques[i][j];
		}
		delete [] bloques[i];
	}
	delete [] bloques;
	bloques = nullptr;
}

/*  Devuelve el puntero al bloque del mapa de bloques al que pertenece el punto p.
En caso de no haber bloque en ese punto (incluido el caso de que p esté fuera
del espacio del mapa) devuelve nullptr.
*/
Block* BlockMap::blockAt(const Vector2D& p) {
	bool col = false;
	Block* bloque = nullptr;
	if ((p.getY() < ((WIN_HEIGHT) / 2) + anchoW) && p.getX() > anchoW && p.getX() < WIN_WIDTH - anchoW -20) {
		return bloques[(int)trunc(((p.getY() - anchoW) / (hB)))][(int)trunc(((p.getX() - anchoW) / (wB)))];
	}
	else return nullptr;
}

/* Dados el rectángulo y vector de dirección de la pelota, devuelve un puntero al
bloque con el que ésta colisiona (nullptr si no colisiona con nadie) y el
vector normal perpendicular a la superficie de colisión.
*/
Block* BlockMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector) {
	Vector2D p0 = { (double)ballRect.x, (double)ballRect.y }; // top-left
	Vector2D p1 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y }; // top-right
	Vector2D p2 = { (double)ballRect.x, (double)ballRect.y + (double)ballRect.h }; // bottom-left
	Vector2D p3 = { (double)ballRect.x + (double)ballRect.w, (double)ballRect.y + ballRect.h }; // bottom-right
	Block* b = nullptr;
	if (ballVel.getX() < 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p0))) {
			if ((b->getY() + b->getH() - p0.getY()) <= (b->getX() + b->getW() - p0.getX()))
				collVector = { 0,1 }; // Borde inferior mas cerca de p0
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p1))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p2))) collVector = { 1,0 };
	}
	else if (ballVel.getX() >= 0 && ballVel.getY() < 0) {
		if ((b = blockAt(p1))) {
			if (((b->getY() + b->getH() - p1.getY()) <= (p1.getX() - b->getX())) || ballVel.getX() == 0)
				collVector = { 0,1 }; // Borde inferior mas cerca de p1
			else
				collVector = { -1,0 }; // Borde izqdo mas cerca de p1
		}
		else if ((b = blockAt(p0))) {
			collVector = { 0,1 };
		}
		else if ((b = blockAt(p3))) collVector = { -1,0 };
	}
	else if (ballVel.getX() > 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p3))) {
			if (((p3.getY() - b->getY()) <= (p3.getX() - b->getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p3
			else
				collVector = { -1,0 }; // Borde dcho mas cerca de p3
		}
		else if ((b = blockAt(p2))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p1))) collVector = { -1,0 };
	}
	else if (ballVel.getX() < 0 && ballVel.getY() > 0) {
		if ((b = blockAt(p2))) {
			if (((p2.getY() - b->getY()) <= (b->getX() + b->getW() - p2.getX()))) // || ballVel.getX() == 0)
				collVector = { 0,-1 }; // Borde superior mas cerca de p2
			else
				collVector = { 1,0 }; // Borde dcho mas cerca de p0
		}
		else if ((b = blockAt(p3))) {
			collVector = { 0,-1 };
		}
		else if ((b = blockAt(p0))) collVector = { 1,0 };
	}
	
	return b;
}

void BlockMap::destroyblock(Block* bloq) {
	numbloques--;
	int f = bloq->getF();
	int c = bloq->getC();
	delete bloques[f][c];
	bloques[f][c] = nullptr;
}

bool BlockMap::nobloques() {
	return (numbloques == 0);
}