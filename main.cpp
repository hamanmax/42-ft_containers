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

typedef ft::map<double,double> ddmap;
typedef ft::pair<double,double> ddpair;
int main(void)
{
	ft::map<int,int> map;
	ft::map<int,int>::iterator it = map.end();
	ddmap d;
	ddpair ddrange[10] = {ddpair(12.89,25.214),ddpair(12.6,8456.51),ddpair(12.7,654.151),ddpair(12.8,45216.232),ddpair(12.9,8425785.22),ddpair(12.91,94655.256),ddpair(12.92,4451.23),ddpair(12.93,666.666),ddpair(12.94,123.321),ddpair(12.95,3.15149)};
	ddmap d3(ddrange,ddrange + 10);
	d.insert(ddpair(12.99,56.45));
	d3.erase(12.7);

	for (ddmap::iterator it = d3.begin(); it != d3.end();it++)std::cout << it->first << std::endl;
	return 0;
}
