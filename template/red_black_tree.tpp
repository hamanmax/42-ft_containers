#include "red_black_tree.hpp"

template<class Key,class T,class comp,class pair>
node<Key,T,comp,pair>::node(){
		parent = left = right = NULL;
}

template<class Key,class T,class comp,class pair>
node<Key,T,comp,pair>::node(value_type val): val(val) {
	parent = left = right = NULL;

	// node is created during insertion
	// node is red at insertion
	color = RED;
}

template<class Key,class T,class comp,class pair>
node<Key,T,comp,pair>::node(node const & copy): val(copy.val) {
	parent = left = right = NULL;

	// node is created during insertion
	// node is red at insertion
	color = RED;
}

template<class Key,class T,class comp,class pair>
class node<Key,T,comp,pair>::node &
node<Key,T,comp,pair>::operator=(node const & assign){
	this = assign;
	return *this;
}

template<class Key,class T,class comp,class pair>
node<Key,T,comp,pair>::~node(){}

template<class Key,class T,class comp,class pair>
class node<Key,T,comp,pair>::node *
node<Key,T,comp,pair>::uncle(){
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

template<class Key,class T,class comp,class pair>
bool
node<Key,T,comp,pair>::isOnLeft() {
	return this == parent->left;
}

template<class Key,class T,class comp,class pair>
class node<Key,T,comp,pair>::node *
node<Key,T,comp,pair>::sibling() {
	// sibling null if no parent
	if (parent == NULL)
		return NULL;

	if (isOnLeft())
		return parent->right;

	return parent->left;
}

template<class Key,class T,class comp,class pair>
void
node<Key,T,comp,pair>::moveDown(node *nParent) {
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

template<class Key,class T,class comp,class pair>
bool
node<Key,T,comp,pair>::hasRedChild() {
	return (left != NULL and left->color == RED) or
			(right != NULL and right->color == RED);
}

template<class Key,class T,class Comp>
RBTree<Key,T,Comp>::RBTree():size(0), root(NULL), dummy(std::allocator<node<Key,T,Comp> >().allocate(1)),comp(Comp()),allocator(std::allocator<node<Key,T,Comp> >()) {}

template<class Key,class T,class Comp>
RBTree<Key,T,Comp>::~RBTree(){
	allocator.deallocate(dummy,1);
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::getRoot() const {
	return root;
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::size_type
RBTree<Key,T,Comp>::getSize() const {
	return size;
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::getDummy() const {
		dummy->parent = root;
	if (root != NULL)
	{
		dummy->left = minimum();
		dummy->right = maximum();
	}
	return dummy;
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::minimum()const {
	node_pointer n = root;
	while(n->left != NULL)
		n = n->left;
	return n;
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::maximum()const {
	node_pointer n = root;
	while(n->right != NULL)
		n = n->right;
	return n;
}

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::swapPtr(node_pointer v,node_pointer u)
	{
		node_pointer vparent = v->parent;
		node_pointer vleft = v->left;
		node_pointer vright = v->right;
		node_pointer uparent = u->parent;
		node_pointer uleft = u->left;
		node_pointer uright = u->right;
		std::cout << v << " | " << u << std::endl;
		print_tree(this->root,0);
		if (vleft)
		vleft->parent = u;
		if (vright)
		vright->parent = u;
		if (vparent && vparent->left == v)
			vparent->left = u;
		else if (vparent)
			vparent->right = u;

		if (uleft)
		uleft->parent = v;
		if (uright)
		uright->parent = v;
		if (uparent && uparent->left == u)
			uparent->left = v;
		else if (uparent)
			uparent->right = v;

		v->parent = uparent;
		v->left = uleft;
		v->right = uright;
		u->parent = vparent;
		u->left = vleft;
		u->right = vright;
		swapColors(u,v);
		if (root->parent != root)
		{
		while (root->parent)
			root = root->parent;
		}
		if (root->parent == root && size == 0) root = NULL;
		std::cout << "//////////////" << size << std::endl;
		print_tree(this->root,0);

	}


template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::deleteNode(node_pointer v) {
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
		size--;
		allocator.destroy(v);
		allocator.deallocate(v,1);
		return;
	}

	if (v->left == NULL or v->right == NULL) {
		// v has 1 child
		if (v == root) {
			// v is root, assign the value of u to v, and delete u
			v->val = u->val;
			v->left = v->right = NULL;
			allocator.destroy(u);
			allocator.deallocate(u,1);
			size--;
		}
		else {
		// Detach v from tree and move u up
		if (v->isOnLeft()) {
			parent->left = u;
		}
		else
		{
			parent->right = u;
		}
		size--;
		allocator.destroy(v);
		allocator.deallocate(v,1);
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

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::deleteByVal(const Key n) {
	if (root == NULL)
		// Tree is empty
		return;

	node_pointer v = search(n);

	if (v->val.first != n) {
		return;
	}

	deleteNode(v);
}


template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::print_tree(node_pointer root, int depth) {
	if (root)
	{

	if (root->right)
		print_tree(root->right, depth + 1);
	std::cout << std::setw(depth * 2) << "" << (root->color == 0?"\033[38;5;160m":"\033[38;5;20m") << root->val.first << "\033[0m" << std::endl;
	if (root->left)
		print_tree(root->left, depth + 1);
	}
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::searchAt(Key n)const {
		node_pointer temp = root;
	while (temp != NULL){
		if (comp(n,temp->val.first))
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

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::search(Key n)const {
	node_pointer temp = root;
	while (temp != NULL) {
		if (comp(n,temp->val.first)) {
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

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::search(Key n, node_pointer hint)const {
	node_pointer temp = hint;
	while (temp != NULL) {
		if (comp(n,temp->val.first)) {
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

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::insert(value_type n, node_pointer hint) {
	node_pointer newNode;
	newNode = allocator.allocate(1);
	allocator.construct(newNode,n);

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
		allocator.destroy(newNode);
		allocator.deallocate(newNode,1);
		return NULL;
		}

		// if value is not found, search returns the node
		// where the value is to be inserted

		// connect new node to correct node
		newNode->parent = temp;

		if (comp(n.first,temp->val.first))
		temp->left = newNode;
		else
		temp->right = newNode;

		// fix red red voilaton if exists
		fixRedRed(newNode);
	}
		size++;
		return newNode;
	}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::insert(value_type n) {
	node_pointer newNode;
	newNode = allocator.allocate(1);
	allocator.construct(newNode,n);
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
		allocator.destroy(newNode);
		allocator.deallocate(newNode,1);
		return NULL;
		}

		// if value is not found, search returns the node
		// where the value is to be inserted

		// connect new node to correct node
		newNode->parent = temp;

		if (comp(n.first,temp->val.first))
		temp->left = newNode;
		else
		temp->right = newNode;

		// fix red red voilaton if exists
		fixRedRed(newNode);
	}
		size++;
		return newNode;
	}



template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::leftRotate(node_pointer x) {
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

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::rightRotate(node_pointer x) {
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

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::swapColors(node_pointer x1, node_pointer x2) {
		COLOR temp;
	temp = x1->color;
	x1->color = x2->color;
	x2->color = temp;
	}

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::swapValues(node_pointer u, node_pointer v) {
	value_type temp = u->val;
	u->val = v->val;
	//u->val = v->val;
	v->val = temp;
}

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::fixRedRed(node_pointer x) {
	// if x is root color it black and return
	if (x == root) {
		x->color = BLACK;
		return;
	}
	// initialize parent, grandparent, uncle
	node_pointer parent = x->parent, grandparent = parent->parent, uncle = x->uncle();
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

template<class Key,class T,class Comp>
void
RBTree<Key,T,Comp>::fixDoubleBlack(node_pointer x) {
	if (x == root)
		// Reached root
		return;
	node_pointer sibling = x->sibling(), parent = x->parent;
	if (sibling == NULL){
		// No sibiling, double black pushed up
		fixDoubleBlack(parent);
	}
	else{
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
		}
		else{
			// Sibling black
			if (sibling->hasRedChild()) {
				// at least 1 red children
				if (sibling->left != NULL and sibling->left->color == RED) {
					if (sibling->isOnLeft()) {
						// left left
						sibling->left->color = sibling->color;
						sibling->color = parent->color;
						rightRotate(parent);
					}
					else {
						// right left
						sibling->left->color = parent->color;
						rightRotate(sibling);
						leftRotate(parent);
					}
				}
				else {
					if (sibling->isOnLeft()) {
						// left right
						sibling->right->color = parent->color;
						leftRotate(sibling);
						rightRotate(parent);
					}
					else {
						// right right
						sibling->right->color = sibling->color;
						sibling->color = parent->color;
						leftRotate(parent);
					}
				}
				parent->color = BLACK;
			}
			else{
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

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::successor(node_pointer x) {
	node_pointer temp = x;
	while (temp->left != NULL)
		temp = temp->left;
	return temp;
}

template<class Key,class T,class Comp>
typename RBTree<Key,T,Comp>::node_pointer
RBTree<Key,T,Comp>::BSTreplace(node_pointer x) {
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
