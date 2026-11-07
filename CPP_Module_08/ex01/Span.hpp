#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	vector;
		unsigned long		maxInts;

	public:
		class	noSpanFound : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("Can't get the span");
				}
		};
		class	maxIntsReached : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return ("The container is full");
				}
		};

		void	fillSpan( int min, int max );
		void	addNumber( int i );
		int		longestSpan();
		int		shortestSpan();
		Span( unsigned int n );
		~Span();
};