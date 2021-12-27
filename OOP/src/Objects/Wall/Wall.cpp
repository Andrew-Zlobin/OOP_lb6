#include "Wall.h"

Wall::Wall() {
    entity = Entity::WALL;
}
Wall::Wall(Point mapPosition) {
    entity = Entity::WALL;
    m_mapPosition = mapPosition;
}

int Wall::getHealth() {
    return 1;
}

Entity Wall::getEntity() {
    return entity;
}

void Wall::setEntity(Entity ent) {}

Point Wall::getMapPosition() {
    return m_mapPosition;
}

void Wall::setMapPosition(Point mapPosition) {
    m_mapPosition = mapPosition;
}

CustomTexture* Wall::getTexture() {
    return texture;
}

void Wall::setTexture(CustomTexture *t) {
    texture = t;
}

void Wall::update()
{
}

int Wall::attack()
{
    return 0;
}

std::string Wall::GetLog()
{
    return "Wall\n//-----------\n";
}

void Wall::takeDamage(int health)
{
}



bool Wall::isAvaliable() {
    return avaliable;
}
void Wall::disable() {
    avaliable = false;
}

std::string Wall::getData()
{
    std::string res = "";
    res = res +
        std::to_string((int)entity) + " " +
        std::to_string(m_mapPosition.x) + " " + std::to_string(m_mapPosition.y);
    return res;
}

