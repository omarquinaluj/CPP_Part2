#include "easyfind.hpp"


int main()
{
	std::vector<int> vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);

	if (easyfind(vector, 5) == 0)
		std::cout << "Number 3 found" << std::endl;
	else
		std::cout << "Number 3 not found" << std::endl;
	if (easyfind(vector, 9) == 0)
		std::cout << "Number 9 found" << std::endl;
	else
		std::cout << "Number 9 not found" << std::endl;

	std::vector<int>::iterator iterator = vector.begin();
	while (iterator != vector.end())
	{
		std::cout << *iterator << " ";
		++iterator;
	}

	std::cout << "\n";
	std::cout << "\n";

	std::list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(9);

	if (easyfind(list, 3) == 0)
		std::cout << "Number 3 found" << std::endl;
	else
		std::cout << "Number 3 not found" << std::endl;
	if (easyfind(list, 9) == 0)
		std::cout << "Number 9 found" << std::endl;
	else
		std::cout << "Number 9 not found" << std::endl;

	std::list<int>::iterator it = list.begin();
	while (it != list.end()) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << "\n";
}