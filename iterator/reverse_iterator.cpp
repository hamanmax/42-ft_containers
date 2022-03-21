#include "reverse_iterator.hpp"

template <class Ite>
ft::reverse_iterator<Ite>::reverse_iterator():current(){}

template <class Ite>
ft::reverse_iterator<Ite>::reverse_iterator(iterator_type it):current(it){}

template <class Ite>
typename ft::reverse_iterator<Ite>::iterator_type
ft::reverse_iterator<Ite>::base() const {return current;}

template <class Ite>
typename ft::reverse_iterator<Ite>::reference
ft::reverse_iterator<Ite>::operator*() const{
	iterator_type tmp(current);
	return *(--tmp);
}

template <class Ite>
typename ft::reverse_iterator<Ite>::pointer
ft::reverse_iterator<Ite>::operator->()const {
	return &(operator*());}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator &
ft::reverse_iterator<Ite>::operator++(){--current; return *this;}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator
ft::reverse_iterator<Ite>::operator++(int){
	reverse_iterator tmp = *this;
	--current;
	return tmp;
}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator &
ft::reverse_iterator<Ite>::operator--(){++current; return *this;}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator
ft::reverse_iterator<Ite>::operator--(int){
	reverse_iterator tmp = *this;
	++current;
	return tmp;
}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator
ft::reverse_iterator<Ite>::operator+(difference_type n) const{
	return reverse_iterator(current - n);
}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator
ft::reverse_iterator<Ite>::operator-(difference_type n) const{
	return reverse_iterator(current + n);
}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator &
ft::reverse_iterator<Ite>::operator+=(difference_type n){
	current -= n; return *this;
}

template <class Ite>
typename ft::reverse_iterator<Ite>::reverse_iterator &
ft::reverse_iterator<Ite>::operator-=(difference_type n){
	current += n; return *this;
}

template <class Ite>
typename ft::reverse_iterator<Ite>::reference
ft::reverse_iterator<Ite>::operator[](difference_type n) const {
	return *(*this + n);
}


