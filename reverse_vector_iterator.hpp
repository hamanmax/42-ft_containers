#ifndef REVERSE_VECTOR_ITERATOR_HPP
#define REVERSE_VECTOR_ITERATOR_HPP
#include "iterator.hpp"
#include "reverse_iterator.hpp"

template<
			class T,
			class Pointer = T*,
			class Reference = T&,
			class Category = RandomAccessIteratorTag,
			class Distance = ptrdiff_t
		>
class reverse_vector_iterator: public ft::iterator<Category,T>
{
	public:
	typedef Pointer						pointer;
	typedef Reference					reference;
	private:
		pointer	_mptr;
	public:

		reverse_vector_iterator(pointer ptr):_mptr(ptr){};

		reverse_vector_iterator():_mptr(0){};

		reverse_vector_iterator(reverse_vector_iterator const & copy):_mptr(copy._mptr){}
		template <typename U>
		reverse_vector_iterator( const reverse_vector_iterator<U>  & copy) {_mptr = copy.getptr();}

		reverse_vector_iterator & operator=(reverse_vector_iterator const & op){_mptr = op._mptr; return *this;};

		~reverse_vector_iterator(){};

		const pointer& getptr()const {return _mptr;}

		reference operator*(){
			return *_mptr;}

		pointer operator->(){
			return &(operator*());}

		bool operator!=(const reverse_vector_iterator& Other) const{return !(_mptr == Other._mptr);}

		bool operator==(const reverse_vector_iterator& Other) const{return _mptr == Other._mptr;}

		bool operator<(const reverse_vector_iterator& Other) const{return Other._mptr > _mptr;}

		bool operator>(const reverse_vector_iterator& Other) const{return Other._mptr < _mptr;}

		bool operator<=(const reverse_vector_iterator& Other) const{return Other._mptr >= _mptr;}

		bool operator>=(const reverse_vector_iterator& Other) const{return Other._mptr <= _mptr;}

		reverse_vector_iterator&	operator++(){
			--_mptr;
			return(*this);}

		reverse_vector_iterator	operator++(int){
			reverse_vector_iterator Old(*this);
			this->_mptr--;
			return(Old);}

		reverse_vector_iterator &operator+=(const ssize_t n){
			_mptr -= n;
			return *this;}

		reference operator[](const ssize_t n)const {
			return(_mptr[n]);}

		reverse_vector_iterator operator+(const ssize_t n)const {
			reverse_vector_iterator it(*this);
			if (n < 0)
				for (ssize_t i = 0; i > n; i--)
					it++;
			else
				for (ssize_t i = 0; i < n; i++)
					it--;
			return (it);}

		reverse_vector_iterator&	operator--(){
			++_mptr;
			return(*this);}

		reverse_vector_iterator	operator--(int){
			reverse_vector_iterator Old(*this);
			this->_mptr++;
			return(Old);}

		reverse_vector_iterator &operator-=(const ssize_t n){
			_mptr += n;
			return *this;}

		reverse_vector_iterator operator-(ssize_t n)const {
			reverse_vector_iterator it(*this);
			if (n > 0)
				for (ssize_t i = 0; i < n; i++)
					it++;
			else
				for (ssize_t i = 0; i > n; i--)
					it--;
			return (it);}

		Distance	operator-(reverse_vector_iterator it)const {
			return (this->_mptr - it._mptr);
		}
		friend reverse_vector_iterator operator+(int nb,const reverse_vector_iterator& it) {
			reverse_vector_iterator New(it);
			return (New += nb);
		}

		friend reverse_vector_iterator operator-(int nb,const reverse_vector_iterator& it) {
			reverse_vector_iterator New(it);
			return (New -= nb);
		}
};
#endif
