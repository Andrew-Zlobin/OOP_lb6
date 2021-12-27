#include "Tank.h"

Tank::Tank() : Enemy(10, 200, 2, Point(0, 0)) {
	entity = Entity::TANK;
	speedAttack = 1;
	speedAttackCount = speedAttack;
	avaliable = true;
}

Tank::Tank(Point mapPosition, int m_health, int m_damage) : Enemy(m_damage, m_health, 2, mapPosition)
{
	entity = Entity::TANK;
	speedAttack = 1;
	speedAttackCount = speedAttack;
	avaliable = true;
}

void Tank::move() {
	Point targetPoint;
	//std::cout << "start move\n";
	int direction = std::rand() % 7;
	switch (direction)
	{
	case 1:
		targetPoint = Point(m_mapPosition.x, m_mapPosition.y - 1);
		break;
	case 2:
		targetPoint = Point(m_mapPosition.x, m_mapPosition.y + 1);
		break;
	case 3:
		targetPoint = Point(m_mapPosition.x - 1, m_mapPosition.y);
		break;
	case 0:
		targetPoint = Point(m_mapPosition.x + 1, m_mapPosition.y);
		break;
	default:
		break;
	}

	if (map->getCell(targetPoint)->getCellElement() == nullptr) {

		map->getCell(targetPoint)->setCellElement(map->getCell(m_mapPosition)->getCellElement());
		map->getCell(m_mapPosition)->setCellElement(nullptr);
		m_mapPosition = targetPoint;
	}
}

void Tank::interact() {
	Point targetPoint = chooseAttackDirection();
	if (map->getCell(targetPoint)->getCellElement() != nullptr &&
		map->getCell(targetPoint)->getCellElement()->getEntity() == Entity::PLAYER) {
		if (speedAttackCount == 0) {
			map->getCell(targetPoint)->getCellElement()->takeDamage(m_damage);
			speedAttackCount = speedAttack;
		}
		else {
			speedAttackCount--;
		}
	}
	else {
		speedAttackCount = speedAttack;
	}
}

Point Tank::chooseAttackDirection() {
	Point dirPoint;

	dirPoint = m_mapPosition;
	dirPoint.y -= 1;
	if (detectPlayer(dirPoint)) {
		return dirPoint;
	}

	dirPoint = m_mapPosition;
	dirPoint.y += 1;
	if (detectPlayer(dirPoint)) {
		return dirPoint;
	}

	dirPoint = m_mapPosition;
	dirPoint.x -= 1;
	if (detectPlayer(dirPoint)) {
		return dirPoint;
	}

	dirPoint = m_mapPosition;
	dirPoint.x += 1;
	if (detectPlayer(dirPoint)) {
		return dirPoint;
	}
	return Point(0, 0);
}

std::string Tank::GetLog()
{
	return "type: Tank\nhealth: " + std::to_string(m_health) + " \ndamage: " + std::to_string(m_damage) +
		" \ncoord: (" + std::to_string(m_mapPosition.x) + ", " + std::to_string(m_mapPosition.y) + ")"
		+ "\nIs avaliable" + std::to_string(avaliable) +
		+" \n//-----------\n";
}

