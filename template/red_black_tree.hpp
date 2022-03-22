#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iomanip>
#include <iostream>
#include "utility.hpp"


#include <stdlib.h>

enum COLOR { RED, BLACK };
template<class Key,class T,class comp = std::less<Key> , class pair = ft::pair<Key,T> >
class node {
public:
	typedef pair	value_type;

	value_type	val;
	COLOR		color;
	node		*left, *right, *parent;

	node(value_type val);
	node();
	node(node const & copy);
	~node();
	node & operator=(node const & assign);

// returns pointer to uncle
	node *uncle();

// check if node is left child of parent
	bool isOnLeft();

	// returns pointer to sibling
	node *sibling();

	// moves node down and moves given node in its place
	void moveDown(node *nParent);

	bool hasRedChild();
};

// * RBTree

template<class Key, class T,class Comp = std::less<Key> >
class RBTree {
	public:
	typedef size_t						size_type;
	typedef Comp						key_compare;
	typedef ft::pair<Key,T>				value_type;
	typedef node<Key,T,Comp>*			node_pointer;

	size_type							size;
	node_pointer						root;
	node_pointer						dummy;
	key_compare							comp;
	std::allocator<node<Key,T,Comp> >	allocator;

	// constructor
	// initialize root
	RBTree();
	~RBTree();

	node_pointer getRoot() const;
	size_type getSize() const;
	node_pointer getDummy() const;

	node_pointer minimum()const;
	node_pointer maximum()const;

	void swapPtr(node_pointer v,node_pointer u);

	// deletes the given node
	void deleteNode(node_pointer v);
	// utility function that deletes the node with given value
	void deleteByVal(const Key n);

	void print_tree(node_pointer root, int depth);

	// searches for given value
	// if found returns the node (used for delete)
	// else returns NULL
	node_pointer searchAt(Key n)const;
	// searches for given value
	// if found returns the node (used for delete)
	// else returns the last node while traversing (used in insert)
	node_pointer search(Key n)const;
	node_pointer search(Key n, node_pointer hint)const;


	// inserts the given value to tree
	node_pointer insert(value_type n, node_pointer hint);
	// inserts the given value to tree
	node_pointer insert(value_type n);
	private:
	// rotates the given node
	void leftRotate(node_pointer x);
	void rightRotate(node_pointer x);

	void swapColors(node_pointer x1, node_pointer x2);
	void swapValues(node_pointer u, node_pointer v);

	// fix double color at given node
	void fixRedRed(node_pointer x);
	void fixDoubleBlack(node_pointer x);
	// find node that do not have a left child
	// in the subtree of the given node
	node_pointer successor(node_pointer x);
	// find node that replaces a deleted node in BST
	node_pointer BSTreplace(node_pointer x);

};

#include "red_black_tree.tpp"

#endif
