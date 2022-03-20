
#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "iterator.hpp"

template<
			class T,
			class map,
			class Compare,
			class Pointer = T*,
			class Reference = T&,
			class Category = BidirectionalIteratorTag,
			class Distance = ptrdiff_t
		>
class map_iterator: public ft::iterator<Category,T>
{
public:
	typedef Pointer					pointer;
	typedef Reference				reference;
	typedef Compare					key_compare;
typedef typename map::mapped_type		mapped_type;
typedef typename map::key_type		key_type;
typedef T							value_type;
typedef node<key_type, mapped_type,Compare>*	node_pointer;
private:
	key_compare _comp;
	node_pointer _mptr;
	node_pointer _dummy;
public:
	map_iterator(node_pointer const & ptr,node_pointer const &  dummy):_comp(Compare()),_mptr(ptr),_dummy(dummy){
	};
	map_iterator():_comp(Compare()),_mptr(0),_dummy(0){};
	map_iterator(map_iterator const & copy):_comp(copy.getcompare()),_mptr(copy.getptr()),_dummy(copy.getdummy()){};
	template <typename U,typename V,typename X>
	map_iterator( const map_iterator<U,V,X>  & copy){_comp = copy.getcompare();_mptr = copy.getptr();_dummy = copy.getdummy();}
	map_iterator & operator=(map_iterator const & copy){_comp = copy.getcompare();_mptr = copy.getptr();_dummy = copy.getdummy();return *this;};
	~map_iterator(){
	};

	bool operator==(const map_iterator& Other) const {return _mptr == Other.getptr();}
	bool operator!=(const map_iterator& Other) const {return !(_mptr == Other.getptr());}
	reference operator*() const{return _mptr->val;}


	node_pointer getptr()const {return _mptr;}
	node_pointer getdummy()const {return _dummy;}
	key_compare getcompare()const {return _comp;}

	pointer operator->() const {return (&_mptr->val);}

	node_pointer Minimum(){
		node_pointer mini = _mptr;
		while (mini->parent != NULL) mini = mini->parent;
		while (mini->left != NULL) mini = mini->left;
		return mini;
	}
	node_pointer Maximum(){
		node_pointer max = _mptr;
		while (max->parent != NULL) max = max->parent;
		while (max->right != NULL) max = max->right;
		return max;}

	map_iterator& operator++(){
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

	map_iterator operator++(int){
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
			//while (NewPtr->val.first < _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}

	map_iterator& operator--(){
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

	map_iterator operator--(int){
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
};
#endif
