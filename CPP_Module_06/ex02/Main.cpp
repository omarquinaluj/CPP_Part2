#include "base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
    int random;
    random = std::rand() % 3;
    if (random == 0)
        return (new A());
    if (random == 1)
        return (new B());
    return (new C());
}

int	main(void)
{
	Base	*p;

	std::srand(std::time(NULL));

	p = generate();

	std::cout << "identify(pointer): ";
	identify(p);

	std::cout << "identify(reference): ";
	identify(*p);

	delete p;
	return (0);
}