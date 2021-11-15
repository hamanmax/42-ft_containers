#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <string>
#include <iostream>

class Vector
{
	private:
	protected:
	public:
		std::allocator<int>	_mem;
		int					*_data;
		size_t				_capacity;

		Vector(){};
		Vector(Vector const & copy);
		Vector(ssize_t size);
		Vector & operator=(Vector const & op);
		~Vector();

		ssize_t							Capacity();
		std::reverse_iterator<Vector>	rbegin();
};

Vector::Vector(ssize_t size) {
	this->_data = this->_mem.allocate(size, NULL);
	this->_capacity = size;
	std::cout << *this->_data << std::endl;
}
Vector::~Vector() {
	_mem.deallocate(this->_data,this->_capacity);
}
ssize_t Vector::Capacity(){
			return(this->_capacity);
		}

//template <typename T, typename Allocator>
//Vector::Vector(ssize_t size) {}
#endif
