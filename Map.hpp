#ifndef MAP_HPP
#define MAP_HPP

#include "Utility.hpp"
#include "RedBlackTree.hpp"
#include "MapIterator.hpp"
#include "ReverseMapIterator.hpp"
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
			typedef MapIterator<BidirectionalIteratorTag,Map>		iterator;
			typedef const MapIterator<BidirectionalIteratorTag,Map>	const_iterator;
			typedef ReverseMapIterator<BidirectionalIteratorTag,Map>	reverse_iterator;
			typedef const ReverseMapIterator<BidirectionalIteratorTag,Map>	const_reverse_iterator;
		private:
		RBTree<Key,T>	tree;
		allocator_type	allocator;
		key_compare v;
		public:

		class value_compare
		{
			friend class Map;
			protected:
				value_compare(key_compare c) : comp(c) {}
				key_compare comp;
			public:
			typedef bool result_type;
			typedef value_type first_value_type;
			typedef value_type second_value_type;

			result_type operator()(const value_type& x,value_type& y) const
			{
				return comp(x.first,y.first);
			}
		};

		Map():allocator(Allocator()),tree(RBTree<Key,T>()),v(Compare()){}

		explicit Map(const Compare& comp, const Allocator & alloc = Allocator()):allocator(alloc),tree(RBTree<Key,T>()),v(comp){}

		template< class InputIterator >
		Map(InputIterator first, InputIterator last,const Compare& comp = Compare(),const Allocator & alloc = Allocator() ):v(comp), allocator(alloc){
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}

		Map(const Map& other){
			allocator = other.allocator;
			v = other.v;
			for (Map::iterator it = other.begin(); it != other.end();it++){
				tree.insert(*it);
			}
		}

		~Map(){
			while (tree.getSize() != 0){
				tree.deleteNode(tree.getRoot());
			}
		}

		Map& operator=( const Map& other ){
			allocator = other.allocator;
			v = other.v;
			for (Map::iterator it = other.begin(); it != other.end();it++){
				tree.insert(*it);
			}
			return  *this;
		}

		allocator_type get_allocator() const {return allocator;}

		// * Element Acces

		mapped_type& at(const Key& key){
			if (tree.searchAt(key) == NULL)
			{
				throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			}
			return tree.searchAt(key)->val.second;
		}
		const mapped_type& at(const Key& key) const {
			if (tree.searchAt(key) == NULL)
			{
				throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			}
			return tree.searchAt(key)->val.second;
		}

		mapped_type& operator[]( const Key& key ) {
			Node<Key,T> *tmp = tree.searchAt(key);
			if (tmp)
				return tmp->val.second;
			value_type val = ft::pair<key_type,mapped_type>(key,mapped_type());

			return tree.insert(val)->val.second;
		}

		// * Iterators

		iterator begin(){
			if (size() == 0) return iterator(tree.getDummy(),tree.getDummy());
			Node<Key,T> *begin = tree.getRoot();
			while (begin->left != NULL)
				begin = begin->left;
			return (iterator(begin,tree.getDummy()));
		}
		const_iterator begin() const {
			if (size() == 0) return end();
			Node<Key,T> *begin = tree.getRoot();
			while (begin->left != NULL)
				begin = begin->left;
			return (iterator(begin,tree.getDummy()));
		}

		iterator end() {
			if (size() == 0) return iterator(tree.getDummy(),tree.getDummy());
			Node<Key,T> *dummy = tree.getDummy();
			dummy->parent = dummy->right;
			dummy->right = NULL;
			return (iterator(dummy,dummy));}
		const_iterator end() const {
			if (size() == 0) return iterator(tree.getDummy(),tree.getDummy());
			Node<Key,T> *dummy = tree.getDummy();
			dummy->parent = dummy->right;
			dummy->right = NULL;
			return (iterator(dummy,dummy));}

		reverse_iterator rbegin(){
			if (size() == 0) return rend();
			Node<Key,T> *rbegin = tree.getRoot();
			while (rbegin->right != NULL)
				rbegin = rbegin->right;
			return (reverse_iterator(rbegin,tree.getDummy()));
		}

		const_reverse_iterator rbegin() const {
			if (size() == 0) return rend();
			Node<Key,T> *rbegin = tree.getRoot();
			while (rbegin->right != NULL)
				rbegin = rbegin->right;
			return (reverse_iterator(rbegin,tree.getDummy()));
		}

		reverse_iterator rend() {
			if (size() == 0) return reverse_iterator();
			Node<Key,T> *dummy = tree.getDummy();
			dummy->parent = dummy->left;
			dummy->left = NULL;
			return (reverse_iterator(dummy,dummy));}

		const_reverse_iterator rend() const {
			Node<Key,T> *dummy = tree.getDummy();
			dummy->parent = dummy->left;
			dummy->left = NULL;
			return (reverse_iterator(dummy,dummy));}

		// * Capacity

		bool empty() const {return (size() > 0)? false : true;}

		size_type size() const{return tree.getSize();}

		size_type max_size() const{return allocator.max_size();}

		// * Modifiers

		void clear(){
			while (tree.getSize() != 0){
				allocator.destroy(&tree.getRoot()->val);
				tree.deleteNode(tree.getRoot());
			}
		}

		ft::pair<iterator, bool> insert( const value_type& value) {
			Node<Key,T> *n = tree.insert(value);
			if (n == NULL)
				return (ft::pair<iterator, bool>(tree.search(value.first),false));
			return (ft::pair<iterator, bool>(n,true));
		}

		iterator insert(iterator hint, const value_type& value) {
			Node<Key,T> *n = tree.insert(value,hint._mptr);
			if (n == NULL)
				return (tree.searchAt(value.first));
			return (iterator(n,tree.getDummy()));
		}

		template < class InputIt >
		void insert(InputIt first, InputIt last){
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}

		void erase(iterator pos){
			tree.deleteNode(pos._mptr);
		}

		void erase(iterator first, iterator last){
			while (first != last)
			{
				tree.deleteNode(first._mptr);
				first++;
			}
		}

		size_type erase(const Key& key){
			size_type i = size();
			tree.deleteByVal(key);
			if (size() != i)
				return 1;
			return 0;
		}

		void swap(Map& other){
			Map *tmp = other;
			other.tree = this->tree;
			other.v = this->v;
			other.allocator = this->allocator;
			this->tree = other.tree;
			this->v = other.v;
			this->allocator = other.allocator;
		}

		// * Lookup

		size_type count(const key_type& key) const {
			Node<Key,T> *n = tree.searchAt(key);
			return n ? true : false;
		}

		iterator find(const Key& key){
			Node<Key,T> *n = tree.searchAt(key);
			if (n == NULL)
				return (end());
			return n;
		}

		const_iterator find(const Key& key) const {
			Node<Key,T> *n = tree.searchAt(key);
			if (n == NULL)
				return (end());
			return n;
		}

		ft::pair<iterator, iterator> equal_range(const Key& key){return ft::Map<iterator, iterator>(lower_bound(), upper_bound());};
		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const {return ft::Map<iterator, iterator>(lower_bound(), upper_bound());};

		iterator lower_bound(const Key& key){
			iterator n(tree.search(key),tree.getDummy());
			while (n->first < key && n != end())
				n++;
			return (n);
		}

		const_iterator lower_bound(const Key& key) const {
			iterator n(tree.search(key),tree.getDummy());
			while (n->first < key && n != end())
				n++;
			return (n);
		}

		iterator upper_bound(const Key& key){
			iterator n(tree.search(key),tree.getDummy());
			while (n->first <= key && n != end())
				n++;
			return (n);
		}
		const_iterator upper_bound(const Key& key) const {
			iterator n(tree.search(key),tree.getDummy());
			while (n->first <= key && n != end())
				n++;
			return (n);
		}

		// * Observers

		key_compare key_comp() const {return v;}
		value_compare value_comp() const {return value_compare(v);}

		// * Operators

		friend bool operator==(const Map& lhs, const Map& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			for (ft::pair<iterator, iterator> it(lhs.begin(), rhs.begin()); it.first != lhs.end(),it.second != rhs.end(); it.first++,it.second++)
			{
				if (*it.first != *it.second)
				{
					return false;
				}
			}
			return true;
		}

		friend bool operator!=(const Map& lhs, const Map& rhs) {return !(lhs == rhs);}

		friend bool operator<(const Map& lhs, const Map& rhs) {
			if (lhs.size() < rhs.size())
				return true;
			for (ft::pair<iterator, iterator> it(lhs.begin(), rhs.begin()); it.first != lhs.end(),it.second != rhs.end(); it.first++,it.second++)
			{
				if (*it.first < *it.second)
				{
					return false;
				}
			}
			return false;
		}
		friend bool operator<=(const Map& lhs, const Map& rhs) {
			if (lhs < rhs) return true;
			if (lhs == rhs) return true;
			return false;
		}

		friend bool operator>(const Map& lhs, const Map& rhs) {return !(lhs <= rhs);}

		friend bool operator>=(const Map& lhs, const Map& rhs) {return !(lhs < rhs);}

		friend void swap(Map& lhs, Map& rhs){lhs.swap(rhs);}
	};
};


#endif
