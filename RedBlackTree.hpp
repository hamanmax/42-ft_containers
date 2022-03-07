#include <iostream>
#include "Utility.hpp"
using namespace std;

enum COLOR { RED, BLACK };
template<class Key,class T, class pair = ft::pair<Key,T> >
class Node {
public:
	typedef pair value_type;
	value_type val;
	COLOR color;
	Node *left, *right, *parent;

	Node(value_type val) : val(val) {
	parent = left = right = NULL;

	// Node is created during insertion
	// Node is red at insertion
	color = RED;
	}
	Node(){
		parent = left = right = NULL;
	}

// returns pointer to uncle
Node *uncle() {
	// If no parent or grandparent, then no uncle
	if (parent == NULL or parent->parent == NULL)
		return NULL;

	if (parent->isOnLeft())
		// uncle on right
		return parent->parent->right;
	else
		// uncle on left
		return parent->parent->left;
	}

// check if node is left child of parent
	bool isOnLeft() { return this == parent->left; }

	// returns pointer to sibling
	Node *sibling() {
	// sibling null if no parent
	if (parent == NULL)
		return NULL;

	if (isOnLeft())
		return parent->right;

	return parent->left;
	}

	// moves node down and moves given node in its place
	void moveDown(Node *nParent) {
	if (parent != NULL) {
		if (isOnLeft()) {
			parent->left = nParent;
		}
		else {
			parent->right = nParent;
		}
	}
	nParent->parent = parent;
	parent = nParent;
	}

	bool hasRedChild() {
	return (left != NULL and left->color == RED) or
			(right != NULL and right->color == RED);
	}
};

// * RBTree

template<class Key, class T>
class RBTree {
	typedef size_t size_type;
	typedef ft::pair<Key,T> value_type;
	typedef Node<Key,T>* node_pointer;
	node_pointer root;
	node_pointer dummy;
	size_type size;

	// left rotates the given node
	void leftRotate(node_pointer x) {
	// new parent will be node's right child
	node_pointer nParent = x->right;

	// update root if current node is root
	if (x == root)
		root = nParent;

	x->moveDown(nParent);

	// connect x with new parent's left element
	x->right = nParent->left;
	// connect new parent's left element with node
	// if it is not null
	if (nParent->left != NULL)
		nParent->left->parent = x;

	// connect new parent with x
	nParent->left = x;
	}
	node_pointer minimum()const {
		node_pointer n = root;
		while(n->left != NULL)
			n = n->left;
		return n;
	}
	node_pointer maximum()const {
		node_pointer n = root;
		while(n->right != NULL)
			n = n->right;
		return n;
	}
	void rightRotate(node_pointer x) {
	// new parent will be node's left child
	node_pointer nParent = x->left;

	// update root if current node is root
	if (x == root)
		root = nParent;

	x->moveDown(nParent);

	// connect x with new parent's right element
	x->left = nParent->right;
	// connect new parent's right element with node
	// if it is not null
	if (nParent->right != NULL)
		nParent->right->parent = x;

	// connect new parent with x
	nParent->right = x;
	}

	void swapColors(node_pointer x1, node_pointer x2) {
		COLOR temp;
	temp = x1->color;
	x1->color = x2->color;
	x2->color = temp;
	}

	void swapValues(node_pointer u, node_pointer v) {
	value_type temp;
	temp = u->val;
	u->val = v->val;
	v->val = temp;
}

	// fix red red at given node
	void fixRedRed(node_pointer x) {
	// if x is root color it black and return
	if (x == root) {
		x->color = BLACK;
		return;
	}

	// initialize parent, grandparent, uncle
	node_pointer parent = x->parent, grandparent = parent->parent,
		uncle = x->uncle();

	if (parent->color != BLACK) {
		if (uncle != NULL && uncle->color == RED) {
		// uncle red, perform recoloring and recurse
		parent->color = BLACK;
		uncle->color = BLACK;
		grandparent->color = RED;
		fixRedRed(grandparent);
		} else {
		// Else perform LR, LL, RL, RR
		if (parent->isOnLeft()) {
			if (x->isOnLeft()) {
			// for left right
			swapColors(parent, grandparent);
			}
			else {
			leftRotate(parent);
			swapColors(x, grandparent);
			}
			// for left left and left right
			rightRotate(grandparent);
		}
		else {
			if (x->isOnLeft()) {
			// for right left
			rightRotate(parent);
			swapColors(x, grandparent);
			}
			else {
			swapColors(parent, grandparent);
			}

			// for right right and right left
			leftRotate(grandparent);
		}
		}
	}
	}

	// find node that do not have a left child
	// in the subtree of the given node
	node_pointer successor(node_pointer x) {
	node_pointer temp = x;

	while (temp->left != NULL)
		temp = temp->left;

	return temp;
	}

	// find node that replaces a deleted node in BST
	node_pointer BSTreplace(node_pointer x) {
	// when node have 2 children
	if (x->left != NULL and x->right != NULL)
		return successor(x->right);

	// when leaf
	if (x->left == NULL and x->right == NULL)
		return NULL;

	// when single child
	if (x->left != NULL)
		return x->left;
	else
		return x->right;
	}

	// deletes the given node
	public:
	void deleteNode(node_pointer v) {
	node_pointer u = BSTreplace(v);

	// True when u and v are both black
	bool uvBlack = ((u == NULL or u->color == BLACK) and (v->color == BLACK));
	node_pointer parent = v->parent;

	if (u == NULL) {
		// u is NULL therefore v is leaf
		if (v == root) {
		// v is root, making root null
		root = NULL;
		} else {
		if (uvBlack) {
			// u and v both black
			// v is leaf, fix double black at v
			fixDoubleBlack(v);
		} else {
			// u or v is red
			if (v->sibling() != NULL)
			// sibling is not null, make it red"
			v->sibling()->color = RED;
		}

		// delete v from the tree
		if (v->isOnLeft()) {
			parent->left = NULL;
		} else {
			parent->right = NULL;
		}
		}
		delete v;
		size--;
		return;
	}

	if (v->left == NULL or v->right == NULL) {
		// v has 1 child
		if (v == root) {
		// v is root, assign the value of u to v, and delete u
		v->val = u->val;
		v->left = v->right = NULL;
		delete u;
		size--;
		} else {
		// Detach v from tree and move u up
		if (v->isOnLeft()) {
			parent->left = u;
		} else {
			parent->right = u;
		}
		delete v;
		size--;
		u->parent = parent;
		if (uvBlack) {
			// u and v both black, fix double black at u
			fixDoubleBlack(u);
		} else {
			// u or v red, color u black
			u->color = BLACK;
		}
		}
		return;
	}

	// v has 2 children, swap values with successor and recurse
	swapValues(u, v);
	deleteNode(u);
	}

	void fixDoubleBlack(node_pointer x) {
	if (x == root)
		// Reached root
		return;

	node_pointer sibling = x->sibling(), parent = x->parent;
	if (sibling == NULL) {
		// No sibiling, double black pushed up
		fixDoubleBlack(parent);
	} else {
		if (sibling->color == RED) {
		// Sibling red
		parent->color = RED;
		sibling->color = BLACK;
		if (sibling->isOnLeft()) {
			// left case
			rightRotate(parent);
		} else {
			// right case
			leftRotate(parent);
		}
		fixDoubleBlack(x);
		} else {
		// Sibling black
		if (sibling->hasRedChild()) {
			// at least 1 red children
			if (sibling->left != NULL and sibling->left->color == RED) {
			if (sibling->isOnLeft()) {
				// left left
				sibling->left->color = sibling->color;
				sibling->color = parent->color;
				rightRotate(parent);
			} else {
				// right left
				sibling->left->color = parent->color;
				rightRotate(sibling);
				leftRotate(parent);
			}
			} else {
			if (sibling->isOnLeft()) {
				// left right
				sibling->right->color = parent->color;
				leftRotate(sibling);
				rightRotate(parent);
			} else {
				// right right
				sibling->right->color = sibling->color;
				sibling->color = parent->color;
				leftRotate(parent);
			}
			}
			parent->color = BLACK;
		} else {
			// 2 black children
			sibling->color = RED;
			if (parent->color == BLACK)
			fixDoubleBlack(parent);
			else
			parent->color = BLACK;
		}
		}
	}
	}
	// prints inorder recursively
	void inorder(node_pointer x) {
	if (x == NULL)
		return;
	inorder(x->left);
	cout << x->val.first << " ";
	inorder(x->right);
	}

public:
	// constructor
	// initialize root
	RBTree():size(0), root(NULL), dummy(new Node<Key,T>()) {}
	~RBTree(){delete dummy;}

	node_pointer getRoot() const { return root; }

	size_type getSize() const { return size; }

	node_pointer getDummy() const {
		if (dummy->parent != NULL)
			dummy->parent = NULL;
		if (root != NULL)
		{
			dummy->left = minimum();
			dummy->right = maximum();
		}
		return dummy;
	}

	node_pointer searchAt(const Key n)const {
		node_pointer temp = root;
	while (temp != NULL) {
		if (n < temp->val.first)
		{
			if (temp->left == NULL)
				return NULL;
			else
				temp = temp->left;
		}
		else if (n == temp->val.first)
		{
			break;
		}
		else
		{
			if (temp->right == NULL)
				return NULL;
			else
				temp = temp->right;
		}
	}
		return temp;
	}
	// searches for given value
	// if found returns the node (used for delete)
	// else returns the last node while traversing (used in insert)
	node_pointer search(Key n) {
	node_pointer temp = root;
	while (temp != NULL) {
		if (n < temp->val.first) {
		if (temp->left == NULL)
			break;
		else
			temp = temp->left;
		} else if (n == temp->val.first) {
		break;
		}
		else {
		if (temp->right == NULL)
			break;
		else
			temp = temp->right;
		}
	}

	return temp;
	}

	node_pointer search(Key n, node_pointer hint) {
	node_pointer temp = hint;
	while (temp != NULL) {
		if (n < temp->val.first) {
		if (temp->left == NULL)
			break;
		else
			temp = temp->left;
		} else if (n == temp->val.first) {
		break;
		}
		else {
		if (temp->right == NULL)
			break;
		else
			temp = temp->right;
		}
	}

	return temp;
	}


	// inserts the given value to tree
	node_pointer insert(value_type n, node_pointer hint) {
	node_pointer newNode = new Node<Key, T>(n);
	if (root == NULL) {
		// when root is null
		// simply insert value at root
		newNode->color = BLACK;
		root = newNode;
	}
	else {
		node_pointer temp = search(n.first,hint);

		if (temp->val.first == n.first) {
		// return if value already exists
		delete newNode;
		return NULL;
		}

		// if value is not found, search returns the node
		// where the value is to be inserted

		// connect new node to correct node
		newNode->parent = temp;

		if (n.first < temp->val.first)
		temp->left = newNode;
		else
		temp->right = newNode;

		// fix red red voilaton if exists
		fixRedRed(newNode);
	}
		size++;
		return newNode;
	}

	// inserts the given value to tree
	node_pointer insert(value_type n) {
	node_pointer newNode = new Node<Key, T>(n);
	if (root == NULL) {
		// when root is null
		// simply insert value at root
		newNode->color = BLACK;
		root = newNode;
	}
	else {
		node_pointer temp = search(n.first);

		if (temp->val.first == n.first) {
		// return if value already exists
		delete newNode;
		return NULL;
		}

		// if value is not found, search returns the node
		// where the value is to be inserted

		// connect new node to correct node
		newNode->parent = temp;

		if (n.first < temp->val.first)
		temp->left = newNode;
		else
		temp->right = newNode;

		// fix red red voilaton if exists
		fixRedRed(newNode);
	}
		size++;
		return newNode;
	}

	// utility function that deletes the node with given value
	void deleteByVal(Key n) {
	if (root == NULL)
		// Tree is empty
		return;

	node_pointer v = search(n), *u;

	if (v->val.first != n) {
		cout << "No node found to delete with value: " << n << endl;
		return;
	}

	deleteNode(v);
	}

	// prints inorder of the tree
	void printInOrder() {
	cout << "Inorder: " << endl;
	if (root == NULL)
		cout << "Tree is empty" << endl;
	else
		inorder(root);
	cout << endl;
	}
// prints level order of the tree
void printLevelOrder() {
	cout << "Level order: " << endl;
	if (root == NULL)
		cout << "Tree is empty" << endl;
	else
		levelOrder(root);
	cout << endl;
	}
};
