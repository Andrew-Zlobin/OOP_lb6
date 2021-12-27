#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Graphics/Graphics.h"
#include "../Objects/Units/Direction.h"
enum ControlButtons {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ATTACK
};


class Input {
private:
	sf::RenderWindow* m_window;
	sf::Event event;
	bool m_closeButtonPressed;
	char buttonList[5];
	bool pressedButton[255];
public:
	Input();
	Input(Graphics graphics);
	void setWindow(sf::RenderWindow* window);
	void update();
	void setGraphics(Graphics *graphics);
	bool pressed(ControlButtons button);
	bool closeButtonPressed();
	void setButtons(const char * buttons);
};

