//#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>
#include "Vector.hpp"
#include <vector>
#include <string>

int main(int argc, char **argv)
{
	// * True Vector
	std::vector<int> s(2);
	ft::Vector<int> f(2);
	ft::Vector<int> f2(150);
	ft::Vector<int>::reverse_iterator it(f.rbegin());

	std::cout << *it << std::endl;
	f.reserve(15);
}
