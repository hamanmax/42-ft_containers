#include "stack.hpp"
#include "stdio.h"
#include "vector.hpp"
#include "utility.hpp"
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <unistd.h>

#define END "\033[0m"
#define LIGHTGREEN "\u001b[38;5;40m"
#define GREEN "\u001b[38;5;22m"
#define RED "\u001b[38;5;88m"
#define LIGHTRED "\u001b[38;5;160m"
#define LIGHTBLUE "\u001b[38;5;39m"
#define ORANGE "\u001b[38;5;130m"
#define LIGHTORANGE "\u001b[38;5;208m"
#define LIGHTYELLOW "\u001b[38;5;227m"
#define BLUE "\u001b[38;5;20m"
#define BOLD "\u001b[1m"
#define UNDERLINE "\u001b[4m"
#define RIGHTARROW "\U00002192 "

void test_stack_constructor_capacity(){

	std::cout << "Default constructor with empty vector<int> :" << std::endl;
	ft::Stack<int,std::vector<int> > test;
	ft::Stack<ft::pair<int,int> > test0(ft::vector<ft::pair<int,int> >(25));
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test.size() << END << std::endl;
	std::cout << "\nDefault constructor with a size of 10 uninitialised with a ft::pair :" << std::endl;
	ft::Stack<ft::pair<int,int> > test2(ft::vector<ft::pair<int,int> >(10));
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test2.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test2.size() << END << std::endl;
	std::cout << "\nDefault copy constructor with a copy of the second stack :" << std::endl;
	ft::Stack<ft::pair<int,int> > test3(test2);
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test3.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test3.size() << END << std::endl;
	std::cout << "\noperator= from the third to test0 :" << std::endl;
	test3 = test0;
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test3.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW  << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test3.size() << END << std::endl;
}

void test_stack_element_access(){
	ft::Stack<int> t;
	t.push(12);
	t.push(25);
	t.push(7);
	t.push(8);
	std::cout << "\nTest with a stack of int where i add 12,25,7,8 and then use top to get the last element added :" << std::endl<< RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t.top() << END << std::endl;
	const ft::Stack<int> t1(t);
	std::cout << "\nTest with a stack of int where where Stack is const :" << std::endl<< RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t1.top() << END << std::endl;


	ft::Stack<std::string> t2;
	t2.push("Lorem ");
	t2.push("ipsum ");
	t2.push("dolor ");
	t2.push("sit ");
	t2.push("amet");
	std::cout << "\nTest with a stack of string where i add lorem ipsum dolor sit amet and then use top to get the last element added :" << std::endl<< RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t2.top() << END << std::endl;
}

void test_stack_modifiers(){
	std::cout << "\nNew empty Stack :" <<std::endl;
	ft::Stack<int> t;
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (t.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
	t.push(12);
	t.push(25);
	t.push(6);
	std::cout << std::endl << "Adding 3 values(12,25,6) to stack :" << std::endl;
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (t.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t.top() << END << std::endl << std::endl;
	std::cout << "Remove value_type one by one and ask the top again :" << std::endl;
	t.pop();
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (t.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t.top() << END << std::endl << std::endl;
	t.pop();
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (t.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t.top() << END << std::endl << std::endl;
	t.pop();
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (t.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
}

template<class T>
void print_stack_operators(ft::Stack<T> a,ft::Stack<T> b){
std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "operator==" << END << (a == b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "operator!=" << END << (a != b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "operator<" << END << (a < b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "operator<=" << END << (a <= b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "operator>" << END << (a > b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "operator>=" << END << (a >= b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
}

void test_stack_operators(){
	ft::vector<int> vector(10);
	ft::Stack<int> a(vector);
	ft::Stack<int> b(ft::vector<int>(10));
	vector[9] = 25;
	ft::Stack<int> c(vector);
	ft::Stack<int> d(ft::vector<int>(8));
	std::cout << "Creating 4 stack a and b are equal, c is greater than a, b and d, d is the lesser of them all" << std::endl;
	std::cout << "Testing comparison operator between a and b :" << std::endl;
	print_stack_operators(a,b);
	std::cout<< std::endl << "Testing comparison operator between a and c :" << std::endl;
	print_stack_operators(a,c);
	std::cout<< std::endl << "Testing comparison operator between a and d :" << std::endl;
	print_stack_operators(a,d);
	std::cout<< std::endl << "Testing comparison operator between c and d :" << std::endl;
	print_stack_operators(c,d);

	ft::vector<ft::pair<int,std::string> > string(10);
	ft::Stack<ft::pair<int,std::string> > e(string);
	ft::Stack<ft::pair<int,std::string> > f(ft::vector<ft::pair<int,std::string> >(10));
	string[9] = ft::make_pair<int,std::string>(0,"Bonjour");
	ft::Stack<ft::pair<int,std::string> > g(string);
	ft::Stack<ft::pair<int,std::string> > h(ft::vector<ft::pair<int,std::string> >(8));
	std::cout << std::endl << "Creating the same 4 stack but with ft::pair" << std::endl;
	std::cout << "Testing comparison operator between a and b :" << std::endl;
	print_stack_operators(e,f);
	std::cout<< std::endl << "Testing comparison operator between a and c :" << std::endl;
	print_stack_operators(e,g);
	std::cout<< std::endl << "Testing comparison operator between a and d :" << std::endl;
	print_stack_operators(e,h);
	std::cout<< std::endl << "Testing comparison operator between c and d :" << std::endl;
	print_stack_operators(g,h);

}

void all_stack_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::STACK" << END << std::endl << std::endl;
	std::cout << "The stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure. *cppreference.com\n" << std::endl;
	std::cout << BOLD << LIGHTBLUE << "Testing the constructors" << END << std::endl << std::endl;
	test_stack_constructor_capacity();
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing the element access" << END << std::endl;
	test_stack_element_access();
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing the modifiers" << END << std::endl;
	test_stack_modifiers();
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing operators" << END << std::endl;
	test_stack_operators();
}

void all_vector_test(){

}

int main()
{
	all_stack_test();
	all_vector_test();
	std::cout << std::endl << std::endl << BOLD << UNDERLINE << ORANGE << "TESTING FT::VECTOR" << END << std::endl << std::endl << std::endl;
	return 0;
}
