#include "Stack.hpp"
#include "Vector.hpp"
#include "Utility.hpp"
#include <stack>
#include <vector>
#include <map>

void test_stack_constructor(){

	std::cout << "Default constructor with empty vector<int>" << std::endl;
	ft::Stack<int,std::vector<int> > test;
	ft::Stack<ft::pair<int,int> > test0(ft::Vector<ft::pair<int,int> >(25));
	std::cout << "Stack status = " << (test.empty()? "Empty\t\t": "Not empty\t") << "Stack size = " << test.size() << std::endl;
	std::cout << "\nDefault constructor with a size of 10 uninitialised with a ft::pair" << std::endl;
	ft::Stack<ft::pair<int,int> > test2(ft::Vector<ft::pair<int,int> >(10));
	std::cout << "Stack status = " << (test2.empty()?"Empty\t":"Not empty\t") << "Stack size = " << test2.size() << std::endl;
	std::cout << "\nDefault copy constructor with a copy of the second stack" << std::endl;
	ft::Stack<ft::pair<int,int> > test3(test2);
	std::cout << "Stack status = " << (test3.empty()?"Empty\t":"Not empty\t") << "Stack size = " << test3.size() << std::endl;
	std::cout << "\noperator= from the third test to the first" << std::endl;
	test3 = test0;
	std::cout << "Stack status = " << (test3.empty()?"Empty\t":"Not empty\t") << "Stack size = " << test3.size() << std::endl;
}


int main()
{
	test_stack_constructor();
	//test_stack_element_access();
	//test_stack_capacity();
	//test_stack_modifiers();
	//test_stack_operators();
	return 0;
}
