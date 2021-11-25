#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>
#include "Vector.hpp"

int main(int argc, char **argv)
{
	std::vector<int> t(15,100);
	std::vector<int> t2(8,0);
	ft::Vector<int> b(15,100);

	for(std::vector<int>::iterator it = t.begin(); it != t.end();it++)
	{
		*it = rand() % 35000;
		std::cout << *it << std::endl;
	}
	std::vector<int>::iterator it = t.end();
	it -= 2;
	std::cout<<  << std::endl;
	std::cout << "t.size = " << t.size() << "\tt.capacity = " << t.capacity() << std::endl;
}
