#pragma once
#include "../../Point/Point.h"
#include "../../Map/ICellElement.h"
#include "Direction.h"

class Unit :
    public ICellElement
{    
public:
    
    virtual void update() = 0;
    virtual void interact() = 0;
};

