#ifndef EX02_BASE_HPP
# define EX02_BASE_HPP

#include <cstdlib>
#include <iostream>
#include "colors.hpp"

class Base {

public:
	virtual ~Base(void);

private:
};

class A : virtual public Base {};

class B : virtual public Base {};

class C : virtual public Base {};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif //EX02_BASE_HPP