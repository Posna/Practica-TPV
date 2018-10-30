#include "BlocksMap.h"
#include <iostream>
#include "Game.h"
#include <fstream>


BlockMap::BlockMap(Texture* t, string archivo) {
	ifstream fich;
	fich.open(archivo);
	if (!fich.is_open()) {
		cout << "No se encuentra el fichero " << archivo << endl;
	}
	else {
		int color;
		fich >> dimy >> dimx;
		wB = (WIN_WIDTH - (anchoW*2)) / dimx;
		hB = (WIN_HEIGHT/2) / dimy;
		bloques = new Block**[dimy];
		for (int i = 0; i < dimy; i++) {
			bloques[i] = new Block*[dimx];
			for (int j = 0; j < dimx; j++) {
				Vector2D pos(((j*wB)+anchoW), ((i*hB)+anchoW));
				fich >> color;
				if (color == 0) {
					bloques[i][j] = nullptr;
				}
				else {
					bloques[i][j] = new Block(pos, color, 1, 1, t, wB, hB);
				}
			}
		}
	}
}

void BlockMap::render() const {
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
			delete bloques[i][j];
		}
		delete bloques[i];
	}
	delete bloques;
	bloques = nullptr;

}