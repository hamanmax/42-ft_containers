#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
template<typename T>
class Iterator
{
	public:
	typedef typename T::value_type		value_type;
	typedef typename T::pointer			pointer;
	typedef typename T::reference		reference;
	typedef typename T::const_reference	const_reference;
	private:
		pointer _mptr;
	protected:
		/*Arg*/
	public:
		Iterator(pointer ptr):_mptr(ptr){};
		Iterator():_mptr(0){};
		Iterator(Iterator const & copy);
		Iterator & operator=(Iterator const & op);
		~Iterator(){};
		reference operator*(){
			return *_mptr;
		}
		bool operator!=(const Iterator& Other) const
		{
			return !(this->_mptr == Other._mptr);
		}
		bool operator==(const Iterator& Other) const
		{
			return this->_mptr == Other._mptr;
		}
		Iterator&	operator++()
		{
			_mptr++;
			return(*this);
		}
		Iterator&	operator++(int)
		{
			_mptr++;
			return(*this);
		}
		Iterator&	operator--()
		{
			_mptr--;
			return(*this);
		}
		Iterator&	operator--(int)
		{
			_mptr--;
			return(*this);
		}
};

#endif
