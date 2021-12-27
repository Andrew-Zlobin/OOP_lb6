#include "CustomTexture.h"

CustomTexture::CustomTexture() {}

CustomTexture::CustomTexture(const char* filePath) {
	texture.loadFromFile(filePath);
}

sf::Texture CustomTexture::getTexture() {
	return texture;
}

void CustomTexture::setTexture(const char* filePath) {
	texture.loadFromFile(filePath);
}
