#pragma once
#ifndef GAME_STATE
#define GAME_STATE
#include "GameObject.h"
#include "Game.h"
#include <list>

class GameState{
protected:
	list<GameObject*> objetos;
	Game* game = nullptr;

public:
	virtual ~GameState() {}
	virtual void update();
	virtual void render();
	virtual void handleEvent();

	std::string getStateID() const {}

};

#endif