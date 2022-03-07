#ifndef REVERSE_MAP_ITERATOR_HPP
#define REVERSE_MAP_ITERATOR_HPP
#include "Iterator.hpp"

template<	class Category,
			class T,
			class Distance = ptrdiff_t,
			class Pointer = T*,
			class Reference = T&
		>
class ReverseMapIterator: public Iterator<Category,T>
{
public:
typedef typename T::mapped_type		mapped_type;
typedef typename T::key_type			key_type;
typedef typename T::value_type value_type;
typedef typename T::value_type*		pointer;
typedef typename T::value_type&		reference;
typedef Node<key_type, mapped_type>* NodePointer;
private:
	NodePointer _dummy;
public:
	NodePointer _mptr;
	ReverseMapIterator(NodePointer ptr,NodePointer dummy):_mptr(ptr),_dummy(dummy){};
	ReverseMapIterator():_mptr(0),_dummy(0){};
	ReverseMapIterator(ReverseMapIterator const & copy):_mptr(copy._mptr),_dummy(copy._dummy){};
	ReverseMapIterator & operator=(ReverseMapIterator const & copy){_mptr = copy._mptr;_dummy = copy._dummy;return *this;};
	~ReverseMapIterator(){};

	bool operator==(const ReverseMapIterator& Other) const {return _mptr == Other._mptr;}
	bool operator!=(const ReverseMapIterator& Other) const {return !(_mptr == Other._mptr);}

	reference operator*(){return _mptr->val;}

	pointer operator->(){return &(operator*());}

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

	ReverseMapIterator& operator++(){
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;

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

	ReverseMapIterator operator++(int){
		ReverseMapIterator Ret(*this);
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;

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


	ReverseMapIterator& operator--(){
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;

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

	ReverseMapIterator operator--(int){
		ReverseMapIterator Ret(*this);
		NodePointer OldPtr = _mptr;
		NodePointer NewPtr = NULL;

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
