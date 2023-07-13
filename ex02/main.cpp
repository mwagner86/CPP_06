#include "Base.hpp"
#include <iostream>

int	main(void)
{
	Base	*BaseObject;
	srand(time(NULL));

	std::cout << DARKBLUE << "GENERATE BASE OBJECT\nObject type:" << COLOR_DEFAULT << std::endl;
	BaseObject = generate();
	std::cout << COLOR_CYAN << "TRY IDENTIFYING BY REFERENCE:" << COLOR_DEFAULT << std::endl;
	identify(BaseObject);
	std::cout << COLOR_PURPLE << "TRY IDENTIFYING BY POINTER:" << COLOR_DEFAULT << std::endl;
	identify(*BaseObject);

	delete BaseObject;

	return (0);
}