#include "Enemy.h"

Enemy::Enemy() {}

std::string Enemy::GetLog()
{
	return "Enemy\n";
}

void Enemy::setMap(Map* m) {
	map = m;
}

void Enemy::update() {
	move();
	interact();
}

void Enemy::move()
{
}

bool Enemy::detectPlayer(Point point) {
	return (map->getCell(point)->getCellElement() != nullptr &&
		map->getCell(point)->getCellElement()->getEntity() == Entity::PLAYER);
}

void Enemy::interact()
{
}

Enemy::Enemy(int damage, int health, int attackSpeed, Point mapPosition) {
	this->speedAttack = attackSpeed;
	m_damage = damage;
	m_health = health;
	m_mapPosition = mapPosition;

}

int Enemy::attack() {
	return m_damage;
}

void Enemy::takeDamage(int damage) {
	m_health -= damage;
	if (m_health <= 0) {
		m_health = 0;
	}
}

Entity Enemy::getEntity()
{
	return entity;
}

void Enemy::setEntity(Entity ent) {
	entity = ent;
}



int Enemy::getHealth()
{
	return m_health;
}

Point Enemy::getMapPosition() {
	return m_mapPosition;
}

void Enemy::setMapPosition(Point mapPosition) {
	m_mapPosition = mapPosition;
}


bool Enemy::isAvaliable()
{
	return avaliable;
}

void Enemy::disable() {
	avaliable = false;
}

std::string Enemy::getData()
{
	std::string res = "";
	res = res +
		std::to_string((int)entity) + " " +
		std::to_string(m_mapPosition.x) + ' ' + std::to_string(m_mapPosition.y) + " " +
		std::to_string(m_health) + " " +
		std::to_string(m_damage);
	return res;
}
