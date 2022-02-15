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
	std::map<int, std::string> map1;
	map1[0] = "Bonjour";
	map1[1] = "a";
	map1[2] = "tous";
	map1[30] = "les";
	map1[15] = "humains";
	map1[17] = "beau";
	map1[25] = "goss";
	for (std::map<int, std::string>::iterator it = map1.begin(); it != map1.end();it++) {
		std::cout << it->first << std::endl;
	}
	std::cout << sizeof(map1) << std::endl;
}
