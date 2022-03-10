#ifndef STACK_HPP
#define STACK_HPP
#include "Vector.hpp"


namespace ft
{
	template<class T, class Container = ft::Vector<T> >
	class Stack
	{
		public: // ALiases
		typedef Container container_type;
		typedef typename container_type::value_type value_type;
		typedef typename container_type::size_type size_type;
		typedef typename container_type::reference reference;
		typedef typename container_type::const_reference const_reference;

		private:
		container_type _Container;

		public:

		// Constructors

		explicit Stack( const Container& cont = Container() ):_Container(cont){}
		Stack(const Stack& other):_Container(other._Container){};

		~Stack(){}

		Stack& operator=( const Stack& other ){_Container = other._Container;return *this;};

		reference top(){return _Container.back();}
		const_reference top()const {return _Container.back();}

		bool empty()const {return _Container.empty();}
		size_type size() const{return _Container.size();}

		void push(const value_type& value){_Container.push_back(value);}

		void pop(){_Container.pop_back();}

		friend bool operator==(const Stack& lhs, const Stack& rhs){return lhs._Container == rhs._Container;}
		friend bool operator!=(const Stack& lhs, const Stack& rhs){return lhs._Container != rhs._Container;}
		friend bool operator<(const Stack& lhs, const Stack& rhs){return lhs._Container < rhs._Container;}
		friend bool operator<=(const Stack& lhs, const Stack& rhs){return lhs._Container <= rhs._Container;}
		friend bool operator>(const Stack& lhs, const Stack& rhs){return lhs._Container > rhs._Container;}
		friend bool operator>=(const Stack& lhs, const Stack& rhs){return lhs._Container >= rhs._Container;}
	};
};


#endif
