#include "IncreaseMaxHealth.h"

IncreaseMaxHealth::IncreaseMaxHealth() {
	entity = Entity::IMH;
	increaseMaxHealth = 50;
}

IncreaseMaxHealth::IncreaseMaxHealth(Point mapPosition, int increaseMaxHealth)
{
	entity = Entity::IMH;
	this->increaseMaxHealth = increaseMaxHealth;
}


int IncreaseMaxHealth::getHealth() {
	return 1;
}

Entity IncreaseMaxHealth::getEntity() {
	return entity;
}

void IncreaseMaxHealth::setEntity(Entity ent) {
	entity = ent;
}

Point IncreaseMaxHealth::getMapPosition()
{
	return m_mapPosition;
}

void IncreaseMaxHealth::setMapPosition(Point mapPosition) { m_mapPosition = mapPosition; }

int IncreaseMaxHealth::attack() { return 0; }

void IncreaseMaxHealth::takeDamage(int health) {}

std::string IncreaseMaxHealth::GetLog()
{
	return "Item\n";
}

bool IncreaseMaxHealth::isAvaliable()
{
	return avaliable;
}

void IncreaseMaxHealth::disable() {
	avaliable = false;
}

std::string IncreaseMaxHealth::getData() {
	std::string res = "";
	res = res +
		std::to_string((int)entity) + " " +
		std::to_string(m_mapPosition.x) + ' ' + std::to_string(m_mapPosition.y) + " " +
		std::to_string(increaseMaxHealth);
	return res;
}

