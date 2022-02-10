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
	// * True Vector
	std::vector<int> s(15);
	std::vector<int> s2(5);
	ft::Vector<int> f(15);
	ft::Vector<int> f2(5);
	for (std::vector<int>::iterator i = s.begin(); i != s.end();i++){*i = i - s.begin();}
	for (std::vector<int>::iterator i = s2.begin(); i != s2.end();i++){*i = i - s2.begin() + 100;}
	for (ft::Vector<int>::iterator i = f.begin(); i != f.end();i++){*i = i - f.begin();}
	for (ft::Vector<int>::iterator i = f2.begin(); i != f2.end();i++){*i = i - f2.begin() + 100;}
	s.insert(s.begin() + 2,s2.begin(),s2.end());
	f.insert(f.begin() + 2,f2.begin(),f2.end());
	for ( std::pair<std::vector<int>::iterator,ft::Vector<int>::iterator > i(s.begin(),f.begin()); i.first != s.end();i.first++,i.second++){
		std::cout << "True Vector =\t" << *i.first << "\tMy Vector = " << *i.second << std::endl;}

	}
