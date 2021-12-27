#pragma once
#include <SFML/Graphics.hpp>
#include "Texture/CustomTexture.h"
#include "../Game/Level/Level.h"


#define WIN_WIDTH 2000
#define WIN_HEIDHT 1000
#define CELL_SIZE 50

class Graphics {
private:
	sf::RenderWindow* window;
	Level* m_level;
	CustomTexture wallTexture;
	CustomTexture playerTexture;
	CustomTexture warriorTexture;
	CustomTexture tankTexture;
	CustomTexture ghostTexture;
	CustomTexture imhTexture;
	CustomTexture iaTexture;
	CustomTexture healTexture;
public:
	Graphics();
	Graphics(int x, int y);
	Graphics& operator= (const Graphics& graphics);
	Graphics(const Graphics& graphics);
	void setLevel(Level * level);
	void update();
	sf::RenderWindow* getWindow();
	void close();
};

