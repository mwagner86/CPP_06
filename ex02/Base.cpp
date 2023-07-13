#include "Base.hpp"

Base::~Base() {}

Base *	generate(void) {
	Base * output = NULL;
	int	random = -1;

	random = rand() % 3;
	std::cout << random << std::endl;
	switch (random)	{
		case 0:
			output = new A();
			break;
		case 1:
			output = new B();
			break;
		case 2:
			output = new C();
			break;
		default:
			output = NULL;
			break;
	}
	return (output);
}

void	identify(Base * p)
{
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << COLOR_RED << "Base class <A> identified\n" << COLOR_DEFAULT;
		return ;
	}
	if (dynamic_cast<B *>(p) != NULL) {
		std::cout << COLOR_GREEN << "Base class <B> identified\n" << COLOR_DEFAULT;
		return ;
	}
	if (dynamic_cast<C *>(p) != NULL) {
		std::cout << COLOR_BLUE << "Base class <C> identified\n" << COLOR_DEFAULT;
		return ;
	}
}

void	identify(Base & p)
{
	try	{
		(void) dynamic_cast<A &>(p);
		std::cout << COLOR_RED << "Base class <A> identified\n" << COLOR_DEFAULT;
		return ;
	}
	catch (std::exception & e) {
		std::cerr << COLOR_RED << e.what() << COLOR_DEFAULT << std::endl;
	}
	try	{
		(void) dynamic_cast<B &>(p);
		std::cout << COLOR_GREEN << "Base class <B> identified\n" << COLOR_DEFAULT;
		return ;
	}
	catch (std::exception & e) {
		std::cerr << COLOR_GREEN << e.what() << COLOR_DEFAULT << std::endl;
	}
	try	{
		(void) dynamic_cast<C &>(p);
		std::cout << COLOR_BLUE << "Base class <C> identified\n" << COLOR_DEFAULT;
		return ;
	}
	catch (std::exception & e) {
		std::cerr << COLOR_BLUE << e.what() << COLOR_DEFAULT << std::endl;
	}
}
