#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "Vector.hpp"

void test(int *data, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << *data << std::endl;
		data++;
	}
}

int main(int argc, char **argv)
{
	std::vector<int> t(11);
	std::vector<int> p(2);

	Vector b(20);
	for(Vector::iterator it = b.begin(); it != b.end();it++)
	{
		*it = random() % 35652;
		std::cout << *it << std::endl;
	}

	std::cout << b.size() << std::endl;
	b.push_back(12);

	//uint64_t *x = (uint64_t *)(void *)&p;
	//std::cout << std::hex << x[0] << ' ' << x[1] << ' ' << x[2] << std::endl;
	//p.push
}
