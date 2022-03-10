#ifndef REVERSE_MAP_ITERATOR_HPP
#define REVERSE_MAP_ITERATOR_HPP
#include "iterator.hpp"

template<
			class T,
			class map,
			class Pointer = T*,
			class Reference = T&,
			class Category = BidirectionalIteratorTag,
			class Distance = ptrdiff_t
		>
class reverse_map_iterator: public ft::iterator<Category,T>
{
public:
	typedef Pointer					pointer;
	typedef Reference				reference;
typedef typename map::mapped_type		mapped_type;
typedef typename map::key_type		key_type;
typedef node<key_type, mapped_type>*	node_pointer;
private:
	node_pointer _dummy;
	node_pointer _mptr;
public:
	reverse_map_iterator(node_pointer ptr,node_pointer dummy):_mptr(ptr),_dummy(dummy){};
	reverse_map_iterator():_mptr(0),_dummy(0){};
	reverse_map_iterator(reverse_map_iterator const & copy):_mptr(copy._mptr),_dummy(copy._dummy){};
	template <typename U,typename V>
	reverse_map_iterator( const reverse_map_iterator<U,V>  & copy) {_mptr = copy.getptr();_dummy = copy.getdummy();}

	reverse_map_iterator & operator=(reverse_map_iterator const & copy){_mptr = copy._mptr;_dummy = copy._dummy;return *this;};
	~reverse_map_iterator(){};

	bool operator==(const reverse_map_iterator& Other) const {return _mptr == Other._mptr;}
	bool operator!=(const reverse_map_iterator& Other) const {return !(_mptr == Other._mptr);}


	node_pointer getptr()const {return _mptr;}
	node_pointer getdummy()const {return _dummy;}

	reference operator*(){return _mptr->val;}

	pointer operator->(){return (&_mptr->val);}

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

	reverse_map_iterator& operator++(){
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;

		if (_mptr->val.first == Minimum()->val.first){
			_dummy->parent = _dummy->left;
			_dummy->left = NULL;
			_mptr = _dummy;
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
			while (NewPtr->val.first > _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return *this;
	}

	reverse_map_iterator operator++(int){
		reverse_map_iterator Ret(*this);
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;

		if (_mptr->val.first == Minimum()->val.first){
			_dummy->parent = _dummy->left;
			_dummy->left = NULL;
			_mptr = _dummy;
			return Ret;
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
			while (NewPtr->val.first > _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}


	reverse_map_iterator& operator--(){
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;

		if (_mptr == _dummy) {
			_mptr = _dummy->parent;
			_dummy->left = _dummy->parent;
			_dummy->parent = NULL;
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
			while (NewPtr->val.first < _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return *this;
	}

	reverse_map_iterator operator--(int){
		reverse_map_iterator Ret(*this);
		node_pointer OldPtr = _mptr;
		node_pointer NewPtr = NULL;

		if (_mptr == _dummy) {
			_mptr = _dummy->parent;
			_dummy->left = _dummy->parent;
			_dummy->parent = NULL;
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
			while (NewPtr->val.first < _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}


};


#endif
