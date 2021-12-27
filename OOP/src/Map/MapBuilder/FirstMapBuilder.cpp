#include "FirstMapBuilder.h"

FirstMapBuilder::FirstMapBuilder() {
    Reset();
    std::cout << "First Builder was called\n";
}
FirstMapBuilder::~FirstMapBuilder() {
    delete map;
}
void FirstMapBuilder::Reset() {
    map = new Map();
    //std::cout << "map builded\n";
}


void FirstMapBuilder::BuildWalls() {
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


    for (int i = 2; i <= map->getwidth() - 1 - 2; i = i + 3) {
        for (int j = 1; j <= map->getheight() - 1 - 1; j = j + 3) {
            Wall* wall = new Wall(Point(i, j));
            map->getCell(Point(i, j))->setCellElement(wall);
        }
    }
}

void FirstMapBuilder::BuildExit() {
    map->getCell(Point(map->getwidth() - 2, map->getwidth() - 2))->setConfiguration(Configuration::FINISH);
}

void FirstMapBuilder::BuildEnter() {
    map->getCell(Point(1, 1))->setConfiguration(Configuration::START);
}

Map* FirstMapBuilder::ReturnMap() {
    Map* result = map;
    Reset();
    return result;
}