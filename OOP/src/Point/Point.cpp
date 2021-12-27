#include "Point.h"

Point::Point(int c_x, int c_y) {
	x = c_x;
	y = c_y;
}

Point::Point() {
	x = 0;
	y = 0;
}


bool Point::IsNeighbor(Point p) {
	return (abs(x - p.x) <= 1 && abs(y - p.y) <= 1);
}


