#include "MenuButton.h"

void MenuButton::clicked() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		if (event.type == SDL_MOUSEMOTION) {
			if (event.motion.x >= pos.getX() && event.motion.x <= pos.getX() + w && event.motion.y >= pos.getY() && event.motion.y <= pos.getY() + h) {
				if (event.type == SDL_MOUSEBUTTONDOWN) {
					currentState = CLICKED;
				}
			}
			else {
				currentState = MOUSE_OVER;
			}
		}
	}
	currentState = MOUSE_OUT;
}

void MenuButton::update()
{
	/*Vector2D* pMousePos = TheInputHandler::Instance()
		->getMousePosition();
	if (pMousePos->getX() < (m_position.getX() + m_width)
		&& pMousePos->getX() > m_position.getX()
		&& pMousePos->getY() < (m_position.getY() + m_height)
		&& pMousePos->getY() > m_position.getY())
	{
		m_currentFrame = MOUSE_OVER;
		if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		{
			m_currentFrame = CLICKED;
		}
	}
	else
	{
		m_currentFrame = MOUSE_OUT;
	}*/

	if (currentState == MOUSE_OVER) {
		w = 90;
		h = 40;
	}
	if (currentState == MOUSE_OUT) {
		w = 100;
		h = 50;
	}

}

void MenuButton::handleEvents() {
	if (currentState == CLICKED) {
		m_callback();
	}

}