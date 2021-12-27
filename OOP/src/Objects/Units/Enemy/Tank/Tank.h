#include "../Enemy.h"

class Tank : public Enemy {

public:
    Tank();
    Tank(Point mapPosition, int m_health, int m_damage);
    virtual void move() final;
    virtual void interact() final;

    Point chooseAttackDirection();
    std::string GetLog() final;
};