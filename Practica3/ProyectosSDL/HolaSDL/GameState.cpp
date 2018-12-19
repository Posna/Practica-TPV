#include "GameState.h"

void GameState::update() {
	for (GameObject* o : objetos) {
		o->update();
	}
}

void GameState::render() {
	for (GameObject* o : objetos) {
		o->render();
	}
}

void GameState::handleEvents(SDL_Event& event){
	for (GameObject* o : objetos) {
		o->handleEvents(event);
	}
}