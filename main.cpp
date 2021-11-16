#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
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
	int *ptr;
	void *ddd;
	std::vector<int> t(10);
	Vector p(10);
	t.push_back(15);
	t.push_back(15);
	t.push_back(15);

	p[2] = 1265465;

	std::cout << p[2] << std::endl;
	//uint64_t *x = (uint64_t *)(void *)&p;
	//std::cout << std::hex << x[0] << ' ' << x[1] << ' ' << x[2] << std::endl;
	//p.push
}
