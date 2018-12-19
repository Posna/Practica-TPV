#include "PlayState.h"
#include "GameObject.h"
#include "Paddle.h"		

const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState(Texture* t, Game* game): GameState(game) {
	objetos.push_back(new Paddle(Vector2D(100, 0), 50, 100, Vector2D(0, 0), t));
	cout << "creado play";
}

//void PlayState::update() {
//	for (GameObject* o: objetos) {
//		o->update();
//	}
//}
//
//void PlayState::render() {
//	for (GameObject* o : objetos) {
//		o->render();
//	}
//}
//
//void PlayState::handleEvents() {
//	for (GameObject* o : objetos) {
//		o->handleEvents();
//	}
//}