#pragma once
#include "../Unit.h"
#include "../../../Map/Map/Map.h"
#include "../../../Point/Point.h"

class Enemy :
    public Unit
{
protected:
    int speedAttack;
    int speedAttackCount;
    Enemy(int damage, int health, int attackSpeed, Point mapPosition);
    Map* map;

    int m_damage;
    int m_health;
    Point m_mapPosition;
    Entity entity;
    bool avaliable;
public:
    Enemy();

    virtual std::string GetLog();
    void setMap(Map *m);
    void update();
    virtual void move();
    virtual bool detectPlayer(Point point);
    virtual void interact();

    int attack();
    void takeDamage(int damage);

    virtual Entity getEntity();
    virtual void setEntity(Entity ent);

    virtual int getHealth();
    virtual Point getMapPosition();
    virtual void setMapPosition(Point mapPosition);

    virtual bool isAvaliable();
    virtual void disable();

    virtual std::string getData();
};

