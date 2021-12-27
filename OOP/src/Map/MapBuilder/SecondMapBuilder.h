#ifndef GAME_SECONDMAPBUILDER_H
#define GAME_SECONDMAPBUILDER_H

#include "MapBuilder.h"
#include "../Map/Map.h"
#include "../Cell/Cell.h"

class SecondMapBuilder : public MapBuilder{
private:
    Map* map;
public:
    SecondMapBuilder();
    ~SecondMapBuilder();
    void Reset();
    void BuildEnter() override;
    void BuildExit() override;
    void BuildWalls() override;
    Map* ReturnMap() override;
};

#endif //GAME_SECONDMAPBUILDER_H
