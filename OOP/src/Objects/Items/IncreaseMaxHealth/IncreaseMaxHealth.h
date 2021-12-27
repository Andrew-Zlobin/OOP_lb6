#pragma once
#include "../Item.h"
#include <string>
class IncreaseMaxHealth :
    public Item
{
private :
    int increaseMaxHealth;
    Entity entity;
    Point m_mapPosition;
    bool avaliable;
public:
    IncreaseMaxHealth();
    IncreaseMaxHealth(Point mapPosition, int increaseMaxHealth);


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

