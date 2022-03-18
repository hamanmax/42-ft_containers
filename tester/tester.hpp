#ifndef TESTER_HPP
#define TESTER_HPP

#include "map.hpp"
#include "vector.hpp"
#include "stack.hpp"
#include "utility.hpp"
#include <map>
#include <vector>
#include <stack>
#include <utility>
#include <string>

// * Color define

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

// * Typedefs
#ifndef NAMESPACE
#define NAMESPACE ft
#endif

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


// * Utiliy function

template<class T>
void print_operators(const char *container,T a,T b);
template<class T>
void print_map_operator(const char *container,T a,T b);
template <class T>
void print_vector_status(const char *container, T & t);
template <class T>
void print_vector_element_status(T &t);
template <typename Ite>
void print_vector_iterator_operators(std::string str, Ite & it,Ite & ite);
template <class T>
void print_vector_element_status_const(const T t);

// * Test Stack

void test_stack_constructor_capacity();
void test_stack_element_access();
void test_stack_modifiers();
void test_stack_operators();
void all_stack_test();

// * Test Vector

void test_vector_constructors();
void test_vector_element_access();
void test_vector_iterator_int(std::string str[4]);
void test_vector_iterator_string(std::string str[4]);
void test_vector_iterators();
void test_vector_clear();
template <class T,typename U>
void test_vector_insert_unit(T * vector, U val);
template <class T,typename U>
void test_vector_insert_fill(T * vector,int count, U val);
template <class T,typename InputIt>
void test_vector_insert_range(T * vector,InputIt first, InputIt last);
template <class T,typename U>
void test_vector_assign_unit(T * vector,typename T::size_type count, U val);
template <class T,typename InputIt>
void test_vector_assign_range(T * vector,InputIt first, InputIt last);
template <typename T>
void test_vector_erase_unit(T * vector);
template <typename T>
void test_vector_erase_range(T * vector);
void test_vector_insert(ivector * t, svector * s);
void test_vector_erase(ivector * i, svector * s);
void test_vector_push_pop(ivector * i, svector * s);
void test_vector_resize(ivector * i, svector *s);
void test_vector_swap(ivector * t, svector * s);
void test_vector_max_size(ivector * t, svector * s);
void test_vector_reserve(ivector * t, svector * s);
void test_vector_assign(ivector * t, svector * s);
void test_vector_modifiers();
void all_vector_test();


// * Test Map

void test_map_constructor_capacity();
void test_map_element_access();
void test_map_iterators();
void test_map_clear();
void test_map_insert();
void test_map_erase();
void test_map_swap();
void test_map_modifiers();
void test_map_count();
void test_map_find();
void test_map_equal_range();
void test_map_key_comp();
void test_map_value_comp();
void test_ft_swap_specialization();
void test_equality_operators();
void test_map_observers();
void test_map_non_member();
void test_map_lookup();
void all_map_test();


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

#endif
