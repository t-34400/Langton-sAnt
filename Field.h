#pragma once
#include <iostream>
#include <vector>

class AbstructAnt;

class Field
{
private:
	const std::size_t m_maxX;
	const std::size_t m_maxY;

	// field color
	std::vector<int> m_fieldColor;
	// ants
	std::vector<AbstructAnt> m_ants{};

	inline std::size_t incrementX(std::size_t x) const { return (x < m_maxX - 1) ? ++x : 0; }
	inline std::size_t incrementY(std::size_t y) const { return (y < m_maxY - 1) ? ++y : 0; }
	inline std::size_t decrementX(std::size_t x) const { return (x == 0) ? (m_maxX - 1) : --x; }
	inline std::size_t decrementY(std::size_t y) const { return (y == 0) ? (m_maxY - 1) : --y; }

public:
	Field(std::size_t maxX, std::size_t maxY);

	void addAnt(AbstructAnt&& ant);
	void stepForward(int n = 1);
	void getColor(std::size_t x, std::size_t y);
	void clear();

	friend std::ostream& operator<<(std::ofstream& out, const Field& field);
};