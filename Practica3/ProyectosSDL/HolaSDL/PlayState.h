#pragma once
#include "GameState.h"

class PlayState: public GameState {
private:
	static const std::string s_playID;


public:
	PlayState(Texture* t, Game* game);
	virtual void render();
	virtual void update();
	virtual void handleEvents();

	virtual std::string getStateID() const { return s_playID; }

};