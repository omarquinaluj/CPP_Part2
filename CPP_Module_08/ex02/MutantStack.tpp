#include "MutantStack.hpp"


template<class T>
MutantStack<T>& MutantStack<T>::operator=( const MutantStack<T>& before )
{
	std::stack<T>::operator=(before);
	return (*this);
}

template<class T>
MutantStack<T>::MutantStack( const MutantStack& before ) : std::stack<T>(before)
{
	std::cout << "Default MutantStack Copy Constructor called" << std::endl;
}

template<class T>
MutantStack<T>::MutantStack( void ) : std::stack<T>()
{
	std::cout << "Default MutantStack Constructor called" << std::endl;
}

template<class T>
MutantStack<T>::~MutantStack()
{
	std::cout << "Default MutantStack Destructor called" << std::endl;
}