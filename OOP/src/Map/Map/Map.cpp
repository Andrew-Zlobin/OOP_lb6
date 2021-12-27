#include "Map.h"


Map::Map()
{
	m_width = MAP_WIDTH;
	m_height = MAP_HEIGHT;
	m_start = Point(1, 2);
	m_finish = Point(m_width - 2, m_height - 2);
	m_map = makeEmptyMap();
	setStartAndFinish(m_start, m_finish);
}

Map::~Map() {
	if (m_map) {
		clean();
	}
}


void Map::clean() {
	for (int i = 0; i < m_height; i++) {
		delete[] m_map[i];
	}

	delete[] m_map;
}

Map::Map(const Map& other) {
	m_start = other.m_start;
	m_height = other.m_height;
	m_width = other.m_width;
	m_finish = other.m_finish;
	m_map = new Cell * [m_height];
	for (int i = 0; i < m_height; i++) {
		m_map[i] = new Cell[m_width];
		for (int j = 0; j < m_width; j++) {
			m_map[i][j] = other.m_map[i][j];
		}
	}
}



Map& Map::operator=(const Map& other)
{
	if (this != &other) {
		m_start = other.m_start;
		m_height = other.m_height;
		m_width = other.m_width;
		m_finish = other.m_finish;
		clean();
		m_map = new Cell * [m_height];
		for (int i = 0; i < m_height; i++) {
			m_map[i] = new Cell[m_width];
			for (int j = 0; j < m_width; j++) {
				m_map[i][j] = other.m_map[i][j];
			}
		}
	}
	return *this;
}

Map& Map::operator=(Map&& other) {
	if (this != &other) {
		swap(*this, other);
	}
	return *this;
}


Map::Map(Map&& other) {
	swap(*this, other);
}

int Map::getwidth()
{
	return m_width;
}

int Map::getheight()
{
	return m_height;
}

Cell * Map::getCell(Point point)
{
	
	return &m_map[point.x][point.y];
}



void Map::setStartAndFinish(Point start, Point finish) {
	if (start.IsNeighbor(finish)) {
		start = Point(1, 1);
		finish = Point(m_width - 2, m_height - 2);
	}
	m_start = start;
	m_finish = finish;
	std::cout << m_start.x << ' ' << m_start.y << '\n';
	m_map[start.x][start.y].setConfiguration(Configuration::START);
	m_map[finish.x][finish.y].setConfiguration(Configuration::FINISH);
}


Point Map::getStartPoint()
{
	return m_start;
}

Point Map::getFinishPoint()
{
	return m_finish;
}


Cell** Map::makeEmptyMap() {
	Cell ** map = new Cell * [m_width];
	for (int i = 0; i < m_width; i++) {
		map[i] = new Cell[m_height];
		for (int j = 0; j < m_height; j++) {
			map[i][j].setCellElement(nullptr);
			map[i][j].setMapPosition(Point(i, j));
		}
	}
	return map;
}




void swap(Map& map1, Map& map2) {
	std::swap(map1.m_start, map2.m_start);
	std::swap(map1.m_finish, map2.m_finish);
	std::swap(map1.m_width, map2.m_width);
	std::swap(map1.m_height, map2.m_height);
	std::swap(map1.m_map, map2.m_map);

}
