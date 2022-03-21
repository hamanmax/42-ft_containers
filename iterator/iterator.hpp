#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <cstddef>

struct InputIteratorTag{};

struct OutputIteratorTag{};

struct ForwardIteratorTag : public InputIteratorTag {};

struct BidirectionalIteratorTag : public ForwardIteratorTag {};

struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};

namespace ft
{
template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class iterator{
	public:
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

template<class Iter>
struct iterator_traits{
	public:
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
	typedef typename Iter::iterator_category	iterator_category;
};

template<typename T>
struct iterator_traits<T*>{
	public:
	typedef RandomAccessIteratorTag				iterator_category;
	typedef T									value_type;
	typedef ptrdiff_t							difference_typee;
	typedef T*									pointer;
	typedef T&									reference;
};

template<typename T>
struct iterator_traits<const T*>{
	typedef RandomAccessIteratorTag				iterator_category;
	typedef T									value_type;
	typedef ptrdiff_t							difference_typee;
	typedef const T*							pointer;
	typedef const T&							reference;
};
};

#endif
