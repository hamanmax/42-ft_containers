#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "Iterator.hpp"

namespace ft{

template <class Iterator>
class reverse_iterator{
	public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;
	private :
		Iterator current;
	public:

		reverse_iterator(){}
		explicit reverse_iterator (iterator_type it):current(it){};
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it){*this = rev_it;};
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ){current = other.getbase();};

		iterator_type base() const {return current;}

		reference operator*() const {
			iterator_type tmp = current;
			return *--tmp;
			}

		pointer operator->() const {return &(operator*());}

		reverse_iterator& operator++(){--current; return *this;}

		reverse_iterator operator++(int){
			reverse_iterator tmp = *this;
			--current;
			return tmp;
		}

		reverse_iterator& operator--(){++current;return *this;}

		reverse_iterator operator--(int){
			reverse_iterator tmp = *this;
			++current;
			return tmp;
		}
		reverse_iterator operator+(difference_type n) const{return reverse_iterator(current - n);}
		reverse_iterator operator-(difference_type n) const{return reverse_iterator(current + n);}

		reverse_iterator operator+=(difference_type n) const{current -= n; return *this;}
		reverse_iterator operator-=(difference_type n) const{current += n; return *this;}

		reference operator[](difference_type n) const {return *(*this + n);}

		friend bool operator==(const reverse_iterator& lhs, const reverse_iterator& rhs){return lhs.base() == rhs.base();}
		friend bool operator!=(const reverse_iterator& lhs, const reverse_iterator& rhs){return !(lhs.base() == rhs.base());}
		friend bool operator<(const reverse_iterator& lhs, const reverse_iterator& rhs){return lhs.base() < rhs.base();}
		friend bool operator>(const reverse_iterator& lhs, const reverse_iterator& rhs){return rhs.base() < lhs.base;}
		friend bool operator<=(const reverse_iterator& lhs, const reverse_iterator& rhs){return !(rhs.base() < lhs.base());}
		friend bool operator>=(const reverse_iterator& lhs, const reverse_iterator& rhs){return !(lhs.base() < rhs.base());}
		friend reverse_iterator operator+( typename reverse_iterator::difference_type n,const reverse_iterator& it ){return reverse_iterator(it - n);}
		friend reverse_iterator::difference_type operator-( const reverse_iterator& lhs, const reverse_iterator& rhs ){return rhs.base() -lhs.base();}
};
};
#endif
