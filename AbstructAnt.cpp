#include "AbstructAnt.h"

AbstructAnt::AbstructAnt(const std::vector<turn_t>& turnDirections, direction_t direction)
	:m_turnDirections{ turnDirections }, m_direction{ direction }, m_directionsLength{ turnDirections.size() }
{
}

AbstructAnt::AbstructAnt(const std::string& turnDirections, direction_t direction)
	:m_direction{ direction }, m_directionsLength{ turnDirections.size() }
{
	// allocate memory
	m_turnDirections.reserve(turnDirections.size());

	for (auto& let : turnDirections)
	{
		if (let == 'L' || let == 'l')
		{
			m_turnDirections.push_back(turn::Left);
		}
		else if (let == 'R' || let == 'r')
		{
			m_turnDirections.push_back(turn::Right);
		}
	}
}

AbstructAnt::direction_t AbstructAnt::getNextDirection(fieldColor color)
{
	turn_t turnDirection{ m_turnDirections.at(color % m_directionsLength) };
	// add max_direction_index so that m_direction has the value in [0, max_direction_index] 
	m_direction = (m_direction + direction::max_direction_index + turnDirection) % direction::max_direction_index;
	return m_direction;
}