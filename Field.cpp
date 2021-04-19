#include "Field.h"

Field::Field(const std::size_t maxX, const std::size_t maxY) noexcept
	:m_maxX{ maxX }, m_maxY{ maxY }
{
	m_fieldColor.resize(m_maxX * m_maxY);
	clear();
}

void Field::addAnt(AbstructAnt&& ant)
{
	m_ants.push_back(ant);
}

void Field::stepForward(const int n)
{

}

int Field::getColor(const std::size_t x, const std::size_t y) const { return m_fieldColor[x + y * m_maxX]; }

void Field::clear()
{
	for (auto& color : m_fieldColor)
		color = 0;
}

std::ostream& operator<<(std::ofstream& out, const Field& field)
{

}