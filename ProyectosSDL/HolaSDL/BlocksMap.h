#ifndef BLOCK_MAP
#define BLOCK_MAP
#include "Block.h"
#include "Vector2D.h"
#include "checkML.h"


class BlockMap
{
private:
	Block*** bloques = nullptr;
	uint wB;
	uint hB;
	uint dimx;
	uint dimy;
	int numbloques = 0;
	bool enbloque(Vector2D pos, Vector2D posB, uint Wbloq, uint Hbloq);

public:
	BlockMap(Texture* t, string archivo);
	~BlockMap();
	void render() const;
	Block* collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt(const Vector2D& p);
	void destroyblock(Block* bloq);
	bool nobloques();
};

#endif
