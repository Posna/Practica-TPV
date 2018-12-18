#pragma once
#include "GameState.h"
#include <stack>

class GameStateMachine {
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	void currentState();
private:
	stack<GameState*> states;

};