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
template<class T>
void print_map_operator(const char *container,T a,T b){
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator==" << END << (a == b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
std::cout << RIGHTARROW << container << LIGHTYELLOW << "operator!=" << END << (a != b?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END)<<std::endl;
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
	std::cout << BOLD << UNDERLINE << "Testing member function insert :" << END << std::endl;
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
	std::cout << BOLD << UNDERLINE << "Testing member function erase :" << END << std::endl;
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
	std::cout << BOLD << UNDERLINE << "Testing member function push_back and pop_back :" << END << std::endl;
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
	std::cout << BOLD << UNDERLINE << "Testing member function resize :" << END << std::endl;
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

	std::cout << BOLD << UNDERLINE << "Testing member function swap :" << END << std::endl;
	std::cout << "Swapping the 1st container with the fifth container :" << END << std::endl;
	std::cout << "Before :" << std::endl;
	print_vector_status("Vector",test[0]);
	print_vector_status("Vector",test[5]);
	test[0].swap(test[5]);
	std::cout << "After :" << std::endl;
	print_vector_status("Vector",test[0]);
	print_vector_status("Vector",test[5]);
}

void test_vector_max_size(ivector * t, svector * s){
	std::cout << BOLD << UNDERLINE << "Testing member function max_size :" << END << std::endl;
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
	std::cout << BOLD << UNDERLINE << "Testing member function assign :" << END << std::endl;
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

void test_map_constructor_capacity(){
	std::cout << BOLD << LIGHTBLUE << "Testing map constructor" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap t;
	std::allocator<ispair> alloc = t.get_allocator();
	std::cout << "get_allocator :" << std::endl;
	ispair *p = alloc.allocate(1,NULL);
	alloc.construct(p,ispair(0,std::string("Coucou")));
	std::cout << p->first << " " << p->second << " " << std::endl;
	std::cout << "Default Constructors :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << t.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (t.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
	std::cout << "Range constructor with a range of pair :" << std::endl;
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap t3(range,range + 5);
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << t3.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (t3.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = t3.begin(); it != t3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Copy constructor with a range of pair reverse elem :" << std::endl;
	ismap t4(t3);
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << t4.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (t4.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t4.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::reverse_iterator it = t4.rbegin(); it != t4.rend(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	alloc.destroy(p);
	alloc.deallocate(p,1);
}

void test_map_element_access(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing map element access" << END << std::endl;
	std::cout << "Testing operator[] in a bunch of situation :" << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap t(range,range + 5);
	std::cout << str << "empty\t\t" << END << (t.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << t.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = t.begin(); it != t.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Modifying the value of the pairs :" << std::endl;
	t[0] = std::string("Un");
	t[1] = std::string("jour");
	t[2] = std::string("je");
	t[3] = std::string("serait");
	t[4] = std::string("le");
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = t.begin(); it != t.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Adding pairs of data :" << std::endl;
	t[5] = std::string("meilleur");
	t[6] = std::string("dresseur");
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::iterator i = t.begin(); i != t.end(); i++){
	std::cout << t.at(i->first) << " ";}std::cout << END << std::endl;
}

void test_map_iterators()
{
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	std::cout << BOLD << LIGHTBLUE << std::endl << "Testing map iterators implementation" << END << std::endl;
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap t(range,range + 5);
	ismap t2(t);
	ismap t3;
	ismap::iterator it1 = t.begin();
	ismap::iterator ite1 = t.end();
	ismap::const_iterator cit1 = t.begin();
	ismap::const_iterator cite1 = t.end();
	ismap::reverse_iterator rit1 = t.rbegin();
	ismap::reverse_iterator rite1 = t.rend();
	ismap::const_reverse_iterator crit1 = t.rbegin();
	ismap::const_reverse_iterator crite1 = t.rend();
	std::cout << "Tesing begin and end iterator : ";
	std::cout <<LIGHTORANGE << it1->first << " " << (--ite1)->first << " " << cit1->first << " " << (--cite1)->first << " " << rit1->first << " " << (--rite1)->first << " "  << crit1->first << " " << (--crite1)->first << END << std::endl;
	ite1++;
	cite1++;
	rite1++;
	crite1++;
	std::cout << "Testing iterator equality operators t1 and t2 begin :" << std::endl;
	print_map_operator("Map",t.begin(),t2.begin());
	std::cout << "Testing iterator equality operators t2 and t2 begin :" << std::endl;
	print_map_operator("Map",t.begin(),t.begin());
	std::cout << "Testing iterator equality operators t3 and t3 begin :" << std::endl;
	print_map_operator("Map",t3.begin(),t3.begin());
	std::cout << "Testing normal iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; it1 != ite1; ++it1){
	std::cout << it1->first << "|" << it1->second << " ";}std::cout << END << std::endl;

	std::cout << "Testing const iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; cit1 != cite1; ++cit1){
	std::cout << cit1->first << "|" << cit1->second << " ";}std::cout << END << std::endl;

	std::cout << "Testing reverse iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; rit1 != rite1; ++rit1){
	std::cout << rit1->first << "|" << rit1->second << " ";}std::cout << END << std::endl;

	std::cout << "Testing const reverse iterator begin to end :" << std::endl;
	std::cout << str << "elements\t" << END << "= " << LIGHTORANGE;
	for (; crit1 != crite1; ++crit1){
	std::cout << crit1->first << "|" << crit1->second << " ";}std::cout << END << std::endl;
}

void test_map_clear(){
	std::cout << "Testing clear function :" << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ispair range[5] = {ispair(0,"Bonjour"),ispair(1,"Hello"),ispair(2,"Salut"),ispair(3,"Coucou"),ispair(4,"Aloa")};
	ismap i(range,range + 5);
	ismap i2(i);
	ismap i3(i);
	for (int i = 8; i < 16; i++)
		i3.insert(ispair(i,std::string("Hey")));
	std::cout << "i before clear :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i.size() << END << std::endl;
	std::cout << "i after clear :" << std::endl;
	i.clear();
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i.size() << END << std::endl;
	std::cout << "i2 before clear :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i2.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i2.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i2.size() << END << std::endl;
	std::cout << "i2 after clear :" << std::endl;
	i2.clear();
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i2.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i2.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i2.size() << END << std::endl;
	std::cout << "i3 before clear :" << std::endl;
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i3.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i3.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << "i3 after clear :" << std::endl;
	i3.clear();
	std::cout << str << "max_size\t\t" << END << "= " << LIGHTORANGE << i3.max_size() << END << std::endl;
	std::cout << str << "empty\t\t" << END << (i3.empty()?"= " LIGHTGREEN "True" END : "= " LIGHTRED "False" END)<<std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;

}

void test_map_insert(){
	std::cout << BOLD << UNDERLINE << std::endl << "Testing map insert" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap i3;
	for (int i = 0; i < 20; i+=2)
		i3.insert(ispair(i,std::string("Hey")));
	ismap::iterator it = i3.begin();
	it++;it++;it++;
	std::cout << "Insert with a value :" << std::endl;
	#ifdef NAMESPACE
	NAMESPACE::pair<ismap::iterator,bool> pb(i3.insert(ispair(15,std::string("Nouveau"))));
	#else
	ft::pair<ismap::iterator,bool> pb(i3.insert(ispair(15,std::string("Nouveau"))));
	#endif
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "return_value\t" << END << "= " << LIGHTORANGE << pb.first->first << "|" << pb.first->second << "\t" << (pb.second?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END) << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Insert with a value n2:" << std::endl;
	#ifdef NAMESPACE
	NAMESPACE::pair<ismap::iterator,bool> pbe(i3.insert(ispair(14,std::string("Nouveaudeux"))));
	#else
	ft::pair<ismap::iterator,bool> pbe(i3.insert(ispair(14,std::string("Nouveaudeux"))));
	#endif
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "return_value\t" << END << "= " << LIGHTORANGE << pbe.first->first << "|" << pbe.first->second << "\t" << (pbe.second?"\t= " LIGHTGREEN "True" END : "\t= " LIGHTRED "False" END) << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Insert with a hint :" << std::endl;
	ismap::iterator it2 = i3.insert(it,ispair(7,std::string("Bonjour")));
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "return_value\t" << END << "= " << LIGHTORANGE << it2->first << "|" << it2->second << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	ispair range[8];
	for (int i = 0; i < 8; ++i){
		range[i].first = i+i+1;
		range[i].second = std::string("Encore");
	}
	std::cout << "Insert with a range :" << std::endl;
	i3.insert(range,range + 8);
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_map_erase(){
	std::cout << BOLD << UNDERLINE << std::endl << "Testing map erase :" << END << std::endl;
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap i3;
	for (int i = 0; i < 20; i+=2)
		i3.insert(ispair(i,std::string("Hey")));
	std::cout << "erase the first (0) with his pos and the second with his key (14)" << std::endl;
	std::cout << "Before erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	i3.erase(i3.begin());
	i3.erase(14);
	std::cout << "After erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "erase a range of pair from begin to end - 3:" << std::endl;
	std::cout << "Before erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	ismap::iterator it2 = --(--(--i3.end()));
	i3.erase(i3.begin(), it2);
	std::cout << "After erasing :" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << i3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = i3.begin(); it != i3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_map_swap(){
	std::string str(RIGHTARROW);str.append("Map");str.append(".");str.append(LIGHTYELLOW);
	ismap m;
	ismap m2;
	for (int i = 1; i < 20; i+=2)
		m2.insert(ispair(i,std::string("Hey")));
	ismap m3;
	for (int i = 0; i < 20; i+=2)
		m3.insert(ispair(i,std::string("Hey")));

	std::cout << BOLD << UNDERLINE << std::endl << "Testing mumber function swap" << END << std::endl;

	std::cout << "Swapping m2 and m3" << std::endl;
	std::cout << "Befrore m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	m2.swap(m3);
	std::cout << "After m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;

	std::cout << "Swapping m3 and m" << std::endl;

	std::cout << "Befrore m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	m3.swap(m);
	std::cout << "After m3:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m3.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m3.begin(); it != m3.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;


	std::cout << "Swapping m and m2" << std::endl;
	std::cout << "Befrore m:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "After m:" << std::endl;
	m.swap(m2);
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m.begin(); it != m.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "m2:" << std::endl;
	std::cout << str << "size\t\t" << END << "= " << LIGHTORANGE << m2.size() << END << std::endl;
	std::cout << str << "elements\t\t" << END << "= " << LIGHTORANGE;
	for (ismap::const_iterator it = m2.begin(); it != m2.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
}

void test_map_modifiers(){
	std::cout << std::endl << BOLD << LIGHTBLUE << "Testing map modifier member function" << END << std::endl;
	test_map_clear();
	test_map_insert();
	test_map_erase();
	test_map_swap();
}

void test_map_count(){
	ismap m_odd;
	for (int i = 1; i < 20; i+=2)
		m_odd.insert(ispair(i,std::string("Hisse")));
	ismap m_even;
	for (int i = 0; i < 20; i+=2)
		m_even.insert(ispair(i,std::string("Oh")));
	ismap m_total(m_even);
	m_total.insert(m_odd.begin(),m_odd.end());
	std::cout << BOLD << UNDERLINE << "Testing member function count :" << END << std::endl;
	std::cout << "m_odd : ";
	for (ismap::const_iterator it = m_odd.begin(); it != m_odd.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_odd map :" << (m_odd.count(4)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_odd map :" << (m_odd.count(9)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_odd map :" << (m_odd.count(1)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_odd map :" << (m_odd.count(7)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_odd map :" << (m_odd.count(0)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_odd map :" << (m_odd.count(2)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << std::endl << "m_even :";for (ismap::const_iterator it = m_even.begin(); it != m_even.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_even map :" << (m_even.count(4)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_even map :" << (m_even.count(9)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_even map :" << (m_even.count(1)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_even map :" << (m_even.count(7)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_even map :" << (m_even.count(0)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_even map :" << (m_even.count(2)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << std::endl << "m_total : ";for (ismap::const_iterator it = m_total.begin(); it != m_total.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_total map :" << (m_total.count(4)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_total map :" << (m_total.count(9)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_total map :" << (m_total.count(1)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_total map :" << (m_total.count(7)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_total map :" << (m_total.count(0)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_total map :" << (m_total.count(2)?LIGHTGREEN " Yes":LIGHTRED " No") << END << std::endl;
}

void test_map_find(){
	ismap m_odd;
	for (int i = 1; i < 20; i+=2)
		m_odd.insert(ispair(i,std::string("Hisse")));
	ismap m_even;
	for (int i = 0; i < 20; i+=2)
		m_even.insert(ispair(i,std::string("Oh")));
	ismap m_total(m_even);
	m_total.insert(m_odd.begin(),m_odd.end());
	std::cout << BOLD << UNDERLINE << std::endl << "Testing member function find :" << END << std::endl;
	std::cout << "m_odd : ";
	for (ismap::const_iterator it = m_odd.begin(); it != m_odd.end(); ++it){
	std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(4) != m_odd.end()?m_odd.find(4)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(9) != m_odd.end()?m_odd.find(9)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(1) != m_odd.end()?m_odd.find(1)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(7) != m_odd.end()?m_odd.find(7)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(0) != m_odd.end()?m_odd.find(0)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_odd map :" << LIGHTORANGE << ((m_odd.find(2) != m_odd.end()?m_odd.find(2)->first:-1))<< END << std::endl;
	std::cout << std::endl << "m_even :";for (ismap::const_iterator it = m_even.begin(); it != m_even.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(4) != m_even.end()?m_even.find(4)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(9) != m_even.end()?m_even.find(9)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(1) != m_even.end()?m_even.find(1)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(7) != m_even.end()?m_even.find(7)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(0) != m_even.end()?m_even.find(0)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_even map :" << LIGHTORANGE << ((m_even.find(2) != m_even.end()?m_even.find(2)->first:-1))<< END << std::endl;
	std::cout << std::endl << "m_total : ";for (ismap::const_iterator it = m_total.begin(); it != m_total.end(); ++it){std::cout << it->first << "|" << it->second << " ";}std::cout << END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "4" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(4) != m_total.end()?m_total.find(4)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "9" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(9) != m_total.end()?m_total.find(9)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "1" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(1) != m_total.end()?m_total.find(1)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "7" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(7) != m_total.end()?m_total.find(7)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "0" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(0) != m_total.end()?m_total.find(0)->first:-1))<< END << std::endl;
	std::cout << "Is There a Key " << LIGHTORANGE  "2" << END << " in the m_total map :" << LIGHTORANGE << ((m_total.find(2) != m_total.end()?m_total.find(2)->first:-1))<< END << std::endl;
}

void test_map_equal_range(){
	std::cout << BOLD << UNDERLINE << std::endl << "Testing member function equal range :" << END << std::endl;
	ismap m_odd;
	for (int i = 1; i < 20; i+=2)
		m_odd.insert(ispair(i,std::string("Hisse")));
	std::cout << "Testing with a Key value of 5 :" << std::endl;
	NAMESPACE::pair<ismap::iterator,ismap::iterator> p(m_odd.equal_range(5));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p.second->first << END << std::endl;
	std::cout << "Testing with a Key value of 4 :" << std::endl;
	NAMESPACE::pair<ismap::const_iterator,ismap::const_iterator> p2(m_odd.equal_range(4));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p2.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p2.second->first << END << std::endl;
	std::cout << "Testing with a Key value of 6 :" << std::endl;
	NAMESPACE::pair<ismap::const_iterator,ismap::const_iterator> p3(m_odd.equal_range(6));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p3.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p3.second->first << END << std::endl;
	std::cout << "Testing with a Key value of 11 :" << std::endl;
	NAMESPACE::pair<ismap::const_iterator,ismap::const_iterator> p4(m_odd.equal_range(11));
	std::cout << LIGHTYELLOW << "lower_bound" << END << " = " <<  LIGHTORANGE << p4.first->first << LIGHTYELLOW << " upper_bound" << END << " = " <<  LIGHTORANGE << p4.second->first << END << std::endl;
}

void test_map_lookup(){
	std::cout <<std::endl << BOLD << LIGHTBLUE << "Testing map Lookup function" << END << std::endl;
	test_map_count();
	test_map_find();
	test_map_equal_range();
}

void test_map_observers(){
	std::cout <<std::endl << BOLD << LIGHTBLUE << "Testing map observers function" << END << std::endl;
	//TODO test_key_comp();
	//TODO test_value_comp();
}

void test_map_non_member(){
	std::cout <<std::endl << BOLD << LIGHTBLUE << "Testing map non member function" << END << std::endl;
	//TODO test_swap_specialization();
	//TODO test_equality_operators();
}


void all_map_test(){
	std::cout << BOLD << UNDERLINE << ORANGE << "TESTING FT::MAP" << END << std::endl;
	std::cout << "The map is a sorted associative container that contains key-value pairs with unique keys" << std::endl << std::endl;
	test_map_constructor_capacity();
	test_map_element_access();
	test_map_iterators();
	test_map_modifiers();
	test_map_lookup();
	test_map_observers();
	test_map_non_member();
}

int main()
{
	//all_stack_test();
	//all_vector_test();
	all_map_test();
	return 0;
}
