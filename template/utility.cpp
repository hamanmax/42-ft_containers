#include "utility.hpp"

template<typename T1, typename T2>
ft::pair<T1, T2>::pair(): first(), second() {}

template<typename T1, typename T2>
ft::pair<T1, T2>::pair(const T1& a, const T2& b): first(a), second(b) {}

template<typename T1, typename T2>
typename ft::pair<T1, T2>::pair&
ft::pair<T1, T2>::operator=(const pair& assign){
	if (this != &assign)
	{
		first = assign.first;
		second = assign.second;
	}
	return (*this);
}

template<typename T1, typename T2>
ft::pair<T1, T2>::~pair(){};
