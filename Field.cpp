#include "Field.h"

Field::Field(const int maxX, const int maxY) noexcept
	:m_maxX{ maxX }, m_maxY{ maxY }, m_fieldColor(maxX * maxY)
{
	clear();
}

void Field::addAnt(AbstructAnt&& ant, Point::coordinate_t x, Point::coordinate_t y)
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
			int currentPosition{ m_antsPositions[index].getLatticeIndex() };
			switch (ant.getNextDirection(m_fieldColor[currentPosition]))
			{
			case AbstructAnt::direction::UP:
				m_antsPositions[index].up();
				break;
			case AbstructAnt::direction::RIGHT:
				m_antsPositions[index].right();
				break;
			case AbstructAnt::direction::DOWN:
				m_antsPositions[index].down();
				break;
			case AbstructAnt::direction::LEFT:
				m_antsPositions[index].left();
				break;
			}
			incrementColor(currentPosition);
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
Point Field::getAntsPosition(std::size_t index) const { return m_antsPositions.at(index); }
Point Field::getAntsDirection(std::size_t index) const { return m_antsPositions.at(index); }

std::ostream& operator<<(std::ostream& out, const Field& field)
{
	for (int y{ 0 }; y < field.m_maxY; ++y)
	{
		for (int x{ 0 }; x < field.m_maxX; ++x)
		{
			out << field.getColor(x, y) << ' ';
		}
		out << '\n';
	}
	return out;
}