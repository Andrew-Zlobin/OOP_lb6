#pragma once
#include "../Item.h"
class IncreaseDamage :
    public Item
{
private:
    int increaseDamage;
    Entity entity;
    Point m_mapPosition;
    bool avaliable;
public:
    IncreaseDamage();
    IncreaseDamage(Point mapPosition, int increaseDamage);
    int getHealth() final;

    Entity getEntity() final;

    void setEntity(Entity ent) final;

    Point getMapPosition() final;

    void setMapPosition(Point mapPosition) final;

    int attack() final;

    void takeDamage(int health) final;

    std::string GetLog() final;

    bool isAvaliable() final;

    void disable() final;

    std::string getData() final;
};


