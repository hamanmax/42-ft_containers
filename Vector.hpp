#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>
#include <iterator>

class Vector
{
	private:
	protected:
		int		*_data;
		void	*_capacity;
		void	*_size;
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
		// TODO explicit Vector(const std::allocator<int>& alloc);
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
		// TODO reference at( size_type pos );
		// TODO const_reference at( size_type pos ) const;

		reference operator[]( size_type pos );
		const_reference operator[] (size_type n) const;

		// TODO reference front();
		// TODO const_reference front() const;

		// TODO reference back();
		// TODO const_reference back() const;

		int *data();
		const int *data() const;

		// * Iterators

		// TODO iterator				begin(){
		// TODO 	return (iterator(_data));
		// TODO }
		// TODO const iterator 			begin() const;
		// TODO iterator				end();
		// TODO const iterator			end() const;
		// TODO reverse_iterator		rbegin();
		// TODO const reverse_iterator	rbegin() const;

		// TODO reverse_iterator	rend();
		// TODO const reverse_iterator	rend() const;

		// * Capacity

		bool			empty();
		ssize_t			size();
		ssize_t			max_size();
		void			reserve(size_type n);
		ssize_t			capacity();

		// * Modifiers

		// TODO void			clear();

		// TODO iterator insert( iterator pos, const T& value );
		//void insert( iterator pos, size_type count, const int& value );
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
// TODOVector::Vector(const std::allocator<int>& alloc){
// TODO	alloc.construct(_data,NULL);
// TODO}

Vector::Vector(){
	std::allocator<int> _mem;
	_data = _mem.allocate(0,NULL);
	_capacity = _size = _data;
}

Vector::Vector(ssize_t size) {
	std::allocator<int> _mem;
	_data = _mem.allocate(size, NULL);
	_capacity = _data + 40;
	_size = _capacity;
}
Vector::~Vector() {
	std::allocator<int> _mem;
	if (_capacity != _data)
		_mem.deallocate(_data,this->capacity());
}

int *Vector::data(){
	return(this->_data);
}

const int *Vector::data() const{
	return(this->_data);
}

ssize_t	Vector::max_size(){
	std::allocator<int> mem;
	return(mem.max_size());
}

void	Vector::reserve(size_type n){
	if (n > Vector::capacity())
	{
		std::cout << "\033[35mHOULOULOU\033[0m" << std::endl;
		int * ptr = _data;
		size_t size = Vector::size();
		std::allocator<int> mem;
		_data = mem.allocate(n, NULL);
		for(size_t i = 0; i < size; i++){
			_data[i] = ptr[i];
		}
		mem.deallocate(ptr, size);
		_size = _data + size * sizeof(int);
		_capacity = _data + n * sizeof(int);
	}
}

ssize_t		Vector::capacity(){
	return( ((int *)_capacity - _data) / sizeof(int));
}

bool		Vector::empty(){
	if (_data == _capacity)
		return (true);
	return (false);
}

ssize_t		Vector::size(){
	return(((int *)_size - _data) / sizeof(int));
}

Vector::reference Vector::operator[]( size_type pos ){
	return (*(_data + pos * sizeof(value_type)));
}

Vector::const_reference Vector::operator[] (size_type n) const{
	return (*(_data + n * sizeof(value_type)));
}
#endif
