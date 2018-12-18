#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState) {
	states.push(pState);

}

void GameStateMachine::popState() {
	if (!states.empty()) {
		//delete
		states.pop();
	}
}

void GameStateMachine::changeState(GameState* pState) {
	if (pState->getStateID() != states.top()->getStateID()) {
		popState();
		pushState(pState);
	}

}

GameState* GameStateMachine::currentState() {
	return states.top();
}