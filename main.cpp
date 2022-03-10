#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <map>
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <stack>
#include <vector>
#include <string>
#include "reverse_iterator.hpp"

typedef std::map<
int,std::string> smap;
typedef ft::map<int,std::string> fmap;
typedef std::pair<int,std::string> spair;
typedef ft::pair<int,std::string> fpair;

int main(void)
{
	ft::vector<int> vector(12);
	vector[11] = 12;
	vector[9] = 25;
	ft::vector<int>::reverse_iterator it = vector.rbegin();
	it = it - 2;
	std::cout << *it << std::endl;
	return 0;
}
