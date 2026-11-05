#include "base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void    identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A derived class" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B derived class" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C derived class" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{}
	std::cout << "Not an A, B, or C derived class4" << std::endl;
}


Base::Base(void)
{
    std::cout << "Base constructor called" << std::endl;
}

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}