#pragma once
#include "AbstructAnt.h"
#include <iostream>
#include <vector>

class Field
{
private:
	const std::size_t m_maxX;
	const std::size_t m_maxY;

	// field color
	std::vector<AbstructAnt::fieldColor> m_fieldColor;
	// ants
	std::vector<AbstructAnt> m_ants{};

public:
	Field(const std::size_t maxX, const std::size_t maxY) noexcept;

	void addAnt(AbstructAnt&& ant, std::size_t x, std::size_t y);
	void stepForward(const int n = 1);
	int getColor(const std::size_t x, const std::size_t y) const;
	void clear();

	friend std::ostream& operator<<(std::ofstream& out, const Field& field);
};