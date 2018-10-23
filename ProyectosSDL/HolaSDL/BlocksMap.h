#ifndef BLOCK_MAP
#define BLOCK_MAP
#include "Block.h"
#include "Vector2D.h"


class BlockMap
{
private:
	Block*** bloques = nullptr;
	uint wB;
	uint hB;
	uint dimx;
	uint dimy;

public:
	BlockMap(Texture* t, string archivo);
	~BlockMap();
	void render() const;
};

#endif
