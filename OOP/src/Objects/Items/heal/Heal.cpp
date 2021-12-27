#include "Heal.h"
Heal::Heal() {
	entity = Entity::HEAL;
	heal = 50;
}

Heal::Heal(Point mapPosition, int heal)
{
	entity = Entity::HEAL;
	this->heal = heal;
}

int Heal::getHealth() {
	return 1;
}

Entity Heal::getEntity() {
	return entity;
}

void Heal::setEntity(Entity ent) {
	entity = ent;
}

Point Heal::getMapPosition()
{
	return m_mapPosition;
}

void Heal::setMapPosition(Point mapPosition) { m_mapPosition = mapPosition; }

int Heal::attack() { return 0; }

void Heal::takeDamage(int health) {}

std::string Heal::GetLog()
{
	return "Item\n";
}

bool Heal::isAvaliable()
{
	return avaliable;
}

void Heal::disable() {
	avaliable = false;
}

std::string Heal::getData(){
	std::string res = "";
	res = res +
	std::to_string((int)entity) + " " +
	std::to_string(m_mapPosition.x) + ' ' + std::to_string(m_mapPosition.y) + " " +
	std::to_string(heal);
	return res;
}
