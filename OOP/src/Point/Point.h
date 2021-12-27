#pragma once
#include <iostream>
#include <cstdlib>
class Point {
public:
	int x;
	int y;
	Point(int c_x, int c_y);
	Point();

	bool IsNeighbor(Point p);
};
