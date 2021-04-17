#pragma once
#include <iostream>
#include <vector>

class AbstructAnt;

class Field
{
private:
	const int m_maxX;
	const int m_maxY;

	// field color
	std::vector<int> m_fieldColor;
	// ants
	std::vector<AbstructAnt> m_ants{};

public:
	Field(int x, int y);

	void addAnt(AbstructAnt&& ant, int x = 0, int y = 0);
	void stepForward(int n = 1);

	friend std::ostream& operator<<(std::ofstream& out, Field field);
};