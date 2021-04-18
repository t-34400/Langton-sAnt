#include "Field.h"

Field::Field(std::size_t maxX, std::size_t maxY)
	:m_maxX{ maxX }, m_maxY{ maxY }
{
	m_fieldColor.resize(m_maxX * m_maxY);
	clear();
}

void Field::addAnt(AbstructAnt&& ant, int x, int y)
{

}

void Field::stepForward(int n)
{

}

void Field::getColor(std::size_t x, std::size_t y) { return m_fieldColor[x + y * m_maxX]; }

void Field::clear()
{
	for (auto& color : m_fieldColor)
		color = 0;
}

friend std::ostream& Field::operator<<(std::ofstream& out, const Field& field)
{

}