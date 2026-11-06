#include "inter.hpp"

template <typename T>
void	iter(T *array, int lenght, T (*function)(T))
{
	for (int i = 0; i < lenght; i++)
	{
		array[i] = function(array[i]);
	}
}

char up(char c)
{
	return (c - 32);
}

int main()
{
	int	ii[] = {'a', 'd', 'g', 'c'};

	std::cout << "before: " << (char)ii[0] << " " << (char)ii[1] << " " << (char)ii[2] << " " << (char)ii[3] << std::endl;
	iter(ii, 4, toupper);
	std::cout << "after: " << (char)ii[0] << " " << (char)ii[1] << " " << (char)ii[2] << " " << (char)ii[3] << std::endl;

	char cc[] = "hola";
	std::cout << "before: " << cc << std::endl;
	iter(cc, 4, up);
	std::cout << "after: " << cc << std::endl;
}