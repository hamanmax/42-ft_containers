//#include <vector>
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

int main(void)
{
	ft::pair<int,std::string> pair[5];
	pair[1] = ft::pair<int,std::string>(4,"4");
	pair[2] = ft::pair<int,std::string>(2,"2");
	pair[3] = ft::pair<int,std::string>(12,"3");
	pair[4] = ft::pair<int,std::string>(4,"4");
	pair[0] = ft::pair<int,std::string>(5,"0");
	//std::map<int, std::string> map1(pair,pair+4);
	ft::Map<int, std::string> map2(pair,pair + 4);
	ft::Map<int, std::string> map3(map2);
	// 	std::cout << it->first << std::endl;
	// }
	// std::cout << sizeof(map1) << std::endl;
}
