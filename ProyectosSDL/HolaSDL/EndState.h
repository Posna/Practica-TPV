#pragma once
#ifndef END_STATE
#define END_STATE
#include "GameState.h"

class EndState {

private:

public:
	virtual void render();
	virtual void update();
	virtual void handleEvent();

};
#endif