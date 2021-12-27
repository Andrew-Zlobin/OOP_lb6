#pragma once
#include "../Unit.h"
#include "../../../Map/Map/Map.h"
#include "../../../Point/Point.h"



class Player :
    public Unit
{
private:
    int coins;
    int maxHealth;
    Direction m_direction;
    Map* map;

    int m_damage;
    int m_health;
    Point m_mapPosition;
    Entity entity;
    bool avaliable;
public:
    Player();
    Player(Point mapPosition, int health, int damage, int direction, int maxHealth);
    void setDirection(Direction dir);
    Direction getDirection();
    void setMap(Map * m);

    virtual std::string GetLog();
    void move(Direction direction);
    virtual void interact();
    void takeItem(Point targetPoint);
    //void move(Map * map, Point newPosition);

    int attack();
    void takeDamage(int damage);

    virtual Entity getEntity();
    virtual void setEntity(Entity ent);

    virtual int getHealth();
    virtual Point getMapPosition();
    virtual void setMapPosition(Point mapPosition);
    virtual void update();

    virtual bool isAvaliable();
    virtual void disable();


    virtual std::string getData();
};

