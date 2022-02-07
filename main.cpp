//#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>
#include "Vector.hpp"
#include <vector>

int main(int argc, char **argv)
{
	ft::Vector<int> b(15,100);
	b[7] = 8;
	ft::Vector<int> c(b.begin(),b.end());
	std::cout << c[7] << std::endl;
	for (ft::Vector<int>::iterator i = c.begin(); i != c.end(); i++)
	{
		std::cout << *i << std::endl;
	}

}
