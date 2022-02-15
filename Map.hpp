#ifndef MAP_HPP
#define MAP_HPP

#include "Utility.hpp"
#include <memory>
#include <functional>
#define LEFT 0;
#define RIGHT 1;
#define left child[LEFT];
#define right child[RIGHT];
namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<Key,T> > >
	class Map
	{
		public:
			typedef Key									key_type;
			typedef T									mapped_type;
			typedef std::pair<const Key,T>				value_type;
			typedef size_t								size_type;
			typedef ptrdiff_t							difference_type;
			typedef Compare								key_compare;
			typedef Allocator							allocator_type;
			typedef value_type&							reference;
			typedef const value_type&					const_reference;
			typedef typename Allocator::pointer			pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			// TODO typedef MapIterator<BidirectionalIteratorTag,Map>		iterator;
			// TODO typedef const MapIterator<BidirectionalIteratorTag,Map>	const_iterator;
			// TODO typedef ReverseMapIterator<BidirectionalIteratorTag,Map>	reverse_iterator;
			// TODO typedef const ReverseMapIterator<BidirectionalIteratorTag,Map>	const_reverse_iterator;
		private:
		enum color_t {BLACK, RED};
		struct Node
		{
			value_type			content;
			Node*				parent;
			Node*				child[2];
			color_t				color;
		};
		struct RbTree{
			Node *	root;
		};
		RbTree		_data;
		size_type	size;
		allocator_type	allocator;
		key_compare v;
		std::allocator<Node> Alloc;
		public:

		// TODO map();
		// TODO explicit map(const Compare& comp, const Allocator & alloc = Allocator() );

		// TODO template< class InputIterator > map(InputIterator first, InputIterator last,const Compare& comp = Compare(),const Allocator & alloc = Allocator() );

		// TODO map(const map& other);
	};
};


#endif
