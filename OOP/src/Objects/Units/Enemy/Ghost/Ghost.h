#pragma once
#include "../Enemy.h"
class Ghost :
    public Enemy
{
public:
    Ghost();
    Ghost(Point mapPosition, int m_health, int m_damage);
    void move() final;
    virtual void interact() final;

    Point chooseAttackDirection();
    std::string GetLog() final;
};

