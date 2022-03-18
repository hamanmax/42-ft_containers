#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"


namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
		public: // ALiases
		typedef Container container_type;
		typedef typename container_type::value_type value_type;
		typedef typename container_type::size_type size_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::const_reference const_reference;

		protected:
		container_type _Container;

		public:

		// * Constructors

		explicit stack( const Container& cont = Container() ):_Container(cont){}
		stack(const stack& other):_Container(other._Container){};

		~stack(){}

		stack& operator=( const stack& other ){_Container = other._Container;return *this;};

		// * Element Access

		reference top(){return _Container.back();}
		const_reference top()const {return _Container.back();}

		// * Capacity

		bool empty()const {return _Container.empty();}
		size_type size() const{return _Container.size();}

		// * Modifiers

		void push(const value_type& value){_Container.push_back(value);}

		void pop(){_Container.pop_back();}

		// * Operators

		friend bool operator==(const stack& lhs, const stack& rhs){return lhs._Container == rhs._Container;}
		friend bool operator!=(const stack& lhs, const stack& rhs){return lhs._Container != rhs._Container;}
		friend bool operator<(const stack& lhs, const stack& rhs){return lhs._Container < rhs._Container;}
		friend bool operator<=(const stack& lhs, const stack& rhs){return lhs._Container <= rhs._Container;}
		friend bool operator>(const stack& lhs, const stack& rhs){return lhs._Container > rhs._Container;}
		friend bool operator>=(const stack& lhs, const stack& rhs){return lhs._Container >= rhs._Container;}
	};
};


#endif
