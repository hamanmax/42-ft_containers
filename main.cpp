#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>
#include "Vector.hpp"
#include "Stack.hpp"
#include "Map.hpp"
#include <stack>
#include <vector>
#include <string>
#include "ReverseIterator.hpp"

typedef std::map<
int,std::string> smap;
typedef ft::Map<int,std::string> fmap;
typedef std::pair<int,std::string> spair;
typedef ft::pair<int,std::string> fpair;

int main(void)
{
	ft::Vector<int> vector(12);
	vector[11] = 12;
	vector[9] = 25;
	ft::Vector<int>::reverse_iterator it = vector.rbegin();
	it = it - 2;
	std::cout << *it << std::endl;
	return 0;
}
