#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "Iterator.hpp"

template<
			class T,
			class map,
			class Pointer = T*,
			class Reference = T&,
			class Category = BidirectionalIteratorTag,
			class Distance = ptrdiff_t
		>
class MapIterator: public ft::Iterator<Category,T>
{
public:
	typedef Pointer					pointer;
	typedef Reference				reference;
typedef typename map::mapped_type		mapped_type;
typedef typename map::key_type		key_type;
typedef Node<key_type, mapped_type>*	NodePointer;
private:
	NodePointer _mptr;
	NodePointer _dummy;
public:
	MapIterator(NodePointer ptr,NodePointer dummy):_mptr(ptr),_dummy(dummy){
	};
	MapIterator():_mptr(0),_dummy(0){};
	MapIterator(MapIterator const & copy):_mptr(copy._mptr),_dummy(copy._dummy){};
	template <typename U,typename V>
	MapIterator( const MapIterator<U,V>  & copy) {_mptr = copy.getptr();_dummy = copy.getdummy();}
	MapIterator & operator=(MapIterator const & copy){_mptr = copy._mptr;_dummy = copy._dummy;return *this;};
	~MapIterator(){
	};

	bool operator==(const MapIterator& Other) const {return _mptr == Other._mptr;}
	bool operator!=(const MapIterator& Other) const {return !(_mptr == Other._mptr);}
	reference operator*(){return _mptr->val;}


	NodePointer getptr()const {return _mptr;}
	NodePointer getdummy()const {return _dummy;}

	pointer operator->(){return (&_mptr->val);}

	NodePointer Minimum(){
		NodePointer mini = _mptr;
		while (mini->parent != NULL) mini = mini->parent;
		while (mini->left != NULL) mini = mini->left;
		return mini;
	}
	NodePointer Maximum(){
		NodePointer max = _mptr;
		while (max->parent != NULL) max = max->parent;
		while (max->right != NULL) max = max->right;
		return max;}

	MapIterator& operator++(){
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;

		if (_mptr->val.first == Maximum()->val.first){
			_dummy->parent = _dummy->right;
			_dummy->right = NULL;
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
			while (NewPtr->val.first < _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return *this;
	}

	MapIterator operator++(int){
		MapIterator Ret(*this);
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;

		if (_mptr->val.first == Maximum()->val.first){
			_dummy->parent = _dummy->right;
			_dummy->right = NULL;
			_mptr = _dummy;
			return Ret;
		}
		if (OldPtr->right != NULL)
		{
			NewPtr = OldPtr->right;
			while (NewPtr->left != NULL)
			NewPtr = NewPtr->left;
		}
		if (OldPtr->left == NULL and OldPtr->right == NULL)
		{
			NewPtr = OldPtr->parent;
			while (NewPtr->val.first < _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}

	MapIterator& operator--(){
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;
		if (_mptr == _dummy)
		{
			_mptr = _dummy->parent;
			_dummy->right = _dummy->parent;
			_dummy->parent = NULL;
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

	MapIterator operator--(int){
		MapIterator Ret(*this);
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;
		if (_mptr == _dummy)
		{
			_mptr = _dummy->parent;
			_dummy->right = _dummy->parent;
			_dummy->parent = NULL;
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
			while (NewPtr->val.first > _mptr->val.first)
				NewPtr = NewPtr->parent;
		}
		_mptr = NewPtr;
		return Ret;
	}

};


#endif
