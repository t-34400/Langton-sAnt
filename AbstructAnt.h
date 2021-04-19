#pragma once
#include <string>
#include <vector>

class AbstructAnt
{
public:
	enum direction
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		max_direction_index
	};
	enum turn
	{
		Left = -1,
		Right = 1
	};
	using direction_t = int;
	using turn_t = int;
	using fieldColor = int;

private:
	direction_t m_direction{};
	std::vector<turn_t> m_turnDirections;
	std::size_t m_directionsLength{};

public:
	AbstructAnt(const std::vector<turn_t>& turnDirections = { turn::Left,turn::Right }, direction_t direction = direction::UP);
	AbstructAnt(const std::string& turnDirections, direction_t direction = direction::UP);

	direction_t getNextDirection(fieldColor color);
};