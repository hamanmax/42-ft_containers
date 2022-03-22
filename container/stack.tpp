#include "stack.hpp"

template <class T,class Container>
ft::stack<T,Container>::stack(const Container& cont):c(cont){}

template <class T,class Container>
ft::stack<T,Container>::stack(const stack& other):c(other.c){}

template <class T,class Container>
ft::stack<T,Container>::~stack(){}

template <class T,class Container>
typename ft::stack<T,Container>::reference ft::stack<T,Container>::top(){return c.back();}

template <class T,class Container>
typename ft::stack<T,Container>::const_reference ft::stack<T,Container>::top() const {return c.back();}

template <class T,class Container>
class ft::stack<T,Container>::stack& ft::stack<T,Container>::operator=( const stack& other){c = other.c;return *this;}

template <class T,class Container>
bool ft::stack<T,Container>::empty()const {return c.empty();}

template <class T,class Container>
typename ft::stack<T,Container>::size_type ft::stack<T,Container>::size()const {return c.size();}

template <class T,class Container>
void ft::stack<T,Container>::push(const value_type& value){c.push_back(value);}

template <class T,class Container>
void ft::stack<T,Container>::pop(){c.pop_back();}
