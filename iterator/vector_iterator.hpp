#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include "iterator.hpp"

template<
			class T,
			class Pointer = T*,
			class Reference = T&,
			class Category = RandomAccessIteratorTag,
			class Distance = ptrdiff_t
		>
class vector_iterator : public ft::iterator<Category, T>
{
	public:
	typedef Category	 iterator_category;
	typedef Pointer pointer;
	typedef Reference		reference;
	private:
		pointer _mptr;
	protected:
	public:
		vector_iterator(pointer ptr):_mptr(ptr){};
		vector_iterator():_mptr(0){};
		vector_iterator & operator=(vector_iterator const & op) {_mptr = op.getptr(); return *this;};
		template<typename U>
		vector_iterator( const vector_iterator<U>  & copy) {_mptr = copy.getptr();}

		~vector_iterator(){};
		reference operator*(){
			return *this->_mptr;}

		pointer operator->(){
			return this->_mptr;}

		const pointer& getptr()const {return _mptr;}

		bool operator==(const vector_iterator& Other) const {return (_mptr == Other._mptr);}

		bool operator!=(const vector_iterator& Other) const {return Other._mptr != this->_mptr;}

		bool operator<(const vector_iterator& Other) const {return Other._mptr > _mptr;}

		bool operator>(const vector_iterator& Other) const {return Other._mptr < _mptr;}

		bool operator<=(const vector_iterator& Other) const {return Other._mptr >= _mptr;}

		bool operator>=(const vector_iterator& Other) const {return Other._mptr <= _mptr;}

		reference operator[](const ssize_t n)const {
			return(_mptr[n]);}

		vector_iterator&	operator++() {
			++_mptr;
			return(*this);}

		vector_iterator	operator++(int) {
			vector_iterator Old(*this);
			++(this->_mptr);
			return(Old);}

		vector_iterator &operator+=(const ssize_t n){
			_mptr += n;
			return *this;}

		vector_iterator operator+(const ssize_t n)const {
			vector_iterator it(*this);
			if (n < 0)
				for (ssize_t i = 0; i > n; i--)
					it--;
			else
				for (ssize_t i = 0; i < n; i++)
					it++;
			return (it);}

		vector_iterator&	operator--(){
			--_mptr;
			return(*this);}

		vector_iterator	operator--(int){
			vector_iterator Old(*this);
			this->_mptr--;
			return(Old);}

		vector_iterator &operator-=(const ssize_t n){
			_mptr -= n;
			return *this;}

		vector_iterator operator-(ssize_t n)const {
			vector_iterator it(*this);
			if (n > 0)
				for (ssize_t i = 0; i < n; i++)
					it--;
			else
				for (ssize_t i = 0; i > n; i--)
					it++;
			return (it);}

		Distance	operator-(vector_iterator it)const {
			return (this->_mptr - it._mptr);
		}

		friend vector_iterator operator+(int nb,const vector_iterator& it) {
			vector_iterator New(it);
			return (New += nb);
		}

		friend vector_iterator operator-(int nb,const vector_iterator& it) {
			vector_iterator New(it);
			return (New -= nb);
		}
};

//   template<typename _IteratorL, typename _IteratorR, typename _Container>
//     inline bool
//     operator==(const vector_iterator<_IteratorL, _Container>& __lhs,
//                const vector_iterator<_IteratorR, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs == __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline bool
//     operator==(const vector_iterator<_Iterator, _Container>& __lhs,
//                const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs == __rhs; }
//   template<typename _IteratorL, typename _IteratorR, typename _Container>
//     inline bool
//     operator!=(const vector_iterator<_IteratorL, _Container>& __lhs,
//                const vector_iterator<_IteratorR, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs != __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline bool
//     operator!=(const vector_iterator<_Iterator, _Container>& __lhs,
//                const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs != __rhs; }
//   // Random access iterator requirements
//   template<typename _IteratorL, typename _IteratorR, typename _Container>
//     inline bool
//     operator<(const vector_iterator<_IteratorL, _Container>& __lhs,
//               const vector_iterator<_IteratorR, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs < __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline bool
//     operator<(const vector_iterator<_Iterator, _Container>& __lhs,
//               const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs < __rhs; }
//   template<typename _IteratorL, typename _IteratorR, typename _Container>
//     inline bool
//     operator>(const vector_iterator<_IteratorL, _Container>& __lhs,
//               const vector_iterator<_IteratorR, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs > __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline bool
//     operator>(const vector_iterator<_Iterator, _Container>& __lhs,
//               const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs > __rhs; }
//   template<typename _IteratorL, typename _IteratorR, typename _Container>
//     inline bool
//     operator<=(const vector_iterator<_IteratorL, _Container>& __lhs,
//                const vector_iterator<_IteratorR, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs <= __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline bool
//     operator<=(const vector_iterator<_Iterator, _Container>& __lhs,
//                const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs <= __rhs; }
//   template<typename _IteratorL, typename _IteratorR, typename _Container>
//     inline bool
//     operator>=(const vector_iterator<_IteratorL, _Container>& __lhs,
//                const vector_iterator<_IteratorR, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs >= __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline bool
//     operator>=(const vector_iterator<_Iterator, _Container>& __lhs,
//                const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs >= __rhs; }
// 	  template<typename _IteratorL, typename _IteratorR, typename _Container>
// 	  inline typename vector_iterator<_IteratorL, _Container>::difference_type
//     operator-(const vector_iterator<_IteratorL, _Container>& __lhs,
//               const vector_iterator<_IteratorR, _Container>& __rhs) { return __lhs - __rhs; }
//  template<typename _Iterator, typename _Container>
//     inline typename vector_iterator<_Iterator, _Container>::difference_type
//     operator-(const vector_iterator<_Iterator, _Container>& __lhs,
//               const vector_iterator<_Iterator, _Container>& __rhs)
//     _GLIBCXX_NOEXCEPT
//     { return __lhs - __rhs; }
//   template<typename _Iterator, typename _Container>
//     inline vector_iterator<_Iterator, _Container>
//     operator+(typename vector_iterator<_Iterator, _Container>::difference_type
//               __n, const vector_iterator<_Iterator, _Container>& __i)
//     _GLIBCXX_NOEXCEPT
//     { return vector_iterator<_Iterator, _Container>(__i.base() + __n); }


#endif
