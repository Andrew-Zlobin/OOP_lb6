#include "Ghost.h"
Ghost::Ghost() : Enemy(40, 100, 2, Point(0, 0)) {
	entity = Entity::GHOST;
	speedAttack = 0;
	speedAttackCount = speedAttack;
	avaliable = true;
}

Ghost::Ghost(Point mapPosition, int m_health, int m_damage) : Enemy(m_damage, m_health, 2, mapPosition)
{
	entity = Entity::GHOST;
	speedAttack = 0;
	speedAttackCount = speedAttack;
	avaliable = true;
}

void Ghost::move() {
	Point targetPoint;
	//std::cout << "start move\n";
	int direction = std::rand() % 4;
	switch (direction)
	{
	case 1:
		if (m_mapPosition.y - 2 > 0) {
			targetPoint = Point(m_mapPosition.x, m_mapPosition.y - 2);
		}
		break;
	case 2:
		if (m_mapPosition.y + 2 < map->getheight()) {
			targetPoint = Point(m_mapPosition.x, m_mapPosition.y + 2);
		}
		break;
	case 3:
		if (m_mapPosition.x - 2 > 0) {
			targetPoint = Point(m_mapPosition.x - 2, m_mapPosition.y);
		}
		break;
	case 0:
		if (m_mapPosition.x + 2 < map->getwidth()) {
			targetPoint = Point(m_mapPosition.x + 2, m_mapPosition.y);
		}
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

void Ghost::interact() {
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

Point Ghost::chooseAttackDirection() {
	Point dirPoint;

	dirPoint = m_mapPosition;
	dirPoint.y -= 2;
	if (dirPoint.y > 0) {
		if (detectPlayer(dirPoint)) {
			return dirPoint;
		}
	}

	dirPoint = m_mapPosition;
	dirPoint.y += 2;
	if (dirPoint.y < map->getheight() - 1) {
		if (detectPlayer(dirPoint)) {
			return dirPoint;
		}
	}

	dirPoint = m_mapPosition;
	dirPoint.x -= 2;
	if (dirPoint.x > 0) {
		if (detectPlayer(dirPoint)) {
			return dirPoint;
		}
	}

	dirPoint = m_mapPosition;
	dirPoint.x += 2;
	if (dirPoint.x < map->getwidth() - 1) {
		if (detectPlayer(dirPoint)) {
			return dirPoint;
		}
	}
	return Point(0, 0);
}

std::string Ghost::GetLog()
{
	return "type: Ghost\nhealth: " + std::to_string(m_health) + " \ndamage: " + std::to_string(m_damage) +
		" \ncoord: (" + std::to_string(m_mapPosition.x) + ", " + std::to_string(m_mapPosition.y) + ")"
		+ "\nIs avaliable" + std::to_string(avaliable) +
		+" \n//-----------\n";;
}
