#pragma once

#include <cstdlib>
#include "../ICellElement.h"
#include "../../Point/Point.h"
#include "../Configuration.h"

class Cell {
private:
	ICellElement* m_cellElement;
	Configuration m_config;
	Point mapPosition;
public:
	Cell(ICellElement* cellElement = nullptr, Entity entity = Entity::EMPTY, Configuration config = Configuration::CELL);
	Cell(const Cell& other);
	Cell& operator = (const Cell& other);
	Cell(Cell&& other);
	Cell& operator = (Cell&& other);
	friend void swap(Cell& obj1, Cell& obj2);
	~Cell();


	ICellElement* getCellElement();
	void setCellElement(ICellElement* cellElemnt);
	void setConfiguration(Configuration conf);
	Configuration getConfiruration();
	void setMapPosition(Point point);
	Point getMapPosition();
};

