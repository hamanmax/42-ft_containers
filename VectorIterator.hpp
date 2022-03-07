#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include "Iterator.hpp"

template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class VectorIterator : public Iterator<Category,T>
{
	public:
	typedef typename T::value_type		value_type;
	typedef typename T::pointer			pointer;
	typedef typename T::reference		reference;
	typedef typename T::const_reference	const_reference;
	private:
		pointer _mptr;
	protected:
		/*Arg*/
	public:
		VectorIterator(pointer ptr):_mptr(ptr){};
		VectorIterator():_mptr(0){};
		VectorIterator(VectorIterator const & copy){_mptr = copy._mptr;}
		VectorIterator & operator=(VectorIterator const & op){_mptr = op._mptr; return *this;};
		~VectorIterator(){};
		reference operator*(){
			return *_mptr;}

		pointer operator->(){
			return &(operator*());}

		bool operator!=(const VectorIterator& Other) const{return !(_mptr == Other._mptr);}

		bool operator==(const VectorIterator& Other) const{return _mptr == Other._mptr;}

		bool operator<(const VectorIterator& Other) const{return Other._mptr > _mptr;}

		bool operator>(const VectorIterator& Other) const{return Other._mptr < _mptr;}

		bool operator<=(const VectorIterator& Other) const{return Other._mptr >= _mptr;}

		bool operator>=(const VectorIterator& Other) const{return Other._mptr <= _mptr;}

		reference operator[](const ssize_t n)const {
			return(_mptr[n]);}

		VectorIterator&	operator++(){
			++_mptr;
			return(*this);}

		VectorIterator	operator++(int){
			VectorIterator Old(*this);
			this->_mptr++;
			return(Old);}

		VectorIterator &operator+=(const ssize_t n){
			_mptr += n;
			return *this;}

		VectorIterator operator+(const ssize_t n)const {
			VectorIterator it(*this);
			if (n < 0)
				for (ssize_t i = 0; i > n; i--)
					it--;
			else
				for (ssize_t i = 0; i < n; i++)
					it++;
			return (it);}

		VectorIterator&	operator--(){
			--_mptr;
			return(*this);}

		VectorIterator	operator--(int){
			VectorIterator Old(*this);
			this->_mptr--;
			return(Old);}

		VectorIterator &operator-=(const ssize_t n){
			_mptr -= n;
			return *this;}

		VectorIterator operator-(ssize_t n)const {
			VectorIterator it(*this);
			if (n > 0)
				for (ssize_t i = 0; i < n; i++)
					it--;
			else
				for (ssize_t i = 0; i > n; i--)
					it++;
			return (it);}

		Distance	operator-(VectorIterator it)const {
			return (this->_mptr - it._mptr);
		}

		friend VectorIterator operator+(int nb,const VectorIterator& it) {
			VectorIterator New(it);
			return (New += nb);
		}

		friend VectorIterator operator-(int nb,const VectorIterator& it) {
			VectorIterator New(it);
			return (New -= nb);
		}
};

#endif