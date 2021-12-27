#pragma once
#include <SFML/Graphics.hpp>
class CustomTexture
{
private:
	sf::Texture texture;
public:
	CustomTexture();
	CustomTexture(const char * filePath);
	sf::Texture getTexture();
	void setTexture(const char* filePath);
};

