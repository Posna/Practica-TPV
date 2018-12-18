#pragma once
#include "GameState.h"

class MenuState : public GameState {
public:
	virtual void update();
	virtual void render();
	virtual void handleEvent();

	virtual std::string getStateID() const { return s_menuID; }

private:

	static const std::string s_menuID;
};