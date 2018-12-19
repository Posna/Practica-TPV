#pragma once
#include "GameState.h"
#include "MenuButton.h"
#include <iostream>

class MenuState: public GameState {
public:
	MenuState(Texture* t, Game* game) : GameState(game) { objetos.push_back(new MenuButton(Vector2D(0, 0), t, 100, 50, 0, 0));
	cout << "creado menu";
	}
	/*virtual void update();
	virtual void render();
	virtual void handleEvents();*/

	string getStateID() const { return s_menuID; }

private:
	//MenuButton* playButton;

	//void playstate();

	const string s_menuID = "MENU";
};