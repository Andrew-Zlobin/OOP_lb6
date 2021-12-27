#include "Graphics.h" 

Graphics::Graphics() {
	window = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIDHT), "SFML Works!");
	playerTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\player.png");
	wallTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\Wall.png");

	warriorTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\Warrior.png");
	tankTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\Tank.png");
	ghostTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\Ghost.png");

	imhTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\imh.png");
	iaTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\ia.png");
	healTexture.setTexture("D:\\Code\\OOP\\full\\OOP\\OOP\\src\\imgs\\heal.png");
}

Graphics::Graphics(int x, int y) {
	window = new sf::RenderWindow(sf::VideoMode(x, y), "SFML Works!");
	
}

Graphics& Graphics::operator=(const Graphics& graphics) {
	window = graphics.window;
	return *this;
}

Graphics::Graphics(const Graphics& graphics) {
	window = graphics.window;
}

void Graphics::setLevel(Level* level) {
	m_level = level;
}

void Graphics::update() {
	sf::RenderTexture renderTexture;
	renderTexture.create(WIN_WIDTH, WIN_HEIDHT);
	renderTexture.clear(sf::Color::White);
	
	for (int i = 0; i < m_level->getMap()->getwidth(); i++) {
		for (int j = 0; j < m_level->getMap()->getheight(); j++) {
			if (m_level->getMap()->getCell(Point(i, j))->getCellElement() != nullptr) {
				sf::Sprite objectSprite;
				sf::Texture objectTexture;
				//std::cout << i << ' ' << j << '\n';
				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::PLAYER) {
					objectTexture = playerTexture.getTexture();
				}
				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::WALL) {
					objectTexture = wallTexture.getTexture();
				}

				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::WARRIOR) {
					objectTexture = warriorTexture.getTexture();
				}
				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::TANK) {
					objectTexture = tankTexture.getTexture();
				}
				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::GHOST) {
					objectTexture = ghostTexture.getTexture();
				}

				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::IMH) {
					objectTexture = imhTexture.getTexture();
				}
				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::IA) {
					objectTexture = iaTexture.getTexture();
				}
				if (m_level->getMap()->getCell(Point(i, j))->getCellElement()->getEntity() == Entity::HEAL) {
					objectTexture = healTexture.getTexture();
				}

				objectSprite.setTexture(objectTexture);
				objectSprite.setPosition(i * CELL_SIZE, j * CELL_SIZE);
				renderTexture.draw(objectSprite);
			}
		}
	}
	
	renderTexture.display();
	
	const sf::Texture& texture = renderTexture.getTexture();

	// draw it to the window
	sf::Sprite sprite(texture);
	//window->clear(sf::Color::Black);
	window->draw(sprite);
	window->display();
	
}

sf::RenderWindow* Graphics::getWindow() {
	return window;
}



void Graphics::close() {
	window->close();
}
