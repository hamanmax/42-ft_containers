#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <cstddef>
#include "../iterator/vector_iterator.hpp"
#include "../template/utility.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft
{
template<class T,class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T														value_type;
		typedef Allocator												alloc_type;
		typedef size_t													size_type;
		typedef value_type&												reference;
		typedef const value_type&										const_reference;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef vector_iterator<T>										iterator;
		typedef vector_iterator<T, const_pointer, const_reference>		const_iterator;
		typedef ft::reverse_iterator<iterator >							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	private:
		pointer		_start; // Start
		pointer		_capacity_end; //Capacity
		pointer		_end; //Size
		alloc_type	_alloc;
	public:

		// * Constructeur / Destructeur

		// 1) Default constructor. Constructs an empty container with a default-constructed allocator.

		vector();

		// 2) Constructs an empty container with the given allocator alloc.

		explicit vector(const alloc_type& alloc);
		// 3) Constructs the container with count copies of elements with value value.

		explicit vector(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type());

		// 4) Constructs the container with the contents of the range [first, last).

		template<class InputIterator>
		vector(InputIterator first, InputIterator last,const alloc_type& alloc = alloc_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
			_alloc = alloc;
			size_type i = 0;
			for (InputIterator it = first; it != last; ++it,i++){}
			_start = _alloc.allocate(i, NULL);
			_capacity_end = _start + i;
			for (size_type i = 0; first != last; ++first,++i){
				_alloc.construct(_start + i, *first);}
			_end = _capacity_end;
		}

		// 5) Copy constructor. Constructs the container with the copy of the contents of other.

		vector( const vector& other );

		// Destructs the vector. The destructors of the elements are called and the used storage is deallocated.

		~vector();

		// Copy assignment operator. Replaces the contents with a copy of the contents of other.

		vector & operator=(vector const & op);

		alloc_type get_allocator() const;

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
			size_type n = 0;
			for (InputIterator i = first; i != last;i++,n++){}
			if (n > capacity())
				reserve(n);
			else
				clear();
			for (size_type i = 0; first != last; i++,first++){
				_alloc.construct(_start + i, *first);}
			_end = _start + n;}

		void assign (size_type n, const value_type& val);

		// * Element access

		// Returns a reference to the element at specified location pos, with bounds checking.

		reference at( size_type pos );
		const_reference at(size_type n) const;
		// Returns a reference to the element at specified location pos. No bounds checking is performed.

		reference operator[]( size_type pos );
		const_reference operator[] (size_type n) const;

		// Returns a reference to the first element in the container.

		reference front();
		const_reference front() const;

		// Returns a reference to the last element in the container.

		reference back();
		const_reference back() const;

		// Returns pointer to the underlying array serving as element storage.

		value_type *data();
		const value_type *data() const;

		// * Iterators

		iterator				begin();
		const_iterator 			begin() const;

		iterator				end();
		const_iterator 			end() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator	rend();
		const_reverse_iterator	rend() const;

		// * Capacity

		// Returns whether the vector is empty (i.e. whether its size is 0).

		bool		empty() const;

		// Returns the number of elements in the vector.

		size_type	size() const;

		// Returns the maximum number of elements that the vector can hold.

		size_type	max_size() const;

		// Increase the capacity of the vector to a value that's greater or equal to new_cap.

		void	reserve(size_type n);

		// Returns the number of elements that the container has currently allocated space for.

		size_type	capacity() const;

		// * Modifiers

		// Erases all elements from the container. After this call, size() returns zero.

		void	clear();

		// Inserts elements value at the specified pos in the container.

		iterator insert( iterator pos, const_reference value );

		// Inserts counts of elements value at the specified pos in the container.

		void insert( iterator pos, size_type count, const_reference value);

		// Inserts a range (first and last) of elements value at the specified pos in the container.

		template< class InputIterator >
		void insert( iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
			size_type spos =0, count = 0;
			if (first == last) return ;
			for (iterator i = begin(); i != pos;i++,spos++){}
			for (InputIterator i = first; i != last;i++,count++){}
			if (size() + count > capacity() * 2)
				reserve(capacity() + count);
			else if (size() + count > capacity() && capacity() > count * 2)
				reserve(capacity() + count * 2);
			else if (size() + count > capacity() && capacity() != 0)
				reserve(capacity() * 2);
			else if (capacity() == 0)
				reserve(count);
			for (size_type i = size() + count - 1; i > spos + count - 1; i-- )
				_alloc.construct(_start + i, _start[i - count]);
			for (ft::pair<size_type,InputIterator> i(0,first); i.first < count; i.second++,i.first++)
				_alloc.construct(_start + i.first + spos, *i.second);
			_end += count;}

		// Erases the specified elements pos from the container.

		iterator erase( iterator pos );

		// Erases a range (first and last) of specified elements from the container.

		iterator	erase(iterator first, iterator last);

		// Appends the given element value to the end of the container.

		void push_back( const_reference value );

		// Removes the last element of the container.

		void pop_back();

		// Exchanges the contents of the container with those of other.
		// Does not invoke any move, copy, or swap operations on individual elements.

		void swap (vector& Other);


		void resize (size_type n, value_type val = value_type());

friend bool	operator==(const vector& lhs, const vector& rhs ){
	if (lhs.size() != rhs.size())
		return false;

	for (size_type i = 0; i < lhs.size();i++) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;}

friend bool	operator!=(const vector& lhs, const vector& rhs ){return !(lhs == rhs);}

friend bool	operator<(const vector& lhs, const vector& rhs ){
return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

friend bool	operator>(const vector& lhs, const vector& rhs){return (rhs < lhs);}

friend bool	operator<=(const vector& lhs, const vector& rhs){return (!(rhs < lhs));}

friend bool	operator>=(const vector& lhs, const vector& rhs){return (!(lhs < rhs));}

};

template<class T,class Alloc>
void swap(vector<T,Alloc>& x,vector<T,Alloc>& y){x.swap(y);}
}
#include "vector.cpp"
#endif
