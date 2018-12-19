#pragma once
#include "GameState.h"
#include <stack>
#include <string>

//using namespace std;

class GameStateMachine {
public:
	void pushState(GameState* pState);
	void changeState(GameState* pState);
	void popState();
	GameState* currentState();
private:
	stack <GameState*> states;

};