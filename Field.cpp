#include "Field.h"

Field::Field(const std::size_t maxX, const std::size_t maxY) noexcept
	:m_maxX{ maxX }, m_maxY{ maxY }
{
	m_fieldColor.resize(m_maxX * m_maxY);
	clear();
}

void Field::addAnt(AbstructAnt&& ant, std::size_t x, std::size_t y)
{
	m_ants.push_back(ant);
	m_antsPositions.push_back(Point{ m_maxX,m_maxY,x,y });
}

void Field::incrementColor(Point::latticeIndex_t index) { ++m_fieldColor[index]; }

void Field::stepForward(const int n)
{
	for (int count{ 0 }; count < n; ++count)
	{
		std::size_t index{ 0 };
		for (auto& ant : m_ants)
		{
			switch (ant.getNextDirection(m_fieldColor[m_antsPositions[index].getLatticeIndex()]))
			{
			case AbstructAnt::direction::UP:
				incrementColor(m_antsPositions[index].up());
			case AbstructAnt::direction::RIGHT:
				incrementColor(m_antsPositions[index].right());
			case AbstructAnt::direction::DOWN:
				incrementColor(m_antsPositions[index].down());
			case AbstructAnt::direction::LEFT:
				incrementColor(m_antsPositions[index].left());
			}
			++index;
		}
	}
}

void Field::clear()
{
	for (auto& color : m_fieldColor)
		color = 0;
}

int Field::getColor(const std::size_t x, const std::size_t y) const { return m_fieldColor[x + y * m_maxX]; }
std::size_t Field::getAntNumber() const { return m_ants.size(); }
Point Field::getAntsPositions(std::size_t index) const { return m_antsPositions.at(index); }

std::ostream& operator<<(std::ostream& out, const Field& field)
{
	for (std::size_t y{ 0 }; y < field.m_maxY; ++y)
	{
		for (std::size_t x{ 0 }; x < field.m_maxX; ++x)
		{
			out << field.getColor(x, y) << ' ';
		}
		out << '\n';
	}
	return out;
}