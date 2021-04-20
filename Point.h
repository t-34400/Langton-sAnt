#pragma once
#include <cstddef>
#include <iostream>

class Point
{
public:
	using coordinate_t = int;
	using latticeIndex_t = int;

private:
	const coordinate_t m_maxX{};
	const coordinate_t m_maxY{};

	coordinate_t m_x{};
	coordinate_t m_y{};


public:
	explicit Point(coordinate_t maxX, coordinate_t maxY, coordinate_t x, coordinate_t y);

	latticeIndex_t up();
	latticeIndex_t right();
	latticeIndex_t down();
	latticeIndex_t left();

	latticeIndex_t getLatticeIndex() const;

	friend std::ostream& operator<<(std::ostream& out, const Point& point);
};