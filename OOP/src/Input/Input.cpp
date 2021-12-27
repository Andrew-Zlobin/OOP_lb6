#include "Input.h"

Input::Input() {
	m_closeButtonPressed = false;
	buttonList[ControlButtons::UP] = 'A' - 'A';
	buttonList[ControlButtons::DOWN] = 'A' - 'A';
	buttonList[ControlButtons::LEFT] = 'A' - 'A';
	buttonList[ControlButtons::RIGHT] = 'A' - 'A';
	buttonList[ControlButtons::ATTACK] = 'A' - 'A';

	for (int i = 0; i < 255; i++) {
		pressedButton[i] = false;
	}
}

Input::Input(Graphics graphics) : Input() {
	
	m_window = graphics.getWindow();
}

void Input::setWindow(sf::RenderWindow* window) {
	m_window = window;
}

void Input::update() {
	while (m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_closeButtonPressed = true;
		}
		if (event.type == sf::Event::KeyPressed) {
			pressedButton[event.key.code] = true;
		}
		if (event.type == sf::Event::KeyReleased) {
			pressedButton[event.key.code] = false;
		}
	}
}

void Input::setGraphics(Graphics* graphics) {
	m_window = graphics->getWindow();
}

bool Input::pressed(ControlButtons button) {
	return pressedButton[buttonList[button]];
}

bool Input::closeButtonPressed() {
	return m_closeButtonPressed;
}

void Input::setButtons(const char* buttons) {
	for (int i = 0; i < 5; i++) {
		if (buttons[i] > 'A' && buttons[i] < 'Z') {
			buttonList[i] = buttons[i] - 'A';
		}
	}
}
