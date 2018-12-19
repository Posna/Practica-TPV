#pragma once
#ifndef PAUSE_STATE
#define PAUSE_STATE
#include "GameState.h"

class PauseState {

private:

public:
	virtual void update();
	virtual void render();
};
#endif