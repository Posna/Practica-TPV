#include "SDL.h"
#include "SDL_image.h"
#include "SDLGameObject.h"
#include "Vector2D.h"

class Game;

class MenuButton: public SDLGameObject
{
private:
	enum button_state
	{
		MOUSE_OUT = 0,
		MOUSE_OVER = 1,
		CLICKED = 2
	};
	int currentState = 0;
	//Game* game;
	void(*m_callback) ();
public:
	//Initialize the variables
	MenuButton(Vector2D pos, Texture* t, uint w, uint h, uint fX, uint fY, void (*callback)()) : SDLGameObject(pos, t, w, h, fX, fY), m_callback(callback) {}

	void update();
	void render();
	void handleEvents();

	void clicked();
};