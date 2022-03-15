#include "stack.hpp"
#include "stdio.h"
#include "vector.hpp"
#include "map.hpp"
#include "utility.hpp"
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <unistd.h>
#include <typeinfo>

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

#ifdef NAMESPACE

typedef NAMESPACE::vector<int> ivector;
typedef NAMESPACE::vector<std::string> svector;
typedef NAMESPACE::vector<ft::pair<int,int> > pvector;
typedef NAMESPACE::vector<ft::pair<int,std::string> > psvector;
typedef NAMESPACE::stack<int,ivector> istack;
typedef NAMESPACE::stack<std::string,svector> sstack;
typedef NAMESPACE::stack<ft::pair<int,int>,pvector > pstack;
typedef NAMESPACE::stack<ft::pair<int,std::string>,psvector > psstack;
typedef NAMESPACE::map<int,std::string> ismap;
typedef NAMESPACE::map<double,double> ddmap;
typedef NAMESPACE::pair<int,std::string> ispair;
typedef NAMESPACE::pair<double,double> ddpair;
#else
typedef ft::vector<int> ivector;
typedef ft::vector<std::string> svector;
typedef ft::vector<ft::pair<int,int> > pvector;
typedef ft::vector<ft::pair<int,std::string> > psvector;
typedef ft::stack<int,ivector> istack;
typedef ft::stack<std::string,svector> sstack;
typedef ft::stack<ft::pair<int,int>,pvector > pstack;
typedef ft::stack<ft::pair<int,std::string>,psvector > psstack;
typedef ft::map<int,std::string> ismap;
typedef ft::map<double,double> ddmap;
typedef ft::pair<int,std::string> ispair;
typedef ft::pair<double,double> ddpair;
#endif

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

template<class T>
void print_operators(const char *container,T a,T b){
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator==" << END << (a == b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator!=" << END << (a != b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator<" << END << (a < b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator<=" << END << (a <= b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator>" << END << (a > b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator>=" << END << (a >= b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
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
	print_operators("Stack.",a,b);
	std::cout<< std::endl << "Testing comparison operator between a and c :" << std::endl;
	print_operators("Stack.",a,c);
	std::cout<< std::endl << "Testing comparison operator between a and d :" << std::endl;
	print_operators("Stack.",a,d);
	std::cout<< std::endl << "Testing comparison operator between c and d :" << std::endl;
	print_operators("Stack.",c,d);

	psvector string(10);
	psstack e(string);
	psstack f(psvector(10));
	string[9] = ft::make_pair<int,std::string>(0,"Bonjour");
	psstack g(string);
	psstack h(psvector(8));
	std::cout << std::endl << "Creating the same 4 stack but with ft::pair" << std::endl;
	std::cout << "Testing comparison operator between a and b :" << std::endl;
	print_operators("Stack.",e,f);
	std::cout<< std::endl << "Testing comparison operator between a and c :" << std::endl;
	print_operators("Stack.",e,g);
	std::cout<< std::endl << "Testing comparison operator between a and d :" << std::endl;
	print_operators("Stack.",e,h);
	std::cout<< std::endl << "Testing comparison operator between c and d :" << std::endl;
	print_operators("Stack.",g,h);

}

template <class T>
void print_vector_status(const char *container, T & t){
	std::string str(RIGHTARROW);
	str.append(container);
	str.append(".");
	str.append(LIGHTYELLOW);
	std::cout << str << "empty\t\t" << END << (t.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
	std::cout << str << "capacity\t" << END << "= " << LIGHTORANGE << t.capacity() << END << std::endl;
	if (t.size() > 0){
		std::cout << str << "front\t\t" << END << "= " << LIGHTORANGE << t.front() << END << std::endl;
		std::cout << str << "back\t\t" << END << "= " << LIGHTORANGE << t.back() << END << std::endl;}
	std::cout << std::endl;
}

void test_vector_constructors(){
	std::cout << BOLD << LIGHTBLUE << "Testing the constructors" << END << std::endl;
	std::allocator<int> mem;
	ivector t(mem);
	std::cout << "Default constructor with int as template parameter :" << std::endl;
	print_vector_status("Vector",t);
	std::cout << "Fill constructor with size and initialization :" << std::endl;
	ivector t2(10,25);
	print_vector_status("Vector",t2);
	std::cout << "Range constructor with a size of 10 and a range of initialization from 0 to 10 :" << std::endl;
	int range[10] = {0,1,2,3,4,5,6,7,8,9};
	ivector t3(range, range + 10);
	print_vector_status("Vector",t3);
	std::cout << "Copy constructor to the Range constructor :" << std::endl;
	ivector t4(t3);
	print_vector_status("Vector",t4);
	std::cout << "Operator= of vector t4 with a push_back added:" << std::endl;
	ivector t5(3);
	t4.push_back(250);
	t5 = t4;
	print_vector_status("Vector",t5);
}

template <class T>
void print_vector_element_status(T &t)
{
	std::string str(RIGHTARROW);str.append("Vector");str.append(".");str.append(LIGHTYELLOW);
	std::cout << str << "front\t\t" << END << "= " << LIGHTORANGE << t.front() << END << std::endl;
	std::cout << str << "back\t\t" << END << "= " << LIGHTORANGE << t.back() << END << std::endl;
	std::cout << str << "data\t\t" << END << "= " << LIGHTORANGE << *t.data() << END << std::endl;
	std::cout << str << "at\t\t" << END << "= " << LIGHTORANGE;
	for (typename T::size_type i = 0; i < t.size(); i++){std::cout << t.at(i)  << " ";}
	std::cout << END <<std::endl;
	std::cout << str << "operator[]\t" << END << "= " << LIGHTORANGE;
	for (typename T::size_type i = 0; i < t.size(); i++){std::cout << t[i]  << " ";}
	std::cout << END <<std::endl;
}

template <class T>
void print_vector_element_status_const(const T t)
{
	std::string str(RIGHTARROW);str.append("Vector");str.append(".");str.append(LIGHTYELLOW);
	std::cout << str << "front\t\t" << END << "= " << LIGHTORANGE << t.front() << END << std::endl;
	std::cout << str << "back\t\t" << END << "= " << LIGHTORANGE << t.back() << END << std::endl;
	std::cout << str << "data\t\t" << END << "= " << LIGHTORANGE << *t.data() << END << std::endl;
	std::cout << str << "at\t\t" << END << "= " << LIGHTORANGE;
	for (typename T::size_type i = 0; i < t.size(); i++){std::cout << t.at(i)  << " ";}
	std::cout << END <<std::endl;
	std::cout << str << "operator[]\t" << END << "= " << LIGHTORANGE;
	for (typename T::size_type i = 0; i < t.size(); i++){std::cout << t[i]  << " ";}
	std::cout << END <<std::endl;
}

void test_vector_element_access(){
	std::cout << BOLD << LIGHTBLUE << "Testing the element access" << END << std::endl;
	int range[50]; for (int i = 0; i < 50;i++){range[i] = i;};
	ivector t(range, range + 50);
	std::cout << "Element acces from a vector<int> with a range of 50 :" << std::endl;
	print_vector_element_status(t);
	std::cout << std::endl << "Element acces from a const vector<int> with a range of 50 :" << std::endl;
	const ivector t2(range, range + 50);
	print_vector_element_status_const(t2);
	std::cout << std::endl << "Element acces from a const vector<std::string> with a 15 element :" << std::endl;
	std::string srange[15];for (int i = 0; i < 15;i++){for (int j = 0; j < 5; j++){srange[i].insert(j, 1,i + 64);}};
	svector t3(srange,srange + 15);
	print_vector_element_status(t3);
	std::cout << std::endl << "Element acces from a const vector<std::string> with a 15 element :" << std::endl;
	const svector t4(srange,srange + 15);
	print_vector_element_status_const(t4);

}

template <typename Ite>
void print_vector_iterator_operators(std::string str, Ite & it,Ite & ite)
{
	std::cout << str << "begin & end-1\t" << END << "= " << LIGHTORANGE << *it << " - " << *ite <<END << std::endl;
	std::cout << str << "begin!=end\t\t" << END << "= " << LIGHTORANGE;
	for (Ite i = it; i != ite + 1; i++){std::cout << *i << " ";}
	std::cout << END <<std::endl;
	std::cout << str << "operator*\t\t" << END << "= " << LIGHTORANGE << *it << END << std::endl;
	std::cout << str << "operator->\t\t" << END << "= " << LIGHTORANGE << it.operator->() << END << std::endl;
	std::cout << str << "operator++(int)\t" << END << "= " << LIGHTORANGE << *it.operator++(250) << END << std::endl;
	std::cout << str << "operator++\t\t" << END << "= " << LIGHTORANGE << *it.operator++() << END << std::endl;
	std::cout << str << "operator--(int)\t" << END << "= " << LIGHTORANGE << *it.operator--(250) << END << std::endl;
	std::cout << str << "operator--\t\t" << END << "= " << LIGHTORANGE << *it.operator--() << END << std::endl;
	std::cout << str << "operator+=\t\t" << END << "= " << LIGHTORANGE << *it.operator+=(10) << END << std::endl;
	std::cout << str << "operator-=\t\t" << END << "= " << LIGHTORANGE << *it.operator-=(3) << END << std::endl;
	std::cout << str << "operator+\t\t" << END << "= " << LIGHTORANGE << *it.operator+(3) << END << std::endl;
	std::cout << str << "operator-\t\t" << END << "= " << LIGHTORANGE << *it.operator-(2) << END << std::endl;
}

void test_vector_iterator_int(std::string str[4]){
	typedef ivector ftvector;

	int range[50]; for (int i = 0; i < 50;i++){range[i] = i;};
	ftvector t(range, range + 50), t3(range, range + 50);
	ftvector::iterator it = t.begin(),ite = t.end() - 1;
	ftvector::const_iterator cit = t.begin(),cite = t.end() - 1;
	ftvector::reverse_iterator rit = t.rbegin(),rite = t.rend() - 1;
	ftvector::const_reverse_iterator crit = t.rbegin(), crite = t.rend() - 1;
	std::cout << "Testing vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::iterator >(str[0],it,ite);
	std::cout << std::endl << "Testing const_vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_iterator >(str[1],cit,cite);
	std::cout << std::endl << "Testing reverse_vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::reverse_iterator >(str[2],rit,rite);
	std::cout << std::endl << "Testing const_reverse_vector_iterator with a vector<int> range of 50 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_reverse_iterator >(str[3],crit,crite);
	std::cout << std::endl << END;
	print_operators("Iterator.",(ftvector::iterator(t.begin())),(ftvector::iterator(t3.begin())));
}
void test_vector_iterator_string(std::string str[4]){
	typedef svector ftvector;

	std::string range[15];
	for (int i = 0; i < 15;i++){for (int j = 0; j < 5; j++){range[i].insert(j, 1,i + 64);}};
	ftvector t(range, range + 15), t3(range, range + 15);
	ftvector::iterator it = t.begin(),ite = t.end() - 1;
	ftvector::const_iterator cit = t.begin(),cite = t.end() - 1;
	ftvector::reverse_iterator rit = t.rbegin(),rite = t.rend() - 1;
	ftvector::const_reverse_iterator crit = t.rbegin(), crite = t.rend() - 1;
	std::cout << "Testing vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::iterator >(str[0],it,ite);
	std::cout << str[0] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << it.operator->()->c_str() << END << std::endl;
	std::cout << std::endl << "Testing const_vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_iterator >(str[1],cit,cite);
	std::cout << str[1] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << cit.operator->()->c_str() << END << std::endl;
	std::cout << std::endl << "Testing reverse_vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::reverse_iterator >(str[2],rit,rite);
	std::cout << str[2] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << rit.operator->()->c_str() << END << std::endl;
	std::cout << std::endl << "Testing const_reverse_vector_iterator with a vector<std::string> with 15 elements :" << std::endl;
	print_vector_iterator_operators<ftvector::const_reverse_iterator >(str[3],crit,crite);
	std::cout << str[3] << "operator->c_str()\t" << END << "= " << LIGHTORANGE << crit.operator->()->c_str() << END << std::endl;
	std::cout << END <<std::endl;
	std::cout << "Testing iterator comparison operator t.begin() and t.begin() :" << std::endl;
	print_operators("Iterator.",(ftvector::iterator(t.begin())),(ftvector::iterator(t.begin())));
	std::cout << "Testing iterator comparison operator t.begin() and t.end() :" << std::endl;
	print_operators("Iterator.",(ftvector::iterator(t.begin())),(ftvector::iterator(t.end())));
	std::cout << "Testing iterator comparison operator *t.begin() and *t3.begin() :" << std::endl;
	print_operators("Iterator.",*(ftvector::iterator(t.begin())),*(ftvector::iterator(t3.begin())));
}
void test_vector_iterators(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing vector's iterators" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Iterator");str.append(".");str.append(LIGHTYELLOW);
	std::string str2(RIGHTARROW);str2.append("CIterator");str2.append(".");str2.append(LIGHTYELLOW );
	std::string str3(RIGHTARROW);str3.append("RIterator");str3.append(".");str3.append(LIGHTYELLOW );
	std::string str4(RIGHTARROW);str4.append("CRIterator");str4.append(".");str4.append(LIGHTYELLOW);
	std::string cpstr[4]; cpstr[0] = str; cpstr[1] = str2; cpstr[2] = str3; cpstr[3] = str4;
	test_vector_iterator_int(cpstr);
	test_vector_iterator_string(cpstr);
}

void test_vector_clear(){
	std::string str(RIGHTARROW);str.append("Vector");str.append(".");str.append(LIGHTYELLOW);
	ivector t(15,150);
	std::cout << "Testing clear() with a vector<std::vector> with 15 elements :\nBefore : ";
	for(ivector::iterator it = t.begin(); it != t.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t);
	t.clear();
	std::cout << "After : ";
	for(ivector::iterator it = t.begin(); it != t.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t);
	svector t2(15,std::string("tutu"));
	std::cout << "Testing clear() with a vector<std::string> with 15 elements :\nBefore : ";
	for(svector::iterator it = t2.begin(); it != t2.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t2);
	t2.clear();
	std::cout << "After : ";
	for(svector::iterator it = t2.begin(); it != t2.end();it++) {std::cout << *it << " ";}
	std::cout << std::endl;
	print_vector_status("Vector",t2);
}

template <class T,typename U>
void test_vector_insert_unit(T * vector, U val)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		typename T::iterator it = test[i].insert(test[i].begin(),val);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		typename T::iterator it = test[i].insert(test[i].end(),val);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "insert\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <class T,typename U>
void test_vector_insert_fill(T * vector,int count, U val)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].begin(),count,val);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].end(),count,val);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}


template <class T,typename InputIt>
void test_vector_insert_range(T * vector,InputIt first, InputIt last)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].begin(),first,last);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].insert(test[i].end(),first,last);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}


template <class T,typename U>
void test_vector_assign_unit(T * vector,typename T::size_type count, U val)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(count,val);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(count,val);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <class T,typename InputIt>
void test_vector_assign_range(T * vector,InputIt first, InputIt last)
{
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(first,last);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 10)?"\t\t\t\t\t\t\t\t":((test[i].size() == 11)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		test[i].assign(first,last);
		std::cout << "Test n = " << i + 6 << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((test[i].size() > 15)?"\t\t":((test[i].size() == 11)?"":((test[i].size() == 12)?"\t\t\t\t\t\t\t":"\t\t\t\t\t\t"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <typename T>
void test_vector_erase_unit(T * vector){
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 1; i < 6; i++)
	{
		typename T::iterator it = test[i].erase(test[i].begin() + i);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((vector[i].size() == 10)?"\t\t\t\t\t\t\t":((vector[i].size() == 11)?"\t\t\t\t\t\t":((vector[i].size() == 15)?"\t\t\t\t":"tutu"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

template <typename T>
void test_vector_erase_range(T * vector){
	T test[6] = {vector[0], vector[1], vector[2], vector[3], vector[4], vector[5]};
	for (int i = 1; i < 6; i++)
	{
		typename T::iterator it = test[i].erase(test[i].begin(),test[i].begin() + i);
		std::cout << "Test n = " << i << std::endl;
		std::cout << "Before :\t\t\t\t\t\t\t\t\t\t\tAfter :" << std:: endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << vector[i].size() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "size\t\t" << END << "= "<<LIGHTORANGE << test[i].size() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << vector[i].capacity() << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "capacity\t" << END << "= "<<LIGHTORANGE << test[i].capacity() << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << "NULL" << END << "\t\t\t\t\t\t\t\t\t" << RIGHTARROW << "Vector." << LIGHTYELLOW << "erase\t\t" << END << "= "<<LIGHTORANGE << *it << END << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(typename T::iterator it = vector[i].begin(); it != vector[i].end();it++) {std::cout << *it << " ";}
		if (vector[i].size() == 0) std::cout << "\t\t\t";
		std::cout << END << ((vector[i].size() == 10)?"\t\t\t\t\t\t\t":((vector[i].size() == 11)?"\t\t\t\t\t\t":((vector[i].size() == 15)?"\t\t\t\t":"tutu"))) << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<< LIGHTORANGE ;
		for(typename T::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";}
		std::cout << END << std::endl << std::endl;
	}
}

void test_vector_insert(ivector * t, svector * s){
	std::cout << "Testing member function insert :" << std::endl;
	std::cout << "Testing insert on a bunch of vector<int> and with a single value of 25" << std::endl;
	test_vector_insert_unit(t, 25);

	std::cout << "Testing insert on a bunch of vector<string> and with a single value of 25" << std::endl;
	test_vector_insert_unit(s, std::string("25"));

	std::cout << "Testing insert on a bunch of vector<int> and with 10 values of 99" << std::endl;
	test_vector_insert_fill(t, 10, 99);

	std::cout << "Testing insert on a bunch of vector<string> and with 10 values of 99" << std::endl;
	test_vector_insert_fill(s, 10, std::string("99"));

	std::cout << "Testing insert on a bunch of vector<int> and with a range of 0 to 9" << std::endl;
	test_vector_insert_range(t, t[5].begin(), t[5].end());

	std::cout << "Testing insert on a bunch of vector<string> and with a range of 0 to 9" << std::endl;
	test_vector_insert_range(s, s[5].begin(), s[5].end());
}

void test_vector_erase(ivector * i, svector * s){
	std::cout << "Testing member function erase :" << std::endl;
	std::cout << "Testing erase on a bunch of vector<int>" << std::endl;
	test_vector_erase_unit(i);

	std::cout << "Testing erase on a bunch of vector<string>" << std::endl;
	test_vector_erase_unit(s);

	std::cout << "Testing erase on a bunch of vector<int> and with a range" << std::endl;
	test_vector_erase_range(i);

	std::cout << "Testing erase on a bunch of vector<string> and with a range" << std::endl;
	test_vector_erase_range(s);

}

void test_vector_push_pop(ivector * i, svector * s){
	ivector test[6] = {i[0], i[1], i[2], i[3], i[4], i[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};
	std::cout << "Testing member function push_back and pop_back :" << std::endl;
	std::cout << "Adding 10 elements to each vector :" << std::endl;
	for (int k = 0; k < 6;k++){
		for (int j = 0; j < 10; j++){
			if (j % 3 == 0){
				std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
				for(svector::iterator it = test2[k].begin(); it != test2[k].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
				print_vector_status("Vector",test2[k]);
				std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
				for(ivector::iterator it = test[k].begin(); it != test[k].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
				print_vector_status("Vector",test[k]);
			}
			test[k].push_back(k + 52);
			test2[k].push_back(std::string((test2[4].data() + k)->c_str()));
		}
	}
	std::cout << "Deleting all the elements in the vector :" << std::endl;
	for (int k = 0; k < 6;k++){
		for (ivector::size_type j = test[k].size(); j > 0; j--){
			test[k].pop_back();
		}
		for (svector::size_type j = test2[k].size(); j > 0; j--){
			test2[k].pop_back();
		}
			print_vector_status("Vector",test2[k]);
			print_vector_status("Vector",test[k]);
	}
}

void test_vector_resize(ivector * i, svector *s)
{
	ivector test[6] = {i[0], i[1], i[2], i[3], i[4], i[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};
	std::cout << "Testing member function resize :" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Before :" << std::endl;
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(ivector::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
		print_vector_status("Vector",test[i]);
		std::cout << "After :" << std::endl;
		test[i].resize(i * 5,32);
		test2[i].resize(i * 5);
		std::cout << RIGHTARROW << "Vector." << LIGHTYELLOW << "iterator\t" << END << "= "<<LIGHTORANGE ;
		for(ivector::iterator it = test[i].begin(); it != test[i].end();it++) {std::cout << *it << " ";};std:: cout << END << std::endl;
		print_vector_status("Vector",test[i]);
	}
}

void test_vector_swap(ivector * t, svector * s)
{
	ivector test[6] = {t[0], t[1], t[2], t[3], t[4], t[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};

	std::cout << "Testing member function swap :" << std::endl;
	std::cout << "Swapping the 1st container with the fifth container :" << std::endl;
	std::cout << "Before :" << std::endl;
	print_vector_status("Vector",test[0]);
	print_vector_status("Vector",test[5]);
	test[0].swap(test[5]);
	std::cout << "After :" << std::endl;
	print_vector_status("Vector",test[0]);
	print_vector_status("Vector",test[5]);
}

void test_vector_max_size(ivector * t, svector * s){
	std::cout << "Testing member function max_size :" << std::endl;
	for (int i = 0; i < 6; i++){
		std::cout << RIGHTARROW << "Ivector["<<i<< "]." << LIGHTYELLOW << "max_size\t\t" << END << "= "<<LIGHTORANGE << t[i].max_size() << END << "\t\t\t\t" << RIGHTARROW << "Svector["<< i <<"]." << LIGHTYELLOW << "max_size\t\t" << END << "= "<<LIGHTORANGE << s[i].max_size() << END << std::endl;
	}
	std::cout << std::endl;
}

void test_vector_reserve(ivector * t, svector * s){
	ivector test[6] = {t[0], t[1], t[2], t[3], t[4], t[5]};
	svector test2[6] = {s[0], s[1], s[2], s[3], s[4], s[5]};
	for (int i = 0; i < 6; i++) {
		print_vector_status("Vector",test[i]);
		test[i].reserve(100);
		print_vector_status("Vector",test[i]);
	}
}

void test_vector_assign(ivector * t, svector * s){
	std::cout << "Testing member function assign :" << std::endl;
	std::cout << "Testing assign on a bunch of vector<int> and with a single value of 25" << std::endl;
	test_vector_assign_unit(t, 25, 99);

	std::cout << "Testing assign on a bunch of vector<string> and with a single value of 25" << std::endl;
	test_vector_assign_unit(s, 25, std::string("99"));

	std::cout << "Testing assign on a bunch of vector<int> and with a range of 0 to 9" << std::endl;
	test_vector_assign_range(t, t[5].begin(), t[5].end());

	std::cout << "Testing assign on a bunch of vector<string> and with a range of 0 to 9" << std::endl;
	test_vector_assign_range(s, s[5].begin(), s[5].end());

}

void test_vector_modifiers(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing vector's modifiers" << END << std::endl;
	int range[10] = {0,1,2,3,4,5,6,7,8,9};
	ivector t,t2(10),t3(t2),t4(15,20),t5(range,range + 10),t6 = t4;
	t2.push_back(12);
	t3.reserve(15);
	ivector i[6] = {t,t2,t3,t4,t5,t6};

	svector s,s2(10);
	for (int i = 0; i < 10; i++){s2[i] = "0";};
	std::string srange[10] = {"0","1","2","3","4","5","6","7","8","9"};
	svector s3(s2),s4(15,std::string("20")),s5(srange,srange + 10),s6;
	s2.push_back("12");
	for (int i = 0; i < 10; i++){s2[i] = "0";};
	s3.reserve(15);
	s6 = s4;
	svector sd[6] = {s,s2,s3,s4,s5,s6};

	test_vector_clear();
	test_vector_insert(i,sd);
	test_vector_erase(i,sd);
	test_vector_push_pop(i,sd);
	test_vector_resize(i,sd);
	test_vector_swap(i,sd);
	test_vector_max_size(i,sd);
	test_vector_reserve(i,sd);
	test_vector_assign(i,sd);
}

void all_vector_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::VECTOR" << END << std::endl;
	std::cout << "The vector is a sequence container that encapsulates dynamic size array" << std::endl << std::endl;
	test_vector_constructors();
	test_vector_element_access();
	test_vector_iterators();
	test_vector_modifiers();
}


void all_stack_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::STACK" << END << std::endl;
	std::cout << "The stack class is a container adaptor that gives the programmer the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure. *cppreference.com\n" << std::endl;
	test_stack_constructor_capacity();
	test_stack_element_access();
	test_stack_modifiers();
	test_stack_operators();
	std::cout << std::endl << std::endl;
}

void test_map_constructor(){
	////ismap t;
	////ismap t2(std::less<int>,std::allocator<ispair>);
	//ispair range[10] = {ispair(12,"Bonjour"),ispair(13,"les"),ispair(14,"amis"),ispair(15,"Comment"),ispair(16,"Aller"),ispair(17,"Vous"),ispair(18,"Aujoud'hui"),ispair(19,"les"),ispair(20,"ptits"),ispair(21,"amis")};
	//ismap t3(range,range + 10);
	//ismap t4(t3);
	//t4.insert(ispair(22,"Developpeur"));
	ddmap d;
	ddmap d2(std::less<int>,std::allocator<ispair>);
	ddpair ddrange[10] = {ddpair(12.89,25.214),ddpair(12.6,8456.51),ddpair(12.7,654.151),ddpair(12.8,45216.232),ddpair(12.9,8425785.22),ddpair(12.91,94655.256),ddpair(12.92,4451.23),ddpair(12.93,666.666),ddpair(12.94,123.321),ddpair(12.95,3.15149)};
	ddmap d3(ddrange,ddrange + 10);
	d.insert(ddpair(12.99,56.45));
	d3.erase(12.7);

	ddmap::const_reverse_iterator it = d3.rbegin();
	ddmap::const_reverse_iterator ite = d3.rend();
	if (it != ite)
		std::cout << "tutu" << std::endl;

	for (ddmap::iterator it = d3.begin(); it != d3.end();it++)
	{
		std::cout << it->first << std::endl;
	} std::cout << endl;

	// for (ddmap::reverse_iterator it = d3.rbegin(); it != d3.rend();it++)
	// {
	// 	std::cout << it->first << std::endl;
	// } std::cout << endl;

	// for (ddmap::iterator it = --d3.end(); it != --d3.begin();it--)
	// {
	// 	std::cout << it->first << std::endl;
	// } std::cout << endl;
	// for (ddmap::reverse_iterator it = --d3.rend(); it != --d3.rbegin();it--)
	// {
	// 	std::cout << it->first << std::endl;
	// } std::cout << endl;

	// for (ddmap::const_iterator it = d3.begin(); it != d3.end();it++)
	// {
	// 	std::cout << it->first << std::endl;
	// } std::cout << endl;
	// ivector v3(12,20);
	// for (ivector::const_iterator it = v3.begin(); it != v3.end();it++)
	// {
	// 	std::cout << *it << std::endl;
	// } std::cout << endl;

	// for (ddmap::const_iterator it = --d3.end(); it != --d3.begin();it--)
	// {
	// 	std::cout << it->first << std::endl;
	// } std::cout << endl;
	// for (ddmap::const_reverse_iterator it = --d3.rend(); it != --d3.rbegin();it--)
	// {
	// 	std::cout << it->first << std::endl;
	// } std::cout << endl;
}

void all_map_test(){
	test_map_constructor();
	//TODO test_map_

}

int main()
{
	//all_stack_test();
	//all_vector_test();
	all_map_test();
	return 0;
}
