#include "tester/tester.hpp"

int main(void){

	ivector t;
	ivector::reverse_iterator it = t.rbegin();
	ivector::const_reverse_iterator cit = t.rbegin();

	std::vector<int>::iterator it2;
	std::vector<int>::const_iterator cit2;
	std::vector<int>::const_iterator it3;

	if (cit == it)
	std::cout << "Error" << std::endl;

	std::vector<int> t;
	t.clear();

}
