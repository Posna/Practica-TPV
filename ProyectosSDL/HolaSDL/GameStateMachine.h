#pragma once
#include "GameState.h"
#include <stack>
#include <string>

using namespace std;

class GameStateMachine {
public:
	//GameStateMachine(GameState* pState) { pushState(pState); }
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	GameState* currentState();
private:
	stack<GameState*> states;

};