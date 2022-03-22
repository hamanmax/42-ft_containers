#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator.hpp"

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

		reverse_iterator();
		explicit reverse_iterator (iterator_type it);
		template <class Iter>
		reverse_iterator (const reverse_iterator<Iter>& rev_it):current(rev_it.base()){}

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ){current = other.current;}

		iterator_type base() const;

		reference operator*() const;
		pointer operator->() const;

		reverse_iterator& operator++();
		reverse_iterator operator++(int);

		reverse_iterator& operator--();
		reverse_iterator operator--(int);

		reverse_iterator operator+(difference_type n) const;
		reverse_iterator operator-(difference_type n) const;

		reverse_iterator& operator+=(difference_type n);
		reverse_iterator& operator-=(difference_type n);

		reference operator[](difference_type n) const;
		friend reverse_iterator operator+( typename reverse_iterator::difference_type n,const reverse_iterator& it ){return reverse_iterator(it.base() - n);}
		friend inline reverse_iterator::difference_type operator-( const reverse_iterator& lhs, const reverse_iterator& rhs ) {return rhs.base() -lhs.base();}
};

	#include "reverse_iterator.tpp"

	template<typename Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{return lhs.base() == rhs.base();}

	template<typename Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, reverse_iterator<Iterator>& rhs)
			{return rhs.base() < lhs.base();}

	template<typename Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{return !(lhs == rhs);}

	template<typename Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
		{return rhs < lhs;}

	template<typename Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
		{return !(rhs < lhs);}

	template<typename Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs)
		{return !(lhs < rhs);}

	template<typename IteratorL, typename IteratorR>
	bool operator==(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
		{return lhs.base() == rhs.base();}

	template<typename IteratorL, typename IteratorR>
	bool operator<(const reverse_iterator<IteratorL>& lhs,const reverse_iterator<IteratorR>& rhs)
		{return rhs.base() < lhs.base();}

	template<typename IteratorL, typename IteratorR>
	bool operator!=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
		{return !(lhs == rhs);}

	template<typename IteratorL, typename IteratorR>
	bool operator>(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
		{return rhs < lhs;}

	template<typename IteratorL, typename IteratorR>
	bool operator<=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
		{return !(rhs < lhs);}

	template<typename IteratorL, typename IteratorR>
	bool operator>=(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
		{return !(lhs < rhs);}

	template<typename Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{return rhs.base() - lhs.base();}

	template<typename IteratorL, typename Iterator>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
		{return rhs.base() - lhs.base();}
};
#endif
