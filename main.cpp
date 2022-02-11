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
	ft::Vector<int> f(15);
	for (ft::Vector<int>::iterator it = f.begin(); it != f.end();it++) {*it = it - f.begin();}
	std::vector<int> s(15);
	for (std::vector<int>::iterator it = s.begin(); it != s.end();it++) {*it = it - s.begin();}

	std::cout << *f.erase(f.begin() + 2,f.begin() + 5) << std::endl;
	std::cout << *s.erase(s.begin() + 2,s.begin() + 5) << std::endl;
	f.pop_back();
	s.pop_back();
	for (ft::pair<std::vector<int>::iterator, ft::Vector<int>::iterator> i(s.begin(),f.begin());
	i.first != s.end() && i.second != f.end();i.first++,i.second++)
	{std::cout << "S = " << *i.first << " F = " << *i.second << std::endl;}
	std::cout << s.capacity() << std::endl;
}
