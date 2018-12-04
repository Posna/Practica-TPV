#include "SDL.h"
#include "SDL_image.h"
#include "ArkanoidObject.h"
#include "Vector2D.h"

class Button: public ArkanoidObject
{
private:
	
public:
	//Initialize the variables
	Button(Vector2D pos, Texture* t, uint w, uint h, uint fX, uint fY) : ArkanoidObject(pos, t, w, h, fX, fY) {}


	bool clicked();
};