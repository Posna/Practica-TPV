#include "MenuButton.h"

void MenuButton::clicked() {

}

void MenuButton::update()
{
	if (currentState == MOUSE_OVER) {
		w = 90;
		h = 40;
	}
	if (currentState == MOUSE_OUT) {
		w = 100;
		h = 50;
	}
	

}

void MenuButton::handleEvents(SDL_Event& event) {
	/*if (currentState == CLICKED) {
		m_callback();
	}*/
					
	if (SDL_PollEvent(&event)) {
		//cout << "se llama";
		if (event.type == SDL_MOUSEMOTION) {
			if (event.motion.x >= pos.getX() && event.motion.x <= pos.getX() + w && event.motion.y >= pos.getY() && event.motion.y <= pos.getY() + h) {
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					//currentState = CLICKED;
					m_callback();
				}
			}
			else {
				currentState = MOUSE_OVER;
			}
		}
	}
	currentState = MOUSE_OUT;

}