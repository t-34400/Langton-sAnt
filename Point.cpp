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
	return m_x;
}
Point::latticeIndex_t Point::right()
{
	if (m_y >= m_maxY - 1)
		m_y = 0;
	else
		++m_y;
	return m_y;
}
Point::latticeIndex_t Point::down()
{
	if (m_x <= 0)
		m_x = m_maxX - 1;
	else
		--m_x;
	return m_x;
}
Point::latticeIndex_t Point::left()
{
	if (m_y <= 0)
		m_y = m_maxY - 1;
	else
		--m_y;
	return m_y;
}