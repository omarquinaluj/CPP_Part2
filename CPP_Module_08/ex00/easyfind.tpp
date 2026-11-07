#include "easyfind.hpp"

template <typename T>
int easyfind(T a, int i)
{
	typename T::const_iterator iterator = std::find(a.begin(), a.end(), i);
	if (iterator == a.end())
		return (-1);
	return (0);
}