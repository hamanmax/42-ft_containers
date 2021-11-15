#include <vector>
#include <iostream>
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
	std::vector<int> t;
	Vector p();
	t.rbegin();
	t.begin();
	std::cout << sizeof(ddd) << std::endl;
	std::cout << sizeof(std::vector<int>) << std::endl;
	//p.push
}
