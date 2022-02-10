#ifndef Vector_HPP
#define Vector_HPP

#include <memory>
#include <string>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include "Iterator.hpp"
#include "Utility.hpp"
#include "ReverseVectorIterator.hpp"

namespace ft
{
template<class T,class Alloc = std::allocator<T> >
class Vector
{
	public:
		typedef T					value_type;
		typedef Alloc				alloc_type;
		typedef size_t				size_type;
		typedef typename alloc_type::pointer		pointer;
		typedef typename alloc_type::const_pointer	const_pointer;
		typedef typename alloc_type::reference&		reference;
		typedef const value_type&					const_reference;
		typedef VectorIterator<RandomAccessIteratorTag ,Vector>				iterator;
		typedef const VectorIterator<RandomAccessIteratorTag, Vector>		const_iterator;
		typedef ReverseVectorIterator<RandomAccessIteratorTag ,Vector>				reverse_iterator;
		typedef const ReverseVectorIterator<RandomAccessIteratorTag, Vector>		const_reverse_iterator;
	private:
		pointer	_start; // Start
		pointer	_capacity_end; //Capacity
		pointer	_end; //Size
	public:

		// * Constructeur / Destructeur


		explicit Vector(const alloc_type& alloc = alloc_type()){
		alloc_type	mem;
		mem = alloc;
		_start = mem.allocate(0, NULL);
		_capacity_end = _end = _start;
		}

		explicit Vector(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type()) {
			alloc_type	mem;
			mem = alloc;
			_start = mem.allocate(n, NULL);
			_capacity_end = _start + n;
			for (size_type i = 0;i < n; i++)
				mem.construct(_start + i, val);
			_end = _capacity_end;}

		template<class InputIterator>
		Vector(InputIterator first, InputIterator last,const alloc_type& alloc = alloc_type(),typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
			alloc_type mem;
			mem = alloc;
			size_type i = 0;
			InputIterator it(first);
			while (it != last){
				i++;
				it++;
			};
			_start = mem.allocate(i, NULL);
			_capacity_end = _start + i;
			for (size_type i = 0; first != last; ++first,++i){
				mem.construct(_start + i, *first);}
			_end = _capacity_end;
		}

		Vector<T,Alloc>( const Vector& other ){
			alloc_type mem;
			_start = mem.allocate(other.capacity());
			_capacity_end = _start + other.capacity();
			for (ft::pair<Vector::iterator,int> i(other.begin(),0);i.first  != other.end();i.first++,i.second++)
			{
				_start[i.second] = *i.first;
			}
			_end = _start + other.size();
		}

		~Vector<T,Alloc>() {
			Alloc _mem;
			_mem.deallocate(_start,capacity());
		}

		Vector & operator=(Vector const & op){
			alloc_type mem;
			if (op.size() > capacity())
			{
				mem.deallocate(_start,capacity());
				_start = mem.allocate(op.size(), NULL);
				_end = _start + op.size();
				_capacity_end = _end;
			}
			else
			{
				for (size_t i = 0; i < op.size();i++)
				{
					_start[i] = op[i];
				}
				_end = _start + op.size();
				_capacity_end = _end;
			}
			return *this;
		}

		// * Element access

		reference at( size_type pos ){
		if (pos >= size())
			throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
		return(*(_start + pos));}
		const_reference at(size_type n) const{
			if (size() < n)
			throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			return(*(_start + n));}

		reference operator[]( size_type pos ){return (*(_start + pos));}
		const_reference operator[] (size_type n) const{return (*(_start + n));}

		reference front(){return(*_start);}
		const_reference front() const{return(*_start);}

		reference back(){return(*(_end - 1));}
		const_reference back() const{return(*(_end - 1));}

		value_type *data(){return(this->_start);}

		const value_type *data() const{return(this->_start);}

		// * Iterators

		iterator				begin(){
			return (iterator(_start));}
		iterator				end(){
			return (iterator(_end));}
		const_iterator 			begin() const{
			return (const_iterator(_start));}
		const_iterator 			end() const{
			return (const_iterator(_end));}

		reverse_iterator		rbegin(){
			return (reverse_iterator(_end - 1));}

		const reverse_iterator	rbegin() const{
			return (const_reverse_iterator(_end - 1));}
		reverse_iterator	rend(){
			return (reverse_iterator(_start - 1));}
		const reverse_iterator	rend() const{
			return (const_reverse_iterator(_start - 1));}

		// * Capacity

		bool		empty() const{
			if (_start == _capacity_end)
				return (true);
			return (false);}

		size_type	size() const{
			return(_end - _start);}

		size_type	max_size() const{
			alloc_type mem;
			return(mem.max_size());}

		void	reserve(size_type n){
			if (n > capacity())
			{
				value_type *ptr = _start;
				size_type actual_size = size();
				alloc_type mem;
				_start = mem.allocate(n, NULL);
				for(size_type i = 0; i < actual_size; i++){
					mem.construct(_start + i, ptr[i]);
				}
				mem.deallocate(ptr, actual_size);
				_end = _start + actual_size;
				_capacity_end = _start + n;
			}
		}

		size_type	capacity() const{return((_capacity_end - _start));}

		// * Modifiers

		void	clear(){
			alloc_type mem;
			while (_end != _start)
			{
				--_end;
				mem.destroy(_end);
			}
		}

		iterator insert( iterator pos, const_reference value ){
			size_type spos = 0;
			for (iterator i = begin(); i != pos;i++,spos++){}
			if (size() == capacity())
				reserve(capacity() * 2);
			for (size_t i = size(); i > spos;i--)
				_start[i] = _start[i - 1];
			_start[spos] = value;
			_end++;
			return begin() + spos;
		}

		void insert( iterator pos, size_type count, const_reference value){
			size_type spos = 0;
			for (iterator i = begin(); i != pos;i++,spos++){}
			if ( size() + count > capacity())
				reserve (size() + count);
			for (size_type i = size() + count - 1; i > spos + count - 1; i-- )
				_start[i] = _start[i - count];
			for (size_type i = 0; i < count; i++)
				_start[i + spos] = value;
			_end += count;
		}


		template< class InputIterator >
		void insert( iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0){
			size_type spos = 0;
			size_type count = 0;
			for (iterator i = begin(); i != pos;i++,spos++){}
			for (InputIterator i = first; i != last;i++,count++){}
			if ( size() + count > capacity())
				reserve (size() + count);
			for (size_type i = size() + count - 1; i > spos + count - 1; i-- )
				_start[i] = _start[i - count];
			for (ft::pair<size_type,InputIterator> i(0,first); i.first < count; i.second++,i.first++)
				_start[i.first + spos] = *i.second;
			_end += count;
		}

		iterator erase( iterator pos ){
			size_type i = 0;
			for (iterator it = pos; it != end(); it++)
			{
				if (it + 1 == end())
				{
					_end -= 1;
					break ;
				}
				*it = *(it + 1);
			}
			return pos;
		}


		void push_back( const_reference value ){
			std::allocator<value_type> mem;
			if (size() == capacity())
			{
				size_type _size = size();
				size_type _capacity = capacity();
				pointer ptr;
				ptr = mem.allocate(capacity() * 2, NULL);
				for(size_type i = 0; i < _size; i++){
					mem.construct(ptr + i, data()[i]);
				}
				mem.deallocate(_start, _capacity);
				_start = ptr;
				_end = _start + _size;
				_capacity_end = _start + (_capacity * 2);
			}
			mem.construct(_end,value);
			_end++;
		}

		void pop_back(){
		(void)(_end - 1);
		_end = _end - 1;
		}

		void swap (Vector& Other){
			pointer ptr[3];
			ptr[0] = Other._start;
			ptr[1] = Other._end;
			ptr[2] = Other._capacity_end;
			Other._start = this->_start;
			Other._end = this->_end;
			Other._capacity_end = this->_capacity_end;
			_start = ptr[0];
			_end = ptr[1];
			_capacity_end = ptr[2];
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last){
			size_type n = 0;
			for (InputIterator i = first; i != last;i++,n++){}
			if (n > capacity())
				reserve(n);
			for (ft::pair<size_type,InputIterator> i(0,first); i.first < n;i.first++,i.second++){
				_start[i.first] = *i.second;
			}
			_end = _start + n;
		}

		void assign (size_type n, const value_type& val){
			if (n > capacity())
				reserve(n);
			for (size_type i = 0; i < n;i++){
				_start[i] = val;
			}
			_end = _start + n;
		}

		void resize (size_type n, value_type val = value_type()){
			if (n > capacity())
				reserve(n);
			while (n > size())
				push_back(val);
			while (n < size())
				pop_back();
		}

friend bool			operator==(const Vector& lhs, const Vector& rhs ){
	if (lhs.size() != rhs.size())
		return false;

	for (size_type i = 0; i < lhs.size();i++) {
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

friend bool			operator!=(const Vector& lhs, const Vector& rhs ){return !(lhs == rhs);}

friend bool	operator<(const Vector& lhs, const Vector& rhs ){

	for (ft::pair<iterator, iterator> it(lhs.begin(), rhs.begin());
	it.first != lhs.end() && it.second != rhs.end(); it.first++, it.second++)
	{
		std::cout << "tutu" << std::endl;
		if (*(it.first) < *(it.second))
			return true;
	}
	return (lhs.size() < rhs.size());}

friend bool	operator>(const Vector& lhs, const Vector& rhs){return (rhs < lhs);}

friend bool	operator<=(const Vector& lhs, const Vector& rhs){return (!(rhs < lhs));}

friend bool	operator>=(const Vector& lhs, const Vector& rhs){return (!(lhs < rhs));}

};
}
#endif
