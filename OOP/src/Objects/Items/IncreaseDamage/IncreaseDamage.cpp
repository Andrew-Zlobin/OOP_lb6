#include "IncreaseDamage.h"
IncreaseDamage::IncreaseDamage() {
	entity = Entity::IA;
	increaseDamage = 50;
}

IncreaseDamage::IncreaseDamage(Point mapPosition, int increaseDamage)
{
	entity = Entity::IA;
	this->increaseDamage = increaseDamage;
}


int IncreaseDamage::getHealth() {
	return 1;
}

Entity IncreaseDamage::getEntity() {
	return entity;
}

void IncreaseDamage::setEntity(Entity ent) {
	entity = ent;
}

Point IncreaseDamage::getMapPosition()
{
	return m_mapPosition;
}

void IncreaseDamage::setMapPosition(Point mapPosition) { m_mapPosition = mapPosition; }

int IncreaseDamage::attack() { return 0; }

void IncreaseDamage::takeDamage(int health) {}

std::string IncreaseDamage::GetLog()
{
	return "Item\n";
}

bool IncreaseDamage::isAvaliable()
{
	return avaliable;
}

void IncreaseDamage::disable() {
	avaliable = false;
}

std::string IncreaseDamage::getData() {
	std::string res = "";
	res = res +
		std::to_string((int)entity) + " " +
		std::to_string(m_mapPosition.x) + ' ' + std::to_string(m_mapPosition.y) + " " +
		std::to_string(increaseDamage);
	return res;
}

