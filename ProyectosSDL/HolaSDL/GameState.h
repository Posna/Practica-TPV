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
	GameState() {}
	void update() {}
	void render() {}
	void handleEvent() {}

	std::string getStateID() const {}

};

#endif