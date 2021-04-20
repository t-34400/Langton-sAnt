#pragma once
#include "AbstructAnt.h"
#include "Point.h"
#include <iostream>
#include <vector>

class Field
{
private:
	const int m_maxX;
	const int m_maxY;

	// field color
	std::vector<AbstructAnt::fieldColor> m_fieldColor;
	// ants
	std::vector<AbstructAnt> m_ants{};
	// the positions of ants
	std::vector<Point> m_antsPositions{};

	void incrementColor(Point::latticeIndex_t index);

public:
	Field(const int maxX, const int maxY) noexcept;

	void addAnt(AbstructAnt&& ant, Point::coordinate_t x = 0, Point::coordinate_t y = 0);
	void stepForward(const int n = 1);
	void clear();

	AbstructAnt::fieldColor getColor(const std::size_t x, const std::size_t y) const;
	std::size_t getAntNumber() const;
	Point getAntsPosition(std::size_t index) const;
	Point getAntsDirection(std::size_t index) const;

	friend std::ostream& operator<<(std::ostream& out, const Field& field);
};