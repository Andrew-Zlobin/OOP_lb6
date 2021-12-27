#pragma once
#include "../../Map/ICellElement.h"
#include <string>
class Item :
    public ICellElement
{
    virtual std::string getData() = 0;
};

