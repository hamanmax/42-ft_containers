#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>
#include <iterator>
#include <cstdlib>

class Vector
{
	private:
	protected:

		int		*_start;
		int		*_capacity_end;
		int		*_end;

	public:

		typedef int					value_type;
		typedef std::allocator<int>	allocator_type;
		typedef size_t				size_type;
		typedef ptrdiff_t 			difference_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		//typedef pointer
		typedef std::iterator<struct random_access_iterator_tag,int>	iterator;
		typedef std::reverse_iterator<iterator>							reverse_iterator;

		// * Constructeur / Destructeur

		Vector();
		// TODO explicit Vector(const allocator_type& alloc);
		// TODO explicit vector( size_type count,
				// TODO const int& value = int(),
				// TODO const Allocator& alloc = Allocator());

		// TODO template< class InputIt >vector( InputIt first, InputIt last,
				// TODO const Allocator& alloc = Allocator() );

		Vector( const Vector& other );
		Vector(ssize_t size); // A Delete
		~Vector();

		Vector & operator=(Vector const & op);

		// * Element access
		reference at( size_type pos );
		const_reference at( size_type pos ) const;

		reference operator[]( size_type pos );
		const_reference operator[] (size_type n) const;

		reference front();
		const_reference front() const;

		reference back();
		const_reference back() const;

		int *data();
		const int *data() const;

		// * Iterators

		// TODO iterator				begin(){
		// TODO 	return (iterator(_start));
		// TODO }
		// TODO const iterator 			begin() const;
		// TODO iterator				end();
		// TODO const iterator			end() const;
		// TODO reverse_iterator		rbegin();
		// TODO const reverse_iterator	rbegin() const;

		// TODO reverse_iterator	rend();
		// TODO const reverse_iterator	rend() const;

		// * Capacity

		bool			empty() const;
		ssize_t			size() const;
		ssize_t			max_size() const;
		void			reserve(size_type n);
		ssize_t			capacity() const;

		// * Modifiers

		void			clear();

		// TODO iterator insert( iterator pos, const T& value );
		// TODO void insert( iterator pos, size_type count, const int& value );
		// TODO template< class InputIt >
			// TODO void insert( iterator pos, InputIt first, InputIt last );

		// TODO iterator erase( iterator pos );
		// TODO iterator erase( iterator first, iterator last );

		// TODO void push_back( const T& value );

		// TODO void pop_back();

};

// * Non-member Functions

// TODO template< class T, class Alloc >bool			operator==
// TODO			(const std::vector<T,Alloc>& lhs,
// TODO			const std::vector<T,Alloc>& rhs );

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


// TODOVector::Vector(const allocator_type& alloc){
// TODO	alloc.construct(_start,NULL);
// TODO}

Vector::Vector(){
	allocator_type _mem;
	_start = _mem.allocate(0,NULL);
	_capacity_end = _end = _start;
}

Vector::Vector(ssize_t size) {
	allocator_type _mem;
	_start = _mem.allocate(size, NULL);
	_capacity_end = _start + 10;
	_end = _capacity_end;
}
Vector::~Vector() {
	allocator_type _mem;
	if (_capacity_end != _start)
		_mem.deallocate(_start,this->capacity());
}

int *Vector::data(){
	return(this->_start);
}

const int *Vector::data() const{
	return(this->_start);
}

ssize_t	Vector::max_size() const{
	allocator_type mem;
	return(mem.max_size());
}

void	Vector::reserve(size_type n){
	if (n > Vector::capacity())
	{
		int * ptr = _start;
		size_t size = Vector::size();
		allocator_type mem;
		_start = mem.allocate(n, NULL);
		for(size_t i = 0; i < size; i++){
			_start[i] = ptr[i];
		}
		mem.deallocate(ptr, size);
		_end = _start + size;
		_capacity_end = _start + n;
	}
}

ssize_t		Vector::capacity() const{
	return((_capacity_end - _start));
}

bool		Vector::empty() const{
	if (_start == _capacity_end)
		return (true);
	return (false);
}


void	Vector::clear(){
	std::allocator<value_type> mem;
	while (_end != _start)
	{
		--_end;
		mem.destroy(_end);
	}
}

ssize_t		Vector::size() const{
	return(_end - _start);
}

Vector::reference Vector::operator[]( size_type pos ){
	return (*(_start + pos));
}

Vector::const_reference Vector::operator[] (size_type n) const{
	return (*(_start + n));
}


Vector::reference Vector::front(){
	return(*_start);
}

Vector::const_reference Vector::front() const{
	return(*_start);
}


Vector::reference Vector::back(){
	return(*(_end - 1));
}
Vector::const_reference Vector::back() const{
	return(*(_end - 1));
}

Vector::reference Vector::at( size_type pos ){
	if (pos >= Vector::size())
		throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
	return(*(_start + pos));
}

Vector::const_reference Vector::at(size_type n) const{
	if (Vector::size() < n)
		throw std::out_of_range::exception();
	return(*(_start + n));
}

#endif
