#include "vector_iterator.hpp"

template<class T,class P,class R,class C,class D>
vector_iterator<T,P,R,C,D>::vector_iterator():_mptr(0){}

template<class T,class P,class R,class C,class D>
vector_iterator<T,P,R,C,D>::vector_iterator(pointer ptr):_mptr(ptr){}

template<class T,class P,class R,class C,class D>
vector_iterator<T,P,R,C,D>::vector_iterator(const vector_iterator  & copy):_mptr(copy.getptr()){}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator &
vector_iterator<T,P,R,C,D>::operator=(vector_iterator const & op) {
	_mptr = op.getptr();
	return *this;
}

template<class T,class P,class R,class C,class D>
vector_iterator<T,P,R,C,D>::~vector_iterator() {}

template<class T,class P,class R,class C,class D>
typename vector_iterator<T,P,R,C,D>::reference
vector_iterator<T,P,R,C,D>::operator*()const{
	return *this->_mptr;
}

template<class T,class P,class R,class C,class D>
typename vector_iterator<T,P,R,C,D>::pointer
vector_iterator<T,P,R,C,D>::operator->() const{
	return this->_mptr;
}

template<class T,class P,class R,class C,class D>
typename vector_iterator<T,P,R,C,D>::pointer
vector_iterator<T,P,R,C,D>::getptr()const {
	return _mptr;
}

template<class T,class P,class R,class C,class D>
bool
vector_iterator<T,P,R,C,D>::operator==(const vector_iterator& Other) const {
	return (_mptr == Other._mptr);
}

template<class T,class P,class R,class C,class D>
bool
vector_iterator<T,P,R,C,D>::operator!=(const vector_iterator& Other) const {
	return Other._mptr != this->_mptr;
}

template<class T,class P,class R,class C,class D>
bool
vector_iterator<T,P,R,C,D>::operator<(const vector_iterator& Other) const {
	return (Other._mptr > _mptr);
}

template<class T,class P,class R,class C,class D>
bool
vector_iterator<T,P,R,C,D>::operator>(const vector_iterator& Other) const {
	return (Other._mptr < _mptr);
}

template<class T,class P,class R,class C,class D>
bool
vector_iterator<T,P,R,C,D>::operator<=(const vector_iterator& Other) const {
	return (Other._mptr >= _mptr);
}

template<class T,class P,class R,class C,class D>
bool
vector_iterator<T,P,R,C,D>::operator>=(const vector_iterator& Other) const {
	return (Other._mptr <= _mptr);
}

template<class T,class P,class R,class C,class D>
typename vector_iterator<T,P,R,C,D>::reference
vector_iterator<T,P,R,C,D>::operator[](const ssize_t n)const {
return(_mptr[n]);}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator&
vector_iterator<T,P,R,C,D>::operator++() {
++_mptr;
return(*this);
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator
vector_iterator<T,P,R,C,D>::operator++(int) {
vector_iterator Old(*this);
++(this->_mptr);
return(Old);
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator&
vector_iterator<T,P,R,C,D>::operator+=(const ssize_t n) {
	_mptr += n;
	return *this;
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator
vector_iterator<T,P,R,C,D>::operator+(const ssize_t n)const {
vector_iterator it(*this);
	if (n < 0)
		for (ssize_t i = 0; i > n; i--)
			it--;
	else
		for (ssize_t i = 0; i < n; i++)
			it++;
	return (it);
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator&
vector_iterator<T,P,R,C,D>::operator--() {
--_mptr;
return(*this);
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator
vector_iterator<T,P,R,C,D>::operator--(int) {
vector_iterator Old(*this);
--(this->_mptr);
return(Old);
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator&
vector_iterator<T,P,R,C,D>::operator-=(const ssize_t n) {
	_mptr -= n;
	return *this;
}

template<class T,class P,class R,class C,class D>
class vector_iterator<T,P,R,C,D>::vector_iterator
vector_iterator<T,P,R,C,D>::operator-(const ssize_t n) const{
	vector_iterator it(*this);
	if (n > 0)
		for (ssize_t i = 0; i < n; i++)
			it--;
	else
		for (ssize_t i = 0; i > n; i--)
			it++;
	return (it);
}

template<class T,class P,class R,class C,class D>
typename vector_iterator<T,P,R,C,D>::difference_type
vector_iterator<T,P,R,C,D>::operator-(vector_iterator it) const {
	return (this->_mptr - it._mptr);
}




