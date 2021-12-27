#include "SecondMapBuilder.h"

SecondMapBuilder::SecondMapBuilder() {
    Reset();
}
SecondMapBuilder::~SecondMapBuilder(){
    delete map;
}
void SecondMapBuilder::Reset(){
    map = new Map();
    std::cout << "map builded\n";
}


void SecondMapBuilder::BuildWalls() {
    for (int i = 0; i < map->getheight(); i++) {
        Wall* wall = new Wall(Point(0, i));
        map->getCell(Point(0, i))->setCellElement(wall);

        wall = new Wall(Point(map->getwidth() - 1, i));
        map->getCell(Point(map->getwidth() - 1, i))->setCellElement(wall);

    }
    for (int i = 0; i < map->getwidth(); i++) {
        Wall* wall = new Wall(Point(i, 0));
        map->getCell(Point(i, 0))->setCellElement(wall);

        wall = new Wall(Point(i, map->getheight() - 1));
        map->getCell(Point(i, map->getheight() - 1))->setCellElement(wall);
    }

    int direction = 0;
    for (int i = 2; i <= map->getwidth() - 1 - 2; i = i + 2) {
        for (int j = 1; j <= map->getheight() - 1 - 1; j++) {
            direction = rand() % 10 + 1;
            if (direction < 6) {
                Wall* wall = new Wall(Point(i, j));
                map->getCell(Point(i, j))->setCellElement(wall);
            }
        }
    }
    
}

void SecondMapBuilder::BuildExit() {
    map->getCell(Point(map->getwidth() - 2, map->getwidth() - 2))->setConfiguration(Configuration::FINISH);
}

void SecondMapBuilder::BuildEnter() {
    map->getCell(Point(1, 1))->setConfiguration(Configuration::START);
}

Map* SecondMapBuilder::ReturnMap() {
    Map* result = map;
    Reset();
    return result;
}