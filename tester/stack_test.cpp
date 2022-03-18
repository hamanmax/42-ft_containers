#include "tester.hpp"

void test_stack_constructor_capacity(){
	std::cout << BOLD << LIGHTBLUE << "Testing the constructors" << END << std::endl << std::endl;
	std::cout << "Default constructor with empty vector<int> :" << std::endl;
	ft::stack<int,std::vector<int> > test;
	pstack test0(pvector(25));
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test.size() << END << std::endl;
	std::cout << "\nDefault constructor with a size of 10 uninitialised with a ft::pair :" << std::endl;
	pstack test2(pvector(10));
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test2.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test2.size() << END << std::endl;
	std::cout << "\nDefault copy constructor with a copy of the second stack :" << std::endl;
	pstack test3(test2);
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test3.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test3.size() << END << std::endl;
	std::cout << "\noperator= from the third to test0 :" << std::endl;
	test3 = test0;
	std::cout << RIGHTARROW << "Stack." << LIGHTYELLOW << "empty" << END << (test3.empty()?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl << RIGHTARROW  << "Stack." << LIGHTYELLOW <<"size\t" << END << "= " << LIGHTORANGE << test3.size() << END << std::endl;
}

void test_stack_element_access(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing the element access" << END << std::endl;
	istack t;
	t.push(12);
	t.push(25);
	t.push(7);
	t.push(8);
	std::cout << "\nTest with a stack of int where i add 12,25,7,8 and then use top to get the last element added :" << std::endl<< RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t.top() << END << std::endl;
	const istack t1(t);
	std::cout << "\nTest with a stack of int where where Stack is const :" << std::endl<< RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t1.top() << END << std::endl;
	sstack t2;
	t2.push("Lorem ");
	t2.push("ipsum ");
	t2.push("dolor ");
	t2.push("sit ");
	t2.push("amet");
	std::cout << "\nTest with a stack of string where i add lorem ipsum dolor sit amet and then use top to get the last element added :" << std::endl<< RIGHTARROW << "Stack." << LIGHTYELLOW <<"top\t"<<END<<"= "<< LIGHTORANGE << t2.top() << END << std::endl;
}
void test_stack_modifiers(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing the modifiers" << END << std::endl;
	std::cout << "\nNew empty Stack :" <<std::endl;
	istack t;
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

void test_stack_operators(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing operators" << END << std::endl;
	ivector vector(10);
	istack a(vector);
	istack b(ivector(10));
	vector[9] = 25;
	istack c(vector);
	istack d(ivector(8));
	std::cout << "Creating 4 stack a and b are equal, c is greater than a, b and d, d is the lesser of them all" << std::endl;
	std::cout << "Testing comparison operator between a and b :" << std::endl;
	print_operators<istack>("Stack.",a,b);
	std::cout<< std::endl << "Testing comparison operator between a and c :" << std::endl;
	print_operators<istack>("Stack.",a,c);
	std::cout<< std::endl << "Testing comparison operator between a and d :" << std::endl;
	print_operators<istack>("Stack.",a,d);
	std::cout<< std::endl << "Testing comparison operator between c and d :" << std::endl;
	print_operators<istack>("Stack.",c,d);

	psvector string(10);
	psstack e(string);
	psstack f(psvector(10));
	string[9] = ft::make_pair<int,std::string>(0,"Bonjour");
	psstack g(string);
	psstack h(psvector(8));
	std::cout << std::endl << "Creating the same 4 stack but with ft::pair" << std::endl;
	std::cout << "Testing comparison operator between a and b :" << std::endl;
	print_operators<psstack>("Stack.",e,f);
	std::cout<< std::endl << "Testing comparison operator between a and c :" << std::endl;
	print_operators<psstack>("Stack.",e,g);
	std::cout<< std::endl << "Testing comparison operator between a and d :" << std::endl;
	print_operators<psstack>("Stack.",e,h);
	std::cout<< std::endl << "Testing comparison operator between c and d :" << std::endl;
	print_operators<psstack>("Stack.",g,h);

}
