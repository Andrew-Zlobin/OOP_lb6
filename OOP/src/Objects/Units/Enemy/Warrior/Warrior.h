#pragma once
#include "../Enemy.h"
class Warrior :
    public Enemy
{
public:
    Warrior();
    Warrior(Point mapPosition, int m_health, int m_damage);
    void move() final;
    void interact() final;
    
    Point chooseAttackDirection();
    std::string GetLog() final;
};

