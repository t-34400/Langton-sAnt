#pragma once
#include "AbstructAnt.h"
#include "Point.h"
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
	// the positions of ants
	std::vector<Point> m_antsPositions{};

	void incrementColor(Point::latticeIndex_t index);

public:
	Field(const std::size_t maxX, const std::size_t maxY) noexcept;

	void addAnt(AbstructAnt&& ant, std::size_t x = 0, std::size_t y = 0);
	void stepForward(const int n = 1);
	void clear();

	AbstructAnt::fieldColor getColor(const std::size_t x, const std::size_t y) const;
	std::size_t getAntNumber() const;
	Point getAntsPositions(std::size_t index) const;

	friend std::ostream& operator<<(std::ostream& out, const Field& field);
};