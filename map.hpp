
#ifndef MAP_HPP
#define MAP_HPP

#include "utility.hpp"
#include "red_black_tree.hpp"
#include "map_iterator.hpp"
#include "reverse_map_iterator.hpp"
#include "reverse_iterator.hpp"
#include <memory>
#include <functional>
namespace ft
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<Key,T> > >
	class map
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
			typedef map_iterator<value_type, map>		iterator;
			typedef map_iterator<value_type, map, const_pointer, const_reference>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
		RBTree<Key,T>	tree;
		allocator_type	allocator;
		key_compare v;
		public:

		class value_compare
		{
			friend class map;
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

		map():tree(RBTree<Key,T>()),allocator(Allocator()),v(Compare()){}

		explicit map(const Compare& comp, const Allocator & alloc = Allocator()):allocator(alloc),tree(RBTree<Key,T>()),v(comp){}

		template< class InputIterator >
		map(InputIterator first, InputIterator last,const Compare& comp = Compare(),const Allocator & alloc = Allocator() ):allocator(alloc),v(comp){
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}

		map(const map& other){
			allocator = other.allocator;
			v = other.v;
			for (map::iterator it = other.begin(); it != other.end();it++){
				tree.insert(*it);
			}
		}

		~map(){
			while (tree.getSize() != 0){
				tree.deleteNode(tree.getRoot());
			}
		}

		map& operator=( const map& other ){
			allocator = other.allocator;
			v = other.v;
			for (map::iterator it = other.begin(); it != other.end();it++){
				tree.insert(*it);
			}
			return  *this;
		}

		allocator_type get_allocator() const {return allocator;}

		// * Element Acces

		mapped_type& at(Key& key){
			if (tree.searchAt(key) == NULL)
			{
				throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			}
			return tree.searchAt(key)->val.second;
		}
		const mapped_type& at(Key& key) const {
			if (tree.searchAt(key) == NULL)
			{
				throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
			}
			return tree.searchAt(key)->val.second;
		}

		mapped_type& operator[]( Key& key ) {
			node<Key,T> *tmp = tree.searchAt(key);
			if (tmp)
				return tmp->val.second;
			value_type val = ft::pair<key_type,mapped_type>(key,mapped_type());

			return tree.insert(val)->val.second;
		}

		// * Iterators

		iterator begin(){
			if (size() == 0) return end();
			return (iterator(tree.minimum(),tree.getDummy()));
		}
		const_iterator begin() const {
			if (size() == 0) return end();
			return (const_iterator(tree.minimum(),tree.getDummy()));
		}

		iterator end() {
			return (iterator(tree.getDummy(),tree.getDummy()));}

		reverse_iterator rbegin(){
			return (reverse_iterator(iterator(end())));
		}


		const_reverse_iterator rbegin()const {
			return (const_reverse_iterator(const_iterator(end())));
		}


		reverse_iterator rend() {
			return (reverse_iterator(iterator(begin())));}

		const_reverse_iterator rend() const {
			return (const_reverse_iterator(const_iterator(begin())));}

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
			node<Key,T> *n = tree.insert(value);
			if (n == NULL)
				return (ft::pair<iterator, bool>(iterator(tree.search(value.first),tree.getDummy()),false));
			return (ft::pair<iterator, bool>(iterator(n,tree.getDummy()),true));
		}

		iterator insert(iterator hint, const value_type& value) {
			node<Key,T> *n = tree.insert(value,hint.getptr());
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
			tree.deleteNode(pos.getptr());
		}

		void erase(iterator first, iterator last){
			while (first != last)
			{
				tree.deleteNode(first.getptr());
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

		void swap(map& other) {
			map tmp(other);
			other.tree = this->tree;
			other.v = this->v;
			other.allocator = this->allocator;
			this->tree = tmp.tree;
			this->v = tmp.v;
			this->allocator = tmp.allocator;
		}

		// * Lookup

		size_type count(const key_type& key) const {
			node<Key,T> *n = tree.searchAt(key);
			return n ? true : false;
		}

		iterator find(Key& key){
			node<Key,T> *n = tree.searchAt(key);
			if (n == NULL)
				return (end());
			return n;
		}

		const_iterator find(Key& key) const {
			node<Key,T> *n = tree.searchAt(key);
			if (n == NULL)
				return (end());
			return n;
		}

		ft::pair<iterator, iterator> equal_range(Key& key){return ft::pair<iterator, iterator>(lower_bound(key), upper_bound(key));};
		ft::pair<const_iterator, const_iterator> equal_range(Key& key) const {return ft::map<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));};

		iterator lower_bound(Key& key){
			iterator n(tree.search(key),tree.getDummy());
			while (n->first < key && n != end())
				n++;
			return (n);
		}

		const_iterator lower_bound(Key& key) const {
			const_iterator n(tree.search(key),tree.getDummy());
			while (n->first < key && n != end())
				n++;
			return (n);
		}

		iterator upper_bound(Key& key){
			iterator n(tree.search(key),tree.getDummy());
			while (n->first <= key && n != end())
				n++;
			return (n);
		}
		const_iterator upper_bound(Key& key) const {
			const_iterator n(tree.search(key),tree.getDummy());
			while (n->first <= key && n != end())
				n++;
			return (n);
		}

		// * Observers

		key_compare key_comp() const {return v;}
		value_compare value_comp() const {return value_compare(v);}

		// * Operators

		friend bool operator==(const map& lhs, const map& rhs) {
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

		friend bool operator!=(const map& lhs, const map& rhs) {return !(lhs == rhs);}

		friend bool operator<(const map& lhs, const map& rhs) {
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}
		friend bool operator<=(const map& lhs, const map& rhs) {
			return !(rhs < lhs);}

		friend bool operator>(const map& lhs, const map& rhs) {return (rhs < lhs);}

		friend bool operator>=(const map& lhs, const map& rhs) {return !(lhs < rhs);}

		friend void swap(map& lhs, map& rhs){lhs.swap(rhs);}
	};
};


#endif
