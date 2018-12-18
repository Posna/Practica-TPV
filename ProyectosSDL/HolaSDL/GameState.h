#pragma once
#ifndef GAME_STATE
#define GAME_STATE
#include "GameObject.h"
#include "Game.h"
#include <list>

class GameState{
private:
	list<GameObject*> objetos;
	Game* game;

public:

	virtual void update();
	virtual void render();
	virtual void handleEvent();

	virtual std::string getStateID() const = 0;

};

#endif