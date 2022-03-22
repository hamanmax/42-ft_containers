
#ifndef MAP_HPP
#define MAP_HPP

#include "../template/utility.hpp"
#include "../template/red_black_tree.hpp"
#include "../iterator/map_iterator.hpp"
#include "../iterator/reverse_iterator.hpp"
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
			typedef map_iterator<value_type, map, key_compare>		iterator;
			typedef map_iterator<value_type, map, key_compare, const_pointer, const_reference>	const_iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
		RBTree<Key,T,Compare>	tree;
		allocator_type			allocator;
		key_compare				v;
		public:

		class value_compare
		{
			friend class map;
			protected:
				key_compare comp;
				value_compare(key_compare c);
			public:
			typedef bool result_type;
			typedef value_type first_value_type;
			typedef value_type second_value_type;

			result_type operator()(const value_type& x,const value_type& y) const;
		};

		map();
		explicit map(const Compare& comp, const Allocator & alloc = Allocator());
		template< class InputIterator >
		map(InputIterator first, InputIterator last,const Compare& comp = Compare(),const Allocator & alloc = Allocator() ):tree(RBTree<Key,T,Compare>()),allocator(alloc),v(comp){
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}

		map(const map& other);

		~map();

		map& operator=( const map& other );

		allocator_type get_allocator() const {return allocator;}

		// * Element Acces

		T& at(const Key& key);
		const T& at(const Key& key) const;

		mapped_type& operator[](const Key& key );

		// * Iterators

		iterator begin();
		const_iterator begin() const;

		iterator end();
		const_iterator end() const;

		reverse_iterator rbegin();
		const_reverse_iterator rbegin()const;

		reverse_iterator rend();
		const_reverse_iterator rend() const;

		// * Capacity

		bool empty() const;

		size_type size() const;

		size_type max_size() const;

		// * Modifiers

		void clear();

		ft::pair<iterator, bool> insert( const value_type& value);
		iterator insert(iterator hint, const value_type& value);
		template < class InputIt >
		void insert(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value >::type* = 0){
			while (first != last)
			{
				tree.insert(*first);
				first++;
			}
		}

		void erase(iterator pos);
		void erase(iterator first, iterator last);
		size_type erase(const Key& key);

		void swap(map& other);

		// * Lookup

		size_type count(const key_type& key) const;

		iterator find(const Key& key);
		const_iterator find(const Key& key) const;

		ft::pair<iterator, iterator> equal_range(const Key& key);
		ft::pair<const_iterator, const_iterator> equal_range(const Key& key) const;

		iterator lower_bound(const Key& key);
		const_iterator lower_bound(const Key& key) const;

		iterator upper_bound(const Key& key);
		const_iterator upper_bound(const Key& key) const;

		// * Observers

		key_compare key_comp() const;
		value_compare value_comp() const;

		// * Operators

		friend bool operator==(const map& lhs, const map& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			for (ft::pair<const_iterator, const_iterator> it(lhs.begin(), rhs.begin()); it.first != lhs.end() or it.second != rhs.end(); it.first++,it.second++)
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

#include "map.tpp"

#endif
