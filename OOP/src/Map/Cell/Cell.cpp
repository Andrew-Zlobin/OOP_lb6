#include "Cell.h"



Cell::Cell(ICellElement* cellElement, Entity entity, Configuration config) :
	m_cellElement(cellElement), m_config(config) {};

Cell::Cell(const Cell& other) {
	this->m_cellElement = other.m_cellElement;
	this->m_config = other.m_config;
}

Cell& Cell::operator=(const Cell& other)
{
	if (this != &other) {
		this->m_cellElement = other.m_cellElement;
		this->m_config = other.m_config;
	}
	return *this;
}

Cell::Cell(Cell&& other) {
	swap(*this, other);
}

Cell& Cell::operator = (Cell&& other) {
	if (this != &other) {
		swap(*this, other);
	}
	return *this;
}

Cell::~Cell() { }

ICellElement* Cell::getCellElement() {
	return m_cellElement;
}
void Cell::setCellElement(ICellElement* cellElemnt)
{
	//if (cellElemnt != nullptr) {
	//	cellElemnt->setMapPosition(mapPosition);
	//}
	//std::cout << mapPosition.getX() << ' ' << mapPosition.getY() << '\n';
	m_cellElement = cellElemnt;
}


void Cell::setConfiguration(Configuration conf) {
	m_config = conf;
}

Configuration Cell::getConfiruration()
{
	return m_config;
}

void Cell::setMapPosition(Point point) {
	mapPosition = point;
}

Point Cell::getMapPosition() {
	return mapPosition;
}


void swap(Cell& obj1, Cell& obj2) {
	std::swap(obj1.m_config, obj2.m_config);
	std::swap(obj1.m_cellElement, obj2.m_cellElement);
}
