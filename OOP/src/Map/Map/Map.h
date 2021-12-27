#pragma once
#include "../Cell/Cell.h"
#include "../../Objects/Wall/Wall.h"

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

class Map {
private:
	int m_width;
	int m_height;
	Cell** m_map;
	Point m_start;
	Point m_finish;

public:

	Map();
	~Map();

	friend void swap(Map& map1, Map& map2);

	Map(const Map& other);
	Map& operator=(const Map& other);
	Map(Map&& other);
	Map& operator=(Map&& other);

	void clean();

	int getwidth();
	int getheight();
	Cell* getCell(Point point);
	
	void setStartAndFinish(Point start, Point finish);

	void loadMap(char* filepath);
	Point getStartPoint();
	Point getFinishPoint();
	

private:
	Cell** makeEmptyMap();
};


