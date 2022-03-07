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

typedef std::map<int,std::string> smap;
typedef ft::Map<int,std::string> fmap;
typedef std::pair<int,std::string> spair;
typedef ft::pair<int,std::string> fpair;

int main(void)
{
	std::string str("Bonjour");
	std::string str2("Bonsour");
	fmap map;
	//map.end();
	fpair spr[4];
	spr[0] = fpair(1,"tutu");
	spr[1] = fpair(2,"tutu");
	spr[2] = fpair(3,"tutu");
	spr[3] = fpair(4,"tutu");
	fmap fap(spr, spr + 3);
	fmap tap(spr, spr + 4);
	tap.value_comp();
	return 0;
}
