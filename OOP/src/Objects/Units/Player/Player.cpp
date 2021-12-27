#include "Player.h"

Player::Player() {
	coins = 0;
	maxHealth = 100;
	entity = Entity::PLAYER;
	m_damage = 30;
	m_health = 100;
	m_mapPosition = Point(1, 1);
}

Player::Player(Point mapPosition, int health, int damage, int direction, int maxHealth) {
	coins = 0;
	this->maxHealth = maxHealth;
	this->entity = Entity::PLAYER;
	this->m_damage = damage;
	this->m_direction = static_cast<Direction>(direction);
	this->m_health = health;
	this->m_mapPosition = mapPosition;
}
void Player::setDirection(Direction dir) {
	m_direction = dir;
}

Direction Player::getDirection() {
	return m_direction;
}

void Player::setMap(Map* m) {
	map = m;
}

std::string Player::GetLog()
{
	return "type: Player\nhealth: " + std::to_string(m_health) + " \ndamage: " + std::to_string(m_damage) + 
		" \ncoord: (" + std::to_string(m_mapPosition.x) + ", " + std::to_string(m_mapPosition.y) + ")" 
		 + " \n//-----------\n";
}

void Player::move(Direction direction) {
	Point targetPoint;
	switch (direction)
	{
	case Direction::UP:
		targetPoint = Point(m_mapPosition.x, m_mapPosition.y - 1);
		break;
	case Direction::DOWN:
		targetPoint = Point(m_mapPosition.x, m_mapPosition.y + 1);
		break;
	case Direction::LEFT:
		targetPoint = Point(m_mapPosition.x - 1, m_mapPosition.y);
		break;
	case Direction::RIGHT:
		targetPoint = Point(m_mapPosition.x + 1, m_mapPosition.y);
		break;
	default:
		break;
	}
	if (map->getCell(targetPoint)->getCellElement() == nullptr ||
		map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::IMH ||
		map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::HEAL ||
		map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::IA) {
		takeItem(targetPoint);
		map->getCell(targetPoint)->setCellElement(map->getCell(m_mapPosition)->getCellElement());
		
		map->getCell(m_mapPosition)->setCellElement(nullptr);
		m_mapPosition = targetPoint;
	}
	m_direction = direction;
}

void Player::interact() {
	//std::cout << "attack\n";
	Point targetPoint;
	switch (m_direction)
	{
	case Direction::UP:
		targetPoint = Point(m_mapPosition.x, m_mapPosition.y - 1);
		break;
	case Direction::DOWN:
		targetPoint = Point(m_mapPosition.x, m_mapPosition.y + 1);
		break;
	case Direction::LEFT:
		targetPoint = Point(m_mapPosition.x - 1, m_mapPosition.y);
		break;
	case Direction::RIGHT:
		targetPoint = Point(m_mapPosition.x + 1, m_mapPosition.y);
		break;
	default:
		break;
	}
	if (map->getCell(targetPoint)->getCellElement() != nullptr) {
		map->getCell(targetPoint)->getCellElement()->takeDamage(attack());
		if (map->getCell(targetPoint)->getCellElement()->getHealth() == 0) {
			map->getCell(targetPoint)->getCellElement()->disable();
			map->getCell(map->getCell(targetPoint)->getCellElement()->getMapPosition())->setCellElement(nullptr);
		}
	}
}

void Player::takeItem(Point targetPoint) {
	if (map->getCell(targetPoint)->getCellElement() != nullptr) {
		if (map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::IMH) {
			maxHealth += 50;
			m_health = maxHealth;
		}
		if (map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::HEAL) {
			m_health += 50;
			if (m_health > maxHealth) {
				m_health = maxHealth;
			}
		}
		if (map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::IA) {
			m_damage += 20;
		}
	}
}


int Player::attack() {
	return m_damage;
}

void Player::takeDamage(int damage) {
	m_health -= damage;
	if (m_health <= 0) {
		m_health = 0;
	}
}

Entity Player::getEntity()
{
	return entity;
}

void Player::setEntity(Entity ent) {
	entity = ent;
}



int Player::getHealth()
{
	return m_health;
}

Point Player::getMapPosition() {
	return m_mapPosition;
}

void Player::setMapPosition(Point mapPosition) {
	m_mapPosition = mapPosition;
}

void Player::update() {}

bool Player::isAvaliable()
{
	return avaliable;
}

void Player::disable() {
	avaliable = false;
}

std::string Player::getData()
{
	std::string res = "";
	res = res +
		std::to_string((int) entity) + " " +
		std::to_string(m_mapPosition.x) + ' ' + std::to_string(m_mapPosition.y) + " " +
		std::to_string(m_health) + " " +
		std::to_string(m_damage) + " " +
		std::to_string((int) m_direction) + " " +
		std::to_string(maxHealth);
	return res;
}
