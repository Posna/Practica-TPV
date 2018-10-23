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
		fich >> dimx >> dimy;
		wB = (WIN_WIDTH - (anchoW*2)) / dimx;
		hB = (WIN_HEIGHT/2) / dimy;
		bloques = new Block**[dimx];
		for (int i = 0; i < dimx; i++) {
			bloques[i] = new Block*[dimy];
			for (int j = 0; j < dimy; j++) {
				Vector2D pos(((j*wB)+anchoW), ((i*hB)+anchoW));
				fich >> color;
				bloques[i][j] = new Block(pos, color, 1, 1, t, wB, hB);
			}
		}
	}
}

void BlockMap::render() const {
	for (int i = 0; i < dimx; i++) {
		for (int j = 0; j < dimy; j++) {
			bloques[i][j]->render();
		}
	}
}