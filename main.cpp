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
	std::vector<std::string> t(10);
	Vector p(10);
	Vector &d = p;

	p[9] = 25562;
	t[9] = "Bonjour les amis";
	std::string v = t.back();



	std::cout << t.data()->c_str() << std::endl;
	int j = p.front();

	t.clear();

	std::cout << t.data() << std::endl;
	//uint64_t *x = (uint64_t *)(void *)&p;
	//std::cout << std::hex << x[0] << ' ' << x[1] << ' ' << x[2] << std::endl;
	//p.push
}
