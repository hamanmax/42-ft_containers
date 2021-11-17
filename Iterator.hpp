#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>

template<
	class Category,
	class T,
	class Distance = std::ptrdiff_t,
	class Pointer = T*,
	class Reference = T&
>
class Iterator
{
    typedef T			value_type;
    typedef Distance	difference_type;
    typedef Pointer		pointer;
    typedef Reference	reference;
    typedef Category	iterator_category;
	private:
		/*Arg*/
	protected:
		/*Arg*/
	public:
		Iterator();
		Iterator(Iterator const & copy);
		Iterator & operator=(Iterator const & op);
		~Iterator();
};

#endif
