#ifndef ITERATOR_HPP
#define ITERATOR_HPP

struct InputIteratorTag{};

struct OutputIteratorTag{};

struct ForwardIteratorTag : public InputIteratorTag {};

struct BidirectionalIteratorTag : public ForwardIteratorTag {};

struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};


template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class Iterator{
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};


#endif
