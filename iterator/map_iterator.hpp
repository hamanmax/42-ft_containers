
#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "iterator.hpp"
#include "../template/red_black_tree.hpp"

template<
			class T,
			class map,
			class Compare,
			class Pointer = T*,
			class Reference = T&,
			class Category = BidirectionalIteratorTag
		>
class map_iterator: public ft::iterator<Category,T>
{
public:
	typedef Pointer								pointer;
	typedef Reference							reference;
	typedef Compare								key_compare;
typedef typename map::mapped_type				mapped_type;
typedef typename map::key_type					key_type;
typedef T										value_type;
typedef node<key_type, mapped_type,Compare>*	node_pointer;
private:
	key_compare		_comp;
	node_pointer	_mptr;
	node_pointer	_dummy;
public:
	map_iterator(node_pointer const & ptr,node_pointer const &  dummy);
	map_iterator();
	map_iterator(map_iterator const & copy);
	template <typename U,typename V,typename X>
	map_iterator( const map_iterator<U,V,X>  & copy){_comp = copy.getcompare();_mptr = copy.getptr();_dummy = copy.getdummy();}
	~map_iterator();
	map_iterator & operator=(map_iterator const & copy);

	bool operator==(const map_iterator& Other) const;
	bool operator!=(const map_iterator& Other) const;

	reference operator*() const;
	pointer operator->() const;


	node_pointer getptr()const;
	node_pointer getdummy()const;
	key_compare getcompare()const;


	node_pointer Minimum();
	node_pointer Maximum();

	map_iterator& operator++();
	map_iterator operator++(int);

	map_iterator& operator--();
	map_iterator operator--(int);
};

#include "map_iterator.tpp"
#endif
