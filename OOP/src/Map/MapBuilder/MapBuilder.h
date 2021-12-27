#ifndef GAME_MAPBUILDER_H
#define GAME_MAPBUILDER_H

#include "../Map/Map.h"

class MapBuilder{
public:
    virtual void BuildEnter();
    virtual void BuildExit();
    virtual void BuildWalls();
    virtual Map* ReturnMap();
};

#endif //GAME_MAPBUILDER_H
