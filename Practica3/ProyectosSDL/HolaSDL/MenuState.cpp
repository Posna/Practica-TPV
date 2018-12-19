#include "MenuState.h"

const std::string s_menuID = "MENU";

void MenuState::playstate() {
	this->game->playState();
}


//MenuState::MenuState(Texture* t, Game* game) {
//	
//}

//void MenuState::update() {
//	for (GameObject* o : objetos) {
//		o->update();
//	}
//
//}
//
//void MenuState::render() {
//	for (GameObject* o : objetos) {
//		o->render();
//	}
//
//}
//
//void MenuState::handleEvents() {
//	for (GameObject* o : objetos) {
//		o->handleEvents();
//	}
//}