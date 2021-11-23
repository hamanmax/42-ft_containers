#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>
#include "Vector.hpp"

int main(int argc, char **argv)
{
	std::vector<int> b(15,100);
	std::vector<int> t2(8,0);
	ft::Vector<int> t(15,100);

	// ft::Vector<int>::iterator it = b.begin();
	//int myarray [] = { 501,502,503 };
	//t.reserve(250);
	for(ft::Vector<int>::iterator it = t.begin(); it != t.end();it++)
	{
		*it = rand() % 35000;
		std::cout << *it << std::endl;
	}
	t.insert(t.begin(), 250);
		std::cout << "////////////////////////" << std::endl;
	for(ft::Vector<int>::iterator it = t.begin(); it != t.end();it++)
	{
		std::cout << *it << std::endl;
	}
	//t.push_back(12);
	std::cout << "t.size = " << t.size() << "\tt.capacity = " << t.capacity() << std::endl;
	//std::cout << "b.capacity = " << b.capacity() << "\tt.capacity = " << t.capacity() << std::endl;
	//uint64_t *x = (uint64_t *)(void *)&p;
	//std::cout << std::hex << x[0] << ' ' << x[1] << ' ' << x[2] << std::endl;
	//p.push
}
