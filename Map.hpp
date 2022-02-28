#ifndef MAP_HPP
#define MAP_HPP

#include "Utility.hpp"
#include "RedBlackTree.hpp"
#include <memory>
#include <functional>
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
			typedef ft::pair<Key,T>						value_type;
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
		RBTree<Key,T>	tree;
		allocator_type	allocator;
		key_compare v;
		public:

		Map():allocator(Allocator()),tree(RBTree<Key,T>()),v(Compare()){
		};
		explicit Map(const Compare& comp, const Allocator & alloc = Allocator()):allocator(alloc),tree(RBTree<Key,T>()),v(comp){}

		template< class InputIterator >
		Map(InputIterator first, InputIterator last,const Compare& comp = Compare(),const Allocator & alloc = Allocator() ):v(comp), allocator(alloc){
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		};

		Map(const Map& other){
			allocator = other.allocator;
			v = other.v;
		}

		~Map(){
			while (tree.getSize() != 0){
				//std::cout << tree.getSize() << std::endl;
				tree.deleteNode(tree.getRoot());
			}
		}

		// TODO operator=( const map& other );

		// TODO allocator_type get_allocator() const {};

		// * Element Acces

		// TODO mapped_value& at(const Key& key){};
		// TODO const mapped_value& at(const Key& key) const {};

		// TODO mapped_value& operator[]( const Key& key ) {};

		// * Iterators

		// TODO iterator begin(){};
		// TODO const_iterator begin() const {};

		// TODO iterator end() const {};
		// TODO const_iterator end() const {};

		//TODO reverse_iterator rbegin(){};
		//TODO const_reverse_iterator rbegin() const {};

		//TODO reverse_iterator rend(){};
		//TODO const_reverse_iterator rend() const {};

		// * Capacity

		// TODO bool empty() const {};

		// TODO size_type size() const{};

		// TODO size_type max_size() const{};

		// * Modifiers

		// TODO void clear(){};

		// TODO ft::pair<iterator, bool> insert( const value_type& value) {};
		// TODO iterator insert(iterator hint, const value_type& value) {};
		// TODO template < class InputIt > void insert(InputIt first, InputIt Last){};

		// TODO void erase(iterator pos){};
		// TODO void erase(iterator first, iterator last){};
		// TODO size_type erase(conset Key& key){};

		// TODO void swap(Map& other);

		// * Lookup

		// TODO size_type count(conset Key& key) const {};

		// TODO iterator find(const Key& key){};
		// TODO const_iterator find(const Key& key) const {};

		// TODO ft::pair<iterator, iterator> equal_range(const Key& key){};
		// TODO ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {};

		// TODO iterator lower_bound(const Key& key){};
		// TODO const_iterator lower_bound(const Key& key) const {};

		// TODO iterator upper_bound(const Key& key){};
		// TODO const_iterator upper_bound(const Key& key) const {};

		// * Observers

		// TODO key_compare key_comp() const {};
		// TODO ft::Map::value_compare value_comp() const {};

		// * Operators

		// TODO bool operator==(const Map& lhs, const Map& rhs) {};
		// TODO bool operator!=(const Map& lhs, const Map& rhs) {};
		// TODO bool operator<(const Map& lhs, const Map& rhs) {};
		// TODO bool operator<=(const Map& lhs, const Map& rhs) {};
		// TODO bool operator>(const Map& lhs, const Map& rhs) {};
		// TODO bool operator>=(const Map& lhs, const Map& rhs) {};

		// TODO void swap(Map& lhs, Map& rhs){};
	};
};


#endif
