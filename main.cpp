#include "Field.h"
#include <iostream>

int main()
{
	Field field(20, 20);
	field.addAnt(AbstructAnt("LR"));
	for (int count{ 0 }; count < 20; ++count)
	{
		std::cout << field<<'\n';
		field.stepForward();
		std::size_t maxAntIndex{ field.getAntNumber() };
		for (std::size_t antIndex{ 0 }; antIndex < maxAntIndex; ++antIndex)
			std::cout << "Ant " << antIndex << " is at (" << field.getAntsPosition(antIndex) << ")\n\n";
	}
	return 0;
}