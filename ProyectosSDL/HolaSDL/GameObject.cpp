//#include "GameObject.h"
//
//using namespace std;
//
//void GameObject::render(Texture* t, SDL_Rect desRect) const {
//	t->render(desRect);
//}
//
//void GameObject::update(Vector2D& pos, const Vector2D& veldir) {
//	pos = veldir + pos;
//}
//
//void GameObject::handleEvents(SDL_Event& event) {
//	/*if (event.type == SDL_KEYDOWN) {
//		if (event.key.keysym.sym == SDLK_LEFT) {
//			veldir = Vector2D(-2, 0);
//		}
//		if (event.key.keysym.sym == SDLK_RIGHT) {
//			veldir = Vector2D(2, 0);
//		}
//	}
//	if (event.type == SDL_KEYUP) {
//		if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT)
//			veldir = Vector2D(0, 0);
//	}*/
//}