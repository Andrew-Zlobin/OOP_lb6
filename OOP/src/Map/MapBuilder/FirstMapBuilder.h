#ifndef GAME_FIRSTMAPBUILDER_H
#define GAME_FIRSTMAPBUILDER_H

#include "MapBuilder.h"
#include "../Map/Map.h"
#include "../Cell/Cell.h"

class FirstMapBuilder : public MapBuilder{
private:
    Map* map;
public:
    FirstMapBuilder();
    ~FirstMapBuilder();
    void Reset();
    void BuildEnter() override;
    void BuildExit() override;
    void BuildWalls() override;
    Map* ReturnMap() override;
};

#endif //GAME_FIRSTMAPBUILDER_H
