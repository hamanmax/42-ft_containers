#ifndef vector_HPP
#define vector_HPP

#include <memory>
#include <string>
#include <iostream>
#include <iterator>
#include <cstdlib>
#include "Iterator.hpp"

namespace ft
{
template<class T,class Alloc = std::allocator<T>>
class vector
{
	public:
		typedef T					value_type;
		typedef Alloc				alloc_type;
		typedef size_t				size_type;
		typedef typename alloc_type::pointer			pointer;
		typedef typename alloc_type::const_pointer		const_pointer;
		typedef typename alloc_type::reference&			reference;
		typedef const value_type&	const_reference;
		typedef Iterator<vector>						iterator;
		typedef const Iterator<vector>					const_iterator;
	private:
		pointer	_start;
		pointer	_capacity_end;
		pointer	_end;
	public:

		// * Constructeur / Destructeur

		//TODO vector (InputIterator first, InputIterator last,
		//TODO	const alloc_type& alloc = alloc_type());

		vector (size_type n, const value_type& val = value_type(), const alloc_type& alloc = alloc_type()) {
			alloc_type	mem;
			mem = alloc;
			_start = mem.allocate(n, NULL);
			_capacity_end = _start + n;
			for (size_type i = 0;i < n; i++)
				_start[i] = val;
			_end = _capacity_end;}

		vector<T,Alloc>( const vector& other );

		~vector<T,Alloc>() {
			alloc_type _mem;
			if (_capacity_end != _start)
				_mem.deallocate(_start,this->capacity());
		}
		vector<T,Alloc>(const alloc_type& alloc = alloc_type()){
		_start = alloc.allocate(0,NULL);
		_capacity_end = _end = _start;
		}

		vector & operator=(vector const & op);

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
			std::allocator<value_type> mem;
			while (_end != _start)
			{
				--_end;
				mem.destroy(_end);
			}
		}

		iterator insert( iterator pos, const_reference value ){
			if (size() == capacity())
			{
				value_type	*ptr;
				size_type actualsize = size();
				Alloc	mem;
				ptr = mem.allocate(capacity() * 2,NULL);
				value_type i = 0;
				for (iterator it = begin(); it != end();)
				{
					if (it != pos)
						ptr[i] = *it;
					else
					{
						ptr[i] = value;
					}
					it++;
					i++;
					if ( it == end())
					{
						it--;
						ptr[i] = *it;
						break;
					}
				}
				mem.deallocate(_start,capacity());
				_start = ptr;
				_end = _start + actualsize + 1;
				_capacity_end = _start + (actualsize * 2);
			}
			return begin();
		}

		void insert( iterator pos, size_type count, const_reference value ){
			for (size_type i = 0;i != count;i++)
			{
				*pos = value;
				pos++;
			}
		}
		void insert( iterator pos, iterator first, iterator last );

		// TODO iterator erase( iterator pos );
		// TODO iterator erase( iterator first, iterator last );


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
			_end++;
			*_end = value;
		}

		void pop_back(){
		(void)(_end - 1);
		_end = _end - 1;
		}

};
}

// * Non-member Functions

// TODO bool			operator==(const vector& lhs, const vector& rhs ){
// TODO 	return(false);
// TODO 	}

// TODO template< class T, class Alloc >bool			operator!=
// TODO			(const std::vector<T,Alloc>& lhs,
// TODO			const std::vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator<
//TODO			( const std::vector<T,Alloc>& lhs,
//TODO			const std::vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator<=
//TODO			( const std::vector<T,Alloc>& lhs,
//TODO			const std::vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator>
//TODO			( const std::vector<T,Alloc>& lhs,
//TODO			const std::vector<T,Alloc>& rhs );

// TODO template< class T, class Alloc >bool			operator>
//TODO			( const std::vector<T,Alloc>& lhs,
//TODO			const std::vector<T,Alloc>& rhs );
#endif
