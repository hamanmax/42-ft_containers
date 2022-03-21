#include "map_iterator.hpp"

template<class T,class m,class C,class P,class R,class Ca>
map_iterator<T,m,C,P,R,Ca>::map_iterator(node_pointer const & ptr,node_pointer const &  dummy):_comp(C()),_mptr(ptr),_dummy(dummy){}

template<class T,class m,class C,class P,class R,class Ca>
map_iterator<T,m,C,P,R,Ca>::map_iterator(map_iterator const & copy):_comp(copy.getcompare()),_mptr(copy.getptr()),_dummy(copy.getdummy()){}

template<class T,class m,class C,class P,class R,class Ca>
map_iterator<T,m,C,P,R,Ca>::map_iterator():_comp(C()),_mptr(0),_dummy(0){}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::map_iterator &
map_iterator<T,m,C,P,R,Ca>::operator=(map_iterator const & copy){
	_comp = copy.getcompare();
	_mptr = copy.getptr();
	_dummy = copy.getdummy();
	return *this;
}

template<class T,class m,class C,class P,class R,class Ca>
map_iterator<T,m,C,P,R,Ca>::~map_iterator(){}

template<class T,class m,class C,class P,class R,class Ca>
bool
map_iterator<T,m,C,P,R,Ca>::operator==(const map_iterator& Other) const {
	return _mptr == Other.getptr();
}

template<class T,class m,class C,class P,class R,class Ca>
bool
map_iterator<T,m,C,P,R,Ca>::operator!=(const map_iterator& Other) const {
	return !(_mptr == Other.getptr());
}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::node_pointer
map_iterator<T,m,C,P,R,Ca>::getptr() const {
	return _mptr;
}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::node_pointer
map_iterator<T,m,C,P,R,Ca>::getdummy() const {
	return _dummy;
}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::key_compare
map_iterator<T,m,C,P,R,Ca>::getcompare() const {
	return _comp;
}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::reference
map_iterator<T,m,C,P,R,Ca>::operator*() const{
	return _mptr->val;
}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::pointer
map_iterator<T,m,C,P,R,Ca>::operator->() const{
	return (&_mptr->val);
}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::node_pointer
map_iterator<T,m,C,P,R,Ca>::Minimum(){
		node_pointer mini = _mptr;
		while (mini->parent != NULL) mini = mini->parent;
		while (mini->left != NULL) mini = mini->left;
		return mini;
	}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::node_pointer
map_iterator<T,m,C,P,R,Ca>::Maximum(){
		node_pointer max = _mptr;
		while (max->parent != NULL) max = max->parent;
		while (max->right != NULL) max = max->right;
		return max;
	}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::map_iterator&
map_iterator<T,m,C,P,R,Ca>::operator++(){
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;
		if (_mptr->val.first == Maximum()->val.first){
			_mptr = _dummy;
			return *this;
		}
		if (OldPtr->right != NULL)
		{
			NewPtr = OldPtr->right;
			while (NewPtr->left != NULL)
			NewPtr = NewPtr->left;
		}
		else
		{
			NewPtr = OldPtr->parent;
			while (_comp(NewPtr->val.first,_mptr->val.first))
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return *this;
	}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::map_iterator
map_iterator<T,m,C,P,R,Ca>::operator++(int){
		map_iterator Ret(*this);
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;

		if (_mptr->val.first == Maximum()->val.first){
			_mptr = _dummy;
			return Ret;
		}
		if (OldPtr->right != NULL)
		{
			NewPtr = OldPtr->right;
			while (NewPtr->left != NULL)
			NewPtr = NewPtr->left;
		}
		else
		{
			NewPtr = OldPtr->parent;
			while (_comp(NewPtr->val.first,_mptr->val.first))
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::map_iterator&
map_iterator<T,m,C,P,R,Ca>::operator--(){
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;
		if (_mptr == Minimum())
		{
			_mptr = _dummy;
			return *this;
		}
		if (_mptr == _dummy)
		{
			_mptr = Maximum();
			return *this;
		}
		if (OldPtr->left != NULL)
		{
			NewPtr = OldPtr->left;
			while (NewPtr->right != NULL)
			NewPtr = NewPtr->right;
		}
		else
		{
			NewPtr = OldPtr->parent;
			while (!_comp(NewPtr->val.first,_mptr->val.first))
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return *this;
	}

template<class T,class m,class C,class P,class R,class Ca>
typename map_iterator<T,m,C,P,R,Ca>::map_iterator
map_iterator<T,m,C,P,R,Ca>::operator--(int){
		map_iterator Ret(*this);
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;
		if (_mptr == Minimum())
		{
			_mptr = _dummy;
			return *this;
		}
		if (_mptr == _dummy)
		{
			_mptr = Maximum();
			return Ret;
		}
		if (OldPtr->left != NULL)
		{
			NewPtr = OldPtr->left;
			while (NewPtr->right != NULL)
			NewPtr = NewPtr->right;
		}
		if (OldPtr->left == NULL)
		{
			NewPtr = OldPtr->parent;
			while (!_comp(NewPtr->val.first,_mptr->val.first))
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}
