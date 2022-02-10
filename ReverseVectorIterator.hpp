#ifndef REVERSE_VECTOR_ITERATOR_HPP
#define REVERSE_VECTOR_ITERATOR_HPP
#include "Iterator.hpp"

template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class ReverseVectorIterator: public Iterator<Category, T>
{
	public:
	typedef typename T::value_type		value_type;
	typedef typename T::pointer			pointer;
	typedef typename T::reference		reference;
	typedef typename T::const_reference	const_reference;
	private:
		pointer	_mptr;
	public:
		ReverseVectorIterator(pointer ptr):_mptr(ptr){};

		ReverseVectorIterator():_mptr(0){};

		ReverseVectorIterator(ReverseVectorIterator const & copy){_mptr = copy._mptr;}

		ReverseVectorIterator & operator=(ReverseVectorIterator const & op){_mptr = op._mptr; return this;};

		~ReverseVectorIterator(){};

		reference operator*(){
			return *_mptr;}

		pointer operator->(){
			return &(operator*());}

		ReverseVectorIterator&	operator++(){
			--_mptr;
			return(*this);}

		ReverseVectorIterator&	operator++(int){
			_mptr--;
			return(*this);}

		ReverseVectorIterator &operator+=(const ssize_t n){
			_mptr -= n;
			return *this;}

		ReverseVectorIterator operator+(const ssize_t n)const {
			ReverseVectorIterator it(*this);
			if (n < 0)
				for (ssize_t i = 0; i > n; i--)
					it++;
			else
				for (ssize_t i = 0; i < n; i++)
					it--;
			return (it);}

		ReverseVectorIterator&	operator--(){
			++_mptr;
			return(*this);}

		ReverseVectorIterator&	operator--(int){
			_mptr++;
			return(*this);}

		ReverseVectorIterator &operator-=(const ssize_t n){
			_mptr += n;
			return *this;}

		ReverseVectorIterator operator-(ssize_t n)const {
			ReverseVectorIterator it(*this);
			if (n > 0)
				for (ssize_t i = 0; i < n; i++)
					it++;
			else
				for (ssize_t i = 0; i > n; i--)
					it--;
			return (it);}

		Distance	operator-(ReverseVectorIterator it)const {
			return (this->_mptr - it._mptr);
		}

};
#endif
