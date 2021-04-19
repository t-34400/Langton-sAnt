#pragma once
#include <cstddef>

class Point
{
public:
	using coordinate_t = std::size_t;
	using latticeIndex_t = std::size_t;

private:
	const coordinate_t m_maxX{};
	const coordinate_t m_maxY{};

	coordinate_t m_x{};
	coordinate_t m_y{};

public:
	Point(coordinate_t maxX, coordinate_t maxY, coordinate_t x, coordinate_t y);

	latticeIndex_t up();
	latticeIndex_t right();
	latticeIndex_t down();
	latticeIndex_t left();
};