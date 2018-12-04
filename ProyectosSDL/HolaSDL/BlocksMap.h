#ifndef BLOCK_MAP
#define BLOCK_MAP
#include "Block.h"
#include "Vector2D.h"
#include "checkML.h"
#include "ArkanoidObject.h"

class Game;

class BlockMap: public ArkanoidObject {
private:
	Block*** bloques = nullptr;
	uint wB;
	uint hB;
	uint dimx;
	uint dimy;
	Game* game = nullptr;
	int numbloques = 0;
	

public:
	BlockMap(Texture* t, string archivo, Game* game);
	~BlockMap();
	void leeMapa(ifstream& file);
	void saveToFile(ofstream& file);
	void loadFromFile(ifstream& file);
	virtual void render();
	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);
	//controla cuando para de haber bloque para(se llama en el while del juego)
	bool nobloques();
	void destroyblock(Block* bloq);	
};
#endif