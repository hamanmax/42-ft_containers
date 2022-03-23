#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include "iterator.hpp"
#include <unistd.h>

template<
			class T,
			class Pointer = T*,
			class Reference = T&,
			class Category = RandomAccessIteratorTag,
			class Distance = ptrdiff_t
		>
class vector_iterator : public ft::iterator<Category, T>
{
	public:
	typedef Distance		difference_type;
	typedef Category		iterator_category;
	typedef Pointer			pointer;
	typedef Reference		reference;
	private:
		pointer _mptr;
	protected:
	public:
		vector_iterator(pointer ptr);
		vector_iterator();
		vector_iterator & operator=(vector_iterator const & op);
		vector_iterator( const vector_iterator  & copy);
		template<typename U>
		vector_iterator( const vector_iterator<U>  & copy) {_mptr = copy.getptr();}
		~vector_iterator();

		reference operator*() const;
		pointer operator->() const;

		pointer getptr()const;

		bool operator==(const vector_iterator& Other) const;

		bool operator!=(const vector_iterator& Other) const;

		bool operator<(const vector_iterator& Other) const;

		bool operator>(const vector_iterator& Other) const;

		bool operator<=(const vector_iterator& Other) const;

		bool operator>=(const vector_iterator& Other) const;

		reference operator[](const ssize_t n)const;

		vector_iterator&	operator++();
		vector_iterator	operator++(int);
		vector_iterator &operator+=(const ssize_t n);
		vector_iterator operator+(const ssize_t n)const;

		vector_iterator&	operator--();
		vector_iterator	operator--(int);
		vector_iterator &operator-=(const ssize_t n);
		vector_iterator operator-(const ssize_t n)const;

		difference_type	operator-(vector_iterator it)const;

		friend vector_iterator operator+(int nb,const vector_iterator& it) {
			vector_iterator New(it);
			return (New += nb);
		}

		friend vector_iterator operator-(int nb,const vector_iterator& it) {
			vector_iterator New(it);
			return (New -= nb);
		}
};
#include "vector_iterator.tpp"
#endif
