#pragma once
#include <iostream>
#include <algorithm>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}

		const_iterator begin() const
		{
			return (this->c.begin());
		}
		const_iterator end() const
		{
			return (this->c.end());
		}

		MutantStack& operator=( const MutantStack& before );
		MutantStack( const MutantStack& before );
		MutantStack( void );
		~MutantStack();
};

#include "MutantStack.tpp"