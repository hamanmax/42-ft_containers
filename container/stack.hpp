#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public: // ALiases
		typedef Container									container_type;
		typedef typename container_type::value_type			value_type;
		typedef typename container_type::size_type			size_type;
		typedef typename container_type::reference			reference;
		typedef typename container_type::const_reference	const_reference;

		protected:
		container_type c;

		public:

		// * Constructors

		explicit stack( const Container& cont = Container() );
		stack(const stack& other);

		~stack();

		stack& operator=( const stack& other );

		// * Element Access

		reference top();
		const_reference top()const;

		// * Capacity

		bool empty()const;
		size_type size() const;

		// * Modifiers

		void push(const value_type& value);

		void pop();

		// * Operators

		friend bool operator==(const stack& lhs, const stack& rhs){return lhs.c == rhs.c;}
		friend bool operator!=(const stack& lhs, const stack& rhs){return lhs.c != rhs.c;}
		friend bool operator<(const stack& lhs, const stack& rhs){return lhs.c < rhs.c;}
		friend bool operator<=(const stack& lhs, const stack& rhs){return lhs.c <= rhs.c;}
		friend bool operator>(const stack& lhs, const stack& rhs){return lhs.c > rhs.c;}
		friend bool operator>=(const stack& lhs, const stack& rhs){return lhs.c >= rhs.c;}
	};
};
#include "stack.tpp"

#endif
