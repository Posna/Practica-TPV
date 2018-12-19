#pragma once
#ifndef GAME_STATE
#define GAME_STATE
#include "GameObject.h"
#include <string>
#include <list>
#include "Vector2D.h"
#include "Texture.h"

typedef unsigned int uint;

using namespace std;

class Game;

class GameState {
protected:
	list<GameObject*> objetos;
	Game* game = nullptr;
public:
	GameState(Game* game):game(game) {}
	//virtual ~GameState() {}
	virtual void update();
	virtual void render();
	virtual void handleEvents(SDL_Event& event);

	virtual string getStateID() const  = 0;


};
#endif