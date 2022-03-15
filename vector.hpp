#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include <cstddef>
#include "vector_iterator.hpp"
#include "utility.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
template<class T,class Alloc = std::allocator<T> >
class vector
{
	public:
		typedef T			value_type;
		typedef Alloc		alloc_type;
		typedef size_t		size_type;
		typedef T*			pointer;
		typedef const T*	const_pointer;
		typedef T&			reference;
		typedef const T&	const_reference;
		typedef vector_iterator<T>				iterator;
		typedef vector_iterator<T, const_pointer, const_reference>		const_iterator;
		typedef ft::reverse_iterator<iterator >				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	private:
		pointer	_start; // Start
		pointer	_capacity_end; //Capacity
		pointer	_end; //Size
		alloc_type _alloc;
	public:

		// * Constructeur / Destructeur

		// 1) Default constructor. Constructs an empty container with a default-constructed allocator.

		vector(){
		_alloc = alloc_type();
		_start = _alloc.allocate(0, NULL);
		_capacity_end = _end = _start;}

		// 2) Constructs an empty container with the given allocator alloc.

		explicit vector(const alloc_type& alloc){
		_alloc = alloc;
		_start = _alloc.allocate(0, NULL);
		_capacity_end = _end = _start;}

		// 3) Constructs the container with count copies of elements with value value.

		explicit vector(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type()) {
			_alloc = alloc;
			_start = _alloc.allocate(n, NULL);
			_capacity_end = _start + n;
			for (size_type i = 0;i < n; i++)
				_alloc.construct(_start + i, val);
			_end = _capacity_end;}

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

		vector<T,Alloc>( const vector& other ){
			_alloc = other._alloc;
			_start = _alloc.allocate(other.capacity());
			_capacity_end = _start + other.size();
			for (ft::pair<vector::const_iterator,int> i(other.begin(),0);
			i.first != other.end();i.first++,i.second++){
				_alloc.construct(_start + i.second, *i.first);}
			_end = _start + other.size();
		}

		// Destructs the vector. The destructors of the elements are called and the used storage is deallocated.

		~vector<T,Alloc>() {
			value_type *ptr = _start;
			for (size_type i = 0; i< size(); i++)
			{
				_alloc.destroy(ptr + i);
			}
			_alloc.deallocate(_start, capacity());
		}

		// Copy assignment operator. Replaces the contents with a copy of the contents of other.

		vector & operator=(vector const & op){
			if (op.size() > capacity()){
				for (iterator it = begin(); it != end(); ++it)
					_alloc.destroy(&(*it));
				_alloc.deallocate(_start,capacity());
				_start = _alloc.allocate(op.size(), NULL);
				_end = _start + op.size();
				_capacity_end = _end;}
			for (size_t i = 0; i < op.size();i++){
				_alloc.construct(_start + i, op.at(i));}
			_end = _start + op.size();
			_capacity_end = _end;
			return *this;
		}

		alloc_type get_allocator() const{return _alloc;}

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

		void assign (size_type n, const value_type& val){
			clear();
			if (n > capacity())
				reserve(n);
			for (size_type i = 0; i < n;i++){
				_alloc.construct(_start + i, val);}
			_end = _start + n;}

		// * Element access

		// Returns a reference to the element at specified location pos, with bounds checking.

		reference at( size_type pos ){
			if (pos >= size())
				throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			return(*(_start + pos));}

		const_reference at(size_type n) const{
			if (size() < n)
				throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			return(*(_start + n));}

		// Returns a reference to the element at specified location pos. No bounds checking is performed.

		reference operator[]( size_type pos ){return (*(_start + pos));}
		const_reference operator[] (size_type n) const{return (*(_start + n));}

		// Returns a reference to the first element in the container.

		reference front(){return(*_start);}
		const_reference front() const{return(*_start);}

		// Returns a reference to the last element in the container.

		reference back(){return(*(_end - 1));}
		const_reference back() const{return(*(_end - 1));}

		// Returns pointer to the underlying array serving as element storage.

		value_type *data(){return(this->_start);}
		const value_type *data() const{return(this->_start);}

		// * Iterators

		iterator				begin(){
			return (iterator(_start));}
		const_iterator 			begin() const {
			return const_iterator(_start);}
		iterator				end(){
			return (iterator(_end));}
		const_iterator 			end() const{
			return (const_iterator(_end));}
		reverse_iterator		rbegin(){
			return (reverse_iterator(end()));}
		const_reverse_iterator	rbegin() const{
			return (reverse_iterator(end()));}
		reverse_iterator	rend(){
			return (reverse_iterator(begin()));}
		const_reverse_iterator	rend() const{
			return (reverse_iterator(begin()));}

		// * Capacity

		// Returns whether the vector is empty (i.e. whether its size is 0).

		bool		empty() const{
			if (_start == _end)
				return (true);
			return (false);}

		// Returns the number of elements in the vector.

		size_type	size() const{
			return(_end - _start);}

		// Returns the maximum number of elements that the vector can hold.

		size_type	max_size() const{
			return(_alloc.max_size());}

		// Increase the capacity of the vector to a value that's greater or equal to new_cap.

		void	reserve(size_type n){
			if (n > capacity()){
				value_type *ptr = _start;
				size_type actual_size = size();
				_start = _alloc.allocate(n, NULL);
				for(size_type i = 0; i < actual_size; ++i){
					_alloc.construct(_start + i, ptr[i]);
					_alloc.destroy(ptr + i);
				}
				_alloc.deallocate(ptr, actual_size);
				_end = _start + actual_size;
				_capacity_end = _start + n;}
		}

		// Returns the number of elements that the container has currently allocated space for.

		size_type	capacity() const{return((_capacity_end - _start));}

		// * Modifiers

		// Erases all elements from the container. After this call, size() returns zero.

		void	clear(){
			while (size())
				pop_back();
		}

		// Inserts elements value at the specified pos in the container.

		iterator insert( iterator pos, const_reference value ){
			size_type spos = 0;
			for (iterator i = begin(); i != pos;i++,spos++){}
			if (size() == capacity() && size() > 0)
				reserve(capacity() * 2);
			if (size() == 0)
				reserve(1);
			for (size_t i = size(); i > spos;i--)
				_alloc.construct(_start + i, _start[i - 1]);
			_alloc.construct(_start + spos, value);
			_end++;
			return begin() + spos;}

		// Inserts counts of elements value at the specified pos in the container.

		void insert( iterator pos, size_type count, const_reference value){
			size_type spos = 0;
			if (count == 0){return ;}
			for (iterator i = begin(); i != pos;i++,spos++){}
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
			for (size_type i = 0; i < count; i++)
			{
				_alloc.construct(_start + i + spos, value);
			}
			_end += count;
			}

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

		iterator erase( iterator pos ){
			for (iterator it = pos; it != end(); it++)
			{
				if (it + 1 != end())
					ft::swap(*it,*(it + 1));
			}
			pop_back();
			if (pos != end())
				return pos;
			return end();
		}

		// Erases a range (first and last) of specified elements from the container.

		iterator erase( iterator first, iterator last ){
			size_type range = 0;
			for(iterator i = first; i != last;i++,range++){}
			for (size_type i = 0; i < range; i++)
				erase(first);
			return last - range;
		}

		// Appends the given element value to the end of the container.

		void push_back( const_reference value ){
			if (size() == 0)
				reserve(1);
			else if (size() == capacity())
				reserve(capacity() *2);
			_alloc.construct(_start + size(),value);
			_end++;
		}

		// Removes the last element of the container.

		void pop_back(){
		if (size())
		{
			pointer ptr = --_end;
			_alloc.destroy(ptr);
		}
		}

		// Exchanges the contents of the container with those of other.
		// Does not invoke any move, copy, or swap operations on individual elements.

		void swap (vector& Other){
			pointer ptr[3];
			alloc_type mem = Other._alloc;
			ptr[0] = Other._start;
			ptr[1] = Other._end;
			ptr[2] = Other._capacity_end;
			Other._start = this->_start;
			Other._end = this->_end;
			Other._capacity_end = this->_capacity_end;
			Other._alloc = this->_alloc;
			_start = ptr[0];
			_end = ptr[1];
			_capacity_end = ptr[2];
			_alloc = mem;
		}



		void resize (size_type n, value_type val = value_type()){
			if (n < capacity() * 2 && n > capacity())
				reserve(capacity() * 2);
			else if (n > capacity())
				reserve(n);
			while (n > size())
				push_back(val);
			while (n < size())
				pop_back();}

friend bool			operator==(const vector& lhs, const vector& rhs ){
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

friend void swap(vector& x,vector&y){x.swap(y);}

};
}
#endif
