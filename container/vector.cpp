#include "vector.hpp"

template<class T,class Alloc>
ft::vector<T,Alloc>::vector(){
	_alloc = alloc_type();
	_start = _alloc.allocate(0, NULL);
	_capacity_end = _end = _start;
}

template<class T,class Alloc>
ft::vector<T,Alloc>::vector(const alloc_type& alloc){
	_alloc = alloc;
	_start = _alloc.allocate(0, NULL);
	_capacity_end = _end = _start;
}

template<class T,class Alloc>
ft::vector<T,Alloc>::vector(size_type n, const value_type& val, const alloc_type& alloc){
	_alloc = alloc;
	_start = _alloc.allocate(n, NULL);
	_capacity_end = _start + n;
	for (size_type i = 0;i < n; i++)
		_alloc.construct(_start + i, val);
	_end = _capacity_end;
}

template<class T,class Alloc>
ft::vector<T,Alloc>::vector( const vector& other ){
	_alloc = other._alloc;
	_start = _alloc.allocate(other.capacity());
	_capacity_end = _start + other.size();
	for (ft::pair<vector::const_iterator,int> i(other.begin(),0);
	i.first != other.end();i.first++,i.second++){
		_alloc.construct(_start + i.second, *i.first);}
	_end = _start + other.size();
}

template<class T, class Alloc>
ft::vector<T,Alloc>::~vector() {
	value_type *ptr = _start;
	for (size_type i = 0; i< size(); i++)
	{
		_alloc.destroy(ptr + i);
	}
	_alloc.deallocate(_start, capacity());
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::vector& ft::vector<T,Alloc>::operator=(vector const & op){
	if (op.size() > capacity()){
		for (iterator it = begin(); it != end(); ++it)
			_alloc.destroy(&(*it));
		_alloc.deallocate(_start,capacity());
		_start = _alloc.allocate(op.size(), NULL);
		_end = _start + op.size();
		_capacity_end = _end;}
	for (size_t i = 0; i < op.size();i++){
		_alloc.construct(_start + i, op.at(i));}
	_end = _start + op.size();
	_capacity_end = _end;
	return *this;
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::alloc_type ft::vector<T,Alloc>::get_allocator()const {return _alloc;}

template<class T,class Alloc>
void ft::vector<T,Alloc>::assign(size_type n,const value_type& val){
	clear();
	if (n > capacity())
		reserve(n);
	for (size_type i = 0; i < n;i++){
		_alloc.construct(_start + i, val);}
	_end = _start + n;
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T,Alloc>::at(size_type pos){
	if (pos >= size())
		throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
	return(*(_start + pos));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T,Alloc>::at(size_type pos)const {
	if (pos >= size())
		throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
	return(*(_start + pos));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T,Alloc>::operator[](size_type pos){
	return(*(_start + pos));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T,Alloc>::operator[](size_type pos)const {
	return(*(_start + pos));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T,Alloc>::front(){
	return(*(_start));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T,Alloc>::front()const {
	return(*(_start));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T,Alloc>::back(){
	return(*(_end - 1));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T,Alloc>::back()const {
	return(*(_end - 1));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::value_type * ft::vector<T,Alloc>::data(){
	return(_start);
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::value_type const * ft::vector<T,Alloc>::data() const {
	return(_start);
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T,Alloc>::begin(){
	return(iterator(_start));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_iterator ft::vector<T,Alloc>::begin()const {
	return(const_iterator(_start));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T,Alloc>::end(){
	return(iterator(_end));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_iterator ft::vector<T,Alloc>::end()const {
	return(const_iterator(_end));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::reverse_iterator ft::vector<T,Alloc>::rbegin(){
	return (reverse_iterator(end()));}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_reverse_iterator ft::vector<T,Alloc>::rbegin()const{
	return (const_reverse_iterator(end()));
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::reverse_iterator ft::vector<T,Alloc>::rend(){
	return (reverse_iterator(begin()));}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::const_reverse_iterator ft::vector<T,Alloc>::rend()const{
	return (const_reverse_iterator(begin()));
}

template<class T,class Alloc>
bool ft::vector<T,Alloc>::empty() const{
	if (_start == _end)
		return (true);
	return (false);
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::size_type ft::vector<T,Alloc>::size() const{
	return(_end - _start);
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::size_type ft::vector<T,Alloc>::max_size() const{
	return(_alloc.max_size());
}

template<class T,class Alloc>
void ft::vector<T,Alloc>::reserve(size_type n){
	if (n > capacity()){
		value_type *ptr = _start;
		size_type actual_size = size();
		_start = _alloc.allocate(n, NULL);
		for(size_type i = 0; i < actual_size; ++i){
			_alloc.construct(_start + i, ptr[i]);
			_alloc.destroy(ptr + i);
		}
		_alloc.deallocate(ptr, actual_size);
		_end = _start + actual_size;
		_capacity_end = _start + n;}
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::size_type ft::vector<T,Alloc>::capacity() const{
	return(_capacity_end - _start);
}

template<class T,class Alloc>
void ft::vector<T,Alloc>::clear(){
	while (size())
		pop_back();
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T,Alloc>::insert(iterator pos,const_reference value){
	size_type spos = 0;
	for (iterator i = begin(); i != pos;i++,spos++){}
	if (size() == capacity() && size() > 0)
		reserve(capacity() * 2);
	if (size() == 0)
		reserve(1);
	for (size_t i = size(); i > spos;i--)
		_alloc.construct(_start + i, _start[i - 1]);
	_alloc.construct(_start + spos, value);
	_end++;
	return begin() + spos;
}

template <class T,class Alloc>
void ft::vector<T,Alloc>::insert(iterator pos, size_type count, const_reference value){
	size_type spos = 0;
	if (count == 0){return ;}
	for (iterator i = begin(); i != pos;i++,spos++){}
	if (size() + count > capacity() * 2)
		reserve(capacity() + count);
	else if (size() + count > capacity() && capacity() > count * 2)
		reserve(capacity() + count * 2);
	else if (size() + count > capacity() && capacity() != 0)
		reserve(capacity() * 2);
	else if (capacity() == 0)
		reserve(count);
	for (size_type i = size() + count - 1; i > spos + count - 1; i-- )
		_alloc.construct(_start + i, _start[i - count]);
	for (size_type i = 0; i < count; i++)
	{
		_alloc.construct(_start + i + spos, value);
	}
	_end += count;
}

template <class T,class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T,Alloc>::erase(iterator pos){
	if (pos != end())
	{
		ft::swap(*pos,*(end() - 1));
		pop_back();
		return pos;
	}
	return end();
}

template<class T,class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T,Alloc>::erase(iterator first, iterator last) {
	iterator tmp = first;
	iterator end = this->end();
	size_type deleted = ft::itlen(first, last);
	while (last != end)
	{
		*first = *last;
		++first;
		++last;
	}
	while (deleted-- > 0)
	{
		this->_alloc.destroy(&(*--end));
	}
	return (tmp);
}

template<class T,class Alloc>
void ft::vector<T,Alloc>::push_back(const_reference value){
	if (size() == 0)
		reserve(1);
	else if (size() == capacity())
		reserve(capacity() *2);
	_alloc.construct(_start + size(),value);
	_end++;
}

template<class T,class Alloc>
void ft::vector<T,Alloc>::pop_back(){
	if (size()){
		pointer ptr = --_end;
		_alloc.destroy(ptr);
	}
}

template<class T,class Alloc>
void ft::vector<T,Alloc>::swap(vector& Other){
	pointer ptr[3];
	alloc_type mem = Other._alloc;
	ptr[0] = Other._start;
	ptr[1] = Other._end;
	ptr[2] = Other._capacity_end;
	Other._start = this->_start;
	Other._end = this->_end;
	Other._capacity_end = this->_capacity_end;
	Other._alloc = this->_alloc;
	_start = ptr[0];
	_end = ptr[1];
	_capacity_end = ptr[2];
	_alloc = mem;
}

template<class T,class Alloc>
void ft::vector<T,Alloc>::resize(size_type n, value_type val){
	if (n < capacity() * 2 && n > capacity())
		reserve(capacity() * 2);
	else if (n > capacity())
		reserve(n);
	while (n > size())
		push_back(val);
	while (n < size())
		pop_back();
}
