#include "Point.h"
#include <cassert>

Point::Point(coordinate_t maxX, coordinate_t maxY, coordinate_t x, coordinate_t y)
	:m_maxX{ maxX }, m_maxY{ maxY }, m_x{ x }, m_y{ y }
{
	assert(m_maxX > 0 && m_maxY > 0);
}

Point::latticeIndex_t Point::up()
{ 
	if (m_x >= m_maxX - 1)
		m_x = 0;
	else
		++m_x;
	return getLatticeIndex();
}
Point::latticeIndex_t Point::right()
{
	if (m_y >= m_maxY - 1)
		m_y = 0;
	else
		++m_y;
	return getLatticeIndex();
}
Point::latticeIndex_t Point::down()
{
	if (m_x <= 0)
		m_x = m_maxX - 1;
	else
		--m_x;
	return getLatticeIndex();
}
Point::latticeIndex_t Point::left()
{
	if (m_y <= 0)
		m_y = m_maxY - 1;
	else
		--m_y;
	return getLatticeIndex();
}

Point::latticeIndex_t Point::getLatticeIndex() const { return m_x + m_y * m_maxX; }

std::ostream& operator<<(std::ostream& out, const Point& point)
{
	out << point.m_x << ',' << point.m_y;
	return out;
}
