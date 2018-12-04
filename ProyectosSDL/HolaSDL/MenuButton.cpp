#include "MenuButton.h"

bool Button::clicked() {
	//saveGame("prueba");
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.motion.x >= pos.getX() && event.motion.x <= pos.getX() + w && event.motion.y >= pos.getY() && event.motion.y <= pos.getY() + h) {
				return true;
			}
		}
	}
	return false;
}