#ifndef Vector_HPP
#define Vector_HPP

#include <memory>
#include <string>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include "Iterator.hpp"
#include "Utility.hpp"

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
	private:
		pointer	_start; // Start
		pointer	_capacity_end; //Capacity
		pointer	_end; //Size
	public:

		// * Constructeur / Destructeur


		explicit Vector(const alloc_type& alloc = alloc_type()){
		_start = alloc.allocate(0,NULL);
		_capacity_end = _end = _start;
		}

		explicit Vector(size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type()) {
			alloc_type	mem;
			mem = alloc;
			_start = mem.allocate(n, NULL);
			_capacity_end = _start + n;
			for (size_type i = 0;i < n; i++)
				_start[i] = val;
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
				_start[i] = *first;}
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
			if (_capacity_end != _start)
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
			return (iterator(_start));}
		const_iterator 			end() const{
			return (iterator(_end));}
		// TODO reverse_iterator		rbegin();
		// TODO const reverse_iterator	rbegin() const;

		// TODO reverse_iterator	rend();
		// TODO const reverse_iterator	rend() const;

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
				for(value_type i = 0; i < actual_size; i++){
					_start[i] = ptr[i];
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
			if (size() == capacity())
			{
				value_type _size = size();
				value_type _capacity = capacity();
				value_type *ptr;
				std::allocator<value_type> mem;
				ptr = mem.allocate(capacity() * 2, NULL);
				for(value_type i = 0; i < size(); i++){
					ptr[i] = data()[i];
				}
				mem.deallocate(_start, _capacity);
				_start = ptr;
				_end = _start + _size;
				_capacity_end = _start + (_capacity * 2);
			}
			*_end = value;
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

		// TODO template <class InputIterator> void assign (InputIterator first, InputIterator last);
		// TODO void assign (size_type n, const value_type& val);
		// TODO Resize

};
}

// * Non-member Functions

// TODO bool			operator==(const Vector& lhs, const Vector& rhs ){
// TODO 	return(false);
// TODO 	}

// TODO template< class T, class Alloc >bool			operator!=
// TODO			(const std::Vector<T,Alloc>& lhs,
// TODO			const std::Vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator<
//TODO			( const std::Vector<T,Alloc>& lhs,
//TODO			const std::Vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator<=
//TODO			( const std::Vector<T,Alloc>& lhs,
//TODO			const std::Vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator>
//TODO			( const std::Vector<T,Alloc>& lhs,
//TODO			const std::Vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator>
//TODO			( const std::Vector<T,Alloc>& lhs,
//TODO			const std::Vector<T,Alloc>& rhs );
#endif
