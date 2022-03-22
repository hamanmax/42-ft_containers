#include "map.hpp"

template<class Key, class T,class Compare,class Allocator>
ft::map<Key, T,Compare,Allocator>::
map():tree(RBTree<Key,T,Compare>()),allocator(Allocator()),v(Compare()){}

template<class Key, class T,class Compare,class Allocator>
ft::map<Key, T,Compare,Allocator>::
map(const Compare& comp, const Allocator & alloc):tree(RBTree<Key,T,Compare>()),allocator(alloc),v(comp){}

template<class Key, class T,class Compare,class Allocator>
ft::map<Key, T,Compare,Allocator>::
map(const map& other){
	allocator = other.allocator;
	v = other.v;
	for (const_iterator it = other.begin(); it != other.end();it++){
tree.insert(*it);
	}
}

template<class Key, class T,class Compare,class Allocator>
ft::map<Key, T,Compare,Allocator>::
~map(){
	while (tree.getSize() != 0){
tree.deleteNode(tree.getRoot());
	}
}

template<class Key, class T,class Compare,class Allocator>
class ft::map<Key, T,Compare,Allocator>::map&
ft::map<Key,T,Compare,Allocator>::operator=(const map& other){
	this->clear();
	allocator = other.allocator;
	v = other.v;
	for (map::const_iterator it = other.begin(); it != other.end();it++){
tree.insert(*it);
	}
	return  *this;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::mapped_type&
ft::map<Key,T,Compare,Allocator>::at(const Key& key){
	if (tree.searchAt(key) == NULL)
	{
throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
	}
	return tree.searchAt(key)->val.second;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::mapped_type const &
ft::map<Key,T,Compare,Allocator>::at(const Key& key) const{
	if (tree.searchAt(key) == NULL)
	{
throw std::out_of_range ("Out Of Bounds Exceptions Thrown");
	}
	return tree.searchAt(key)->val.second;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::mapped_type &
ft::map<Key,T,Compare,Allocator>::operator[](const Key& key){
	node<Key,T,Compare> *tmp = tree.searchAt(key);
	if (tmp)
return tmp->val.second;
	value_type val = ft::make_pair<key_type,mapped_type>(key,mapped_type());
	return tree.insert(val)->val.second;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::iterator
ft::map<Key,T,Compare,Allocator>::begin(){
	if (size() == 0) return end();
	return (iterator(tree.minimum(),tree.getDummy()));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::const_iterator
ft::map<Key,T,Compare,Allocator>::begin()const {
	if (size() == 0) return end();
	return (const_iterator(tree.minimum(),tree.getDummy()));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::iterator
ft::map<Key,T,Compare,Allocator>::end() {
	return (iterator(tree.getDummy(),tree.getDummy()));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::const_iterator
ft::map<Key,T,Compare,Allocator>::end()const {
	return (const_iterator(tree.getDummy(),tree.getDummy()));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::reverse_iterator
ft::map<Key,T,Compare,Allocator>::rbegin(){
	return (reverse_iterator(iterator(end())));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::const_reverse_iterator
ft::map<Key,T,Compare,Allocator>::rbegin()const{
	return (const_reverse_iterator(iterator(end())));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::reverse_iterator
ft::map<Key,T,Compare,Allocator>::rend(){
	return (reverse_iterator(iterator(begin())));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::const_reverse_iterator
ft::map<Key,T,Compare,Allocator>::rend()const{
	return (const_reverse_iterator(iterator(begin())));
}

template<class Key, class T,class Compare,class Allocator>
bool
ft::map<Key,T,Compare,Allocator>::empty()const{
	return (size() > 0)? false : true;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::size_type
ft::map<Key,T,Compare,Allocator>::size()const{
	return tree.getSize();
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key, T,Compare,Allocator>::size_type
ft::map<Key,T,Compare,Allocator>::max_size()const{
	return allocator.max_size();
}

template<class Key, class T,class Compare,class Allocator>
void
ft::map<Key,T,Compare,Allocator>::clear(){
	while (tree.getSize() != 0){
tree.deleteNode(tree.getRoot());
	}
}

template<class Key, class T,class Compare,class Allocator>
ft::pair<typename ft::map<Key,T,Compare,Allocator>::iterator, bool>
ft::map<Key,T,Compare,Allocator>::insert( const value_type& value){
	node<Key,T> *n = tree.insert(value);
	if (n == NULL)
return (ft::make_pair<iterator, bool>(iterator(tree.search(value.first),tree.getDummy()),false));
	return (ft::make_pair<iterator, bool>(iterator(n,tree.getDummy()),true));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::iterator
ft::map<Key,T,Compare,Allocator>::insert(iterator hint, const value_type& value){
	node<Key,T> *n = tree.insert(value,hint.getptr());
	if (n == NULL)
return (iterator(tree.search(value.first),tree.getDummy()));
	return (iterator(n,tree.dummy));
}

template<class Key, class T,class Compare,class Allocator>
void
ft::map<Key,T,Compare,Allocator>::erase(iterator pos){
	tree.deleteNode(pos.getptr());
}

template<class Key, class T,class Compare,class Allocator>
void
ft::map<Key,T,Compare,Allocator>::erase(iterator first, iterator last){
	while (first != last)
	tree.deleteNode((first++).getptr());
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::size_type
ft::map<Key,T,Compare,Allocator>::erase(const Key& key){
	size_type i = size();
	tree.deleteByVal(key);
	if (size() != i)
return 1;
	return 0;
}

template<class Key, class T,class Compare,class Allocator>
void
ft::map<Key,T,Compare,Allocator>::swap(map& other) {
	node<Key,T,Compare> *root = other.tree.root;
	node<Key,T,Compare> *dummy = other.tree.dummy;
	size_t size = other.tree.size;
	key_compare v = other.v;
	allocator_type alloc = other.allocator;
	other.tree.dummy = this->tree.dummy;
	other.tree.root = this->tree.root;
	other.tree.size = this->tree.size;
	other.v = this->v;
	other.allocator = this->allocator;
	this->tree.dummy = dummy;
	this->tree.root = root;
	this->tree.size = size;
	this->v = v;
	this->allocator = alloc;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::size_type
ft::map<Key,T,Compare,Allocator>::count(const key_type& key) const {
	node<Key,T,Compare> *n = tree.searchAt(key);
	return n ? true : false;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::iterator
ft::map<Key,T,Compare,Allocator>::find(const Key& key){
	node<Key,T,Compare> *n = tree.searchAt(key);
	if (n == NULL)
return (end());
	return iterator(n,tree.getDummy());
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::const_iterator
ft::map<Key,T,Compare,Allocator>::find(const Key& key)const{
	node<Key,T,Compare> *n = tree.searchAt(key);
	if (n == NULL)
return (end());
	return iterator(n,tree.getDummy());
}

template<class Key, class T,class Compare,class Allocator>
ft::pair<typename ft::map<Key,T,Compare,Allocator>::iterator, typename ft::map<Key,T,Compare,Allocator>::iterator>
ft::map<Key,T,Compare,Allocator>::equal_range(const Key& key){
	return ft::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key));
}

template<class Key, class T,class Compare,class Allocator>
ft::pair<typename ft::map<Key,T,Compare,Allocator>::const_iterator, typename ft::map<Key,T,Compare,Allocator>::const_iterator>
ft::map<Key,T,Compare,Allocator>::equal_range(const Key& key)const {
	return ft::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key));
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::iterator
ft::map<Key,T,Compare,Allocator>::lower_bound(const Key& key){
	iterator n(tree.search(key),tree.getDummy());
	if (size() != 0)
	{
	while (n != end() && n->first < key)
n++;
	}
	else return end();
	return (n);
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::const_iterator
ft::map<Key,T,Compare,Allocator>::lower_bound(const Key& key)const {
	const_iterator n(tree.search(key),tree.getDummy());
	if (size() != 0)
	{
	while (n != end() && n->first < key)
n++;
	}
	else return end();
	return (n);
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::iterator
ft::map<Key,T,Compare,Allocator>::upper_bound(const Key& key){
	iterator n(tree.search(key),tree.getDummy());
	if (size() != 0)
	{
	while (n != end() && n->first <= key)
n++;
	}
	else return end();
	return (n);
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::const_iterator
ft::map<Key,T,Compare,Allocator>::upper_bound(const Key& key)const {
	const_iterator n(tree.search(key),tree.getDummy());
	if (size() != 0)
	{
	while (n != end() && n->first <= key)
n++;
	}
	else return end();
	return (n);
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::key_compare
ft::map<Key,T,Compare,Allocator>::key_comp() const {
	return v;
}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::value_compare
ft::map<Key,T,Compare,Allocator>::value_comp() const {
	return value_compare(v);
}

template<class Key, class T,class Compare,class Allocator>
ft::map<Key,T,Compare,Allocator>::value_compare::value_compare(key_compare c) : comp(c) {}

template<class Key, class T,class Compare,class Allocator>
typename ft::map<Key,T,Compare,Allocator>::value_compare::result_type
ft::map<Key,T,Compare,Allocator>::value_compare::operator()(const value_type& x,const value_type& y) const{
	return comp(x.first,y.first);
}
