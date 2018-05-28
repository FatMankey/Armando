#pragma once

#include "xmlnode.h"
#include <vector>

// Duplicate Trees and Nodes are allowed
template <typename T1, typename T2>
class XMLTree : public XMLNode<T1,T2> {
	private:
		static int						nodeId;
		int								level;
		T1								key;
		T2								value;
		int								errors;
		int								warnings;
		std::vector<XMLTree<T1, T2>*>	nextLevel;

		// Recursive Helper Functions
		void							getNodesInPreOrderRecursive(XMLNode<T1, T2>* nextNode, std::vector<std::pair<T1, T2>> &traverse);
		void							getNodesInOrderRecursive(XMLNode<T1,T2>* nextNode, std::vector<std::pair<T1, T2>> &traverse);
		void							addNodeRecursive(XMLNode<T1, T2>* nextNode, T1 key, T2 value);

	public:
		XMLTree();
		XMLTree(int level, T1 key, T2 value = {});

		// Copy constructor is called when a new object is created from an existing object, as a copy of the existing object:
		// 1.	XMLTree<T1,T2> tree1;
		//		XMLTree<T1,T2> tree2 = tree1;
		// 2.	Class variable XMLTree<T1,T2> tree;
		//		In a class function, return tree
		XMLTree(const XMLTree<T1,T2> &other);

		// Copy assignment operator is called when an already initialized object is assigned a new value from another existing object:
		XMLTree<T1,T2>& operator = (const XMLTree<T1, T2> &other);

		// Move constructor
		XMLTree(const XMLTree<T1, T2> &&other);

		// Move assignment operator
		XMLTree<T1, T2>& operator = (const XMLTree<T1, T2> &&other);

		// A parent class that has a virtual function is called "a polymorphic class".
		// A PARENT CLASS MUST HAVE AT LEAST ONE VIRTUAL FUNCTION:
		//
		// 1. To avoid "Object Slicing", the loss of child class variable data when storing
		//	  child objects in a variable of type parent class:
		//	  a. DO NOT USE AUTOMATIC OBJECTS!
		//	  b. MAKE SURE AT LEAST ONE PARENT CLASS FUNCTION IS VIRTUAL!
		//
		// Problem example: ALL FlipCard class variables will be lost! Only the parent Card variables will be copied.
		// vector<Card*> cardDeck;
		// Card* card = new FlipCard();
		// cardDeck.push_back(card)
		//
		// 2  To avoid memory leaks:
		//    DESTRUCTOR SHOULD BE DECLARED VIRTUAL IN PARENT CLASS AND CHILD CLASSES
		//
		//	  If your child class destructor is virtual then objects will be deleted
		//	  in order (first child object destructor is called then parent object destructor).
		//	  If your child class destructor is NOT virtual then only parent class objects
		//	  will get deleted. There will be memory leak for child object.
		// 3. In order to use dynamic_cast<>
		virtual ~XMLTree();

		// Getters
		static int						getNodeId();
		int								getLevel() const;
		T1								getTreeKey() const;
		T2								getTreeValue() const;
		bool							isValid() const;
		bool							isEmpty() const;
		bool							hasErrors() const;
		int								getErrors() const;
		int								getWarnings() const;
		
		// Traversals:
		// Binary Tree Example:
		//				F (ROOT)
		//		B				G
		// A		D				I
		//		C		E		H

		// Tree Traversals
		// Please see https://en.wikipedia.org/wiki/Tree_traversal
		//
		// Depth First Traversals:
		//
		// Pre-Order Traversal: LEFT-SIDE (PREV) TOP-DOWN, THEN RIGHT-SIDE TOP-DOWN (F-B-A-D-C-E-G-I-H)
		// Used to create a copy of the tree. Also used to get prefix expression on of an expression tree.
		// Please see http://en.wikipedia.org/wiki/Polish_notation
		// to know why prefix expressions are useful.
		std::vector<XMLTree<T1, T2>*>	getTreesInPreOrder();
		std::vector<std::pair<T1, T2>>	getNodesInPreOrder();

		// In-Order Traversal: LEFT-SIDE (PREV) BOTTOM-UP, THEN RIGHT-SIDE BOTTOM-UP (A-B-C-D-E-F-G-H-I)
		// In case of binary search trees (BST), Inorder traversal gives nodes in increasing order (e.g., alphabetical order)
		std::vector<std::pair<T1, T2>>	getNodesInOrder();
		
		// Post-Order Traversal: LEFT-SIDE (PREV) BOTTOM-UP, THEN RIGHT-SIDE BOTTOM-UP (A-C-D-E-B-H-I-G-F)
		// Used to delete the tree. Also useful to get the postfix expression of an expression tree.
		// Please see http://en.wikipedia.org/wiki/Reverse_Polish_notation
		// for the usage of postfix expression.

		// Breadth First Traversals:
		//
		// Level-Order Traversal: LEFT-SIDE (PREV), THEN RIGHT-SIDE, REPEAT (B-G-A-D-I-C-E-H)
		// Visit every node on a level before going to a lower level.

		// Setters
		void							setLevel(int level);
		void							setTreeKey(T1 key);
		void							setTreeValue(T2 value);
		void							setErrors(int errors);
		void							setWarnings(int warnings);
		bool							addTree(XMLTree<T1, T2>* tree);
		void							addNode(T1 key, T2 value);
};

// Prevent error LNK2001 : unresolved external symbol static int
template <typename T1, typename T2>
int XMLTree<T1, T2>::nodeId = 0;

template <typename T1, typename T2>
XMLTree<T1, T2>::XMLTree() : XMLNode<T1, T2>() {
	level		= 0;
	errors		= 0;
	warnings	= 0;
}

template <typename T1, typename T2>
XMLTree<T1, T2>::XMLTree(int level, T1 key, T2 value) : XMLNode<T1, T2>() {
	this->level		= level;
	this->key		= key;
	this->value		= value;
	this->errors	= 0;
	this->warnings	= 0;
}

template <typename T1, typename T2>
XMLTree<T1, T2>::XMLTree(const XMLTree<T1, T2> &other) {
	level		= other.level;
	key			= other.key;
	value		= other.value;
	errors		= other.errors;
	warnings	= other.warnings;

	// Four ways of copying a vector:
	// 1. Brute force baby! Copy a for-each loop
	// 2. Use std::copy() to do the brute force copy for you!
	// 3. Use the vector copy assignment operator: vector<> v1 = v2 or v1 = v2
	// 4. Use the vector copy constructor: vector<> v1(v2)
	nextLevel	= other.nextLevel;
}

template <typename T1, typename T2>
XMLTree<T1, T2>& XMLTree<T1, T2>::operator = (const XMLTree<T1, T2> &other) {
	level		= other.level;
	key			= other.key;
	value		= other.value;
	errors		= other.errors;
	warnings	= other.warnings;
	nextLevel	= other.nextLevel;

	return *this;
}

template <typename T1, typename T2>
XMLTree<T1, T2>::XMLTree(const XMLTree<T1, T2> &&other) {
	level		= other.level;
	key			= other.key;
	value		= other.value;
	errors		= other.errors;
	warnings	= other.warnings;
	nextLevel	= other.nextLevel;

	// Reset the old object
	other.level		= 0;
	other.key		= {};
	other.value		= {};
	other.errors	= 0;
	other.warnings	= 0;
	
	for (XMLTree<T1, T2>* tree : nextLevel) {
		delete tree;
	}

	nextLevel.clear();
}

template <typename T1, typename T2>
XMLTree<T1, T2>& XMLTree<T1, T2>::operator = (const XMLTree<T1, T2> &&other) {
	level		= move(other.level);
	key			= move(other.key);
	value		= move(other.value);
	errors		= move(other.errors);
	warnings	= move(other.warnings);
	nextLevel	= move(other.nextLevel);

	return *this;
}

template <typename T1, typename T2>
XMLTree<T1, T2>::~XMLTree() {
}

/*
* Recursive Helper Functions
*/

template <typename T1, typename T2>
void XMLTree<T1, T2>::getNodesInPreOrderRecursive(XMLNode<T1, T2>* nextNode, std::vector<std::pair<T1, T2>> &traverse) {

	if (nextNode != nullptr) {
		traverse.push_back(std::make_pair(nextNode->getNodeKey(), nextNode->getNodeValue()));

		// Recursively traverse the left (previous) subtree
		getNodesInPreOrderRecursive(nextNode->getPrevNode(), traverse);

		// Recursively traverse the right (next) subtree
		getNodesInPreOrderRecursive(nextNode->getNextNode(), traverse);
	}
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::getNodesInOrderRecursive(XMLNode<T1, T2>* nextNode, std::vector<std::pair<T1, T2>> &traverse) {

	if (nextNode != nullptr) {
		// If the Node is a subtree (not a parent Node object) pass it on
		if (!dynamic_cast<XMLNode<T1, T2>*>(nextNode)) {
			getNodesInOrderRecursive(nextNode, traverse);
		}
		else {
			// Recursively traverse the left (previous) subtree
			getNodesInOrderRecursive(nextNode->getPrevNode(), traverse);

			traverse.push_back(std::make_pair(nextNode->getNodeKey(), nextNode->getNodeValue()));

			// Recursively traverse the right (next) subtree
			getNodesInOrderRecursive(nextNode->getNextNode(), traverse);
		}
	}
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::addNodeRecursive(XMLNode<T1, T2>* nextNode, T1 key, T2 value) {
	// Get the next Node key
	T1 nextNodeKey = nextNode->getNodeKey();
	T2 nextNodeValue = nextNode->getNodeValue();

	// Recursively check if key and value are less or equal to the next Node key and value, or come are it
	if (key <= nextNodeKey && value <= nextNodeValue) {
		XMLNode<T1, T2>* newNode = nextNode->getPrevNode();

		if (newNode == nullptr) {
			// Add the new Node to the next Node
			XMLNode<T1, T2>* node = new XMLNode<T1, T2>(key, value);
			nextNode->setPrevNode(node);
		}
		else {
			addNodeRecursive(newNode, key, value);
		}
	}
	// Key and value must come after the next Node key and value. Recursively check.
	else {
		XMLNode<T1, T2>* newNode = nextNode->getNextNode();

		if (newNode == nullptr) {
			// Add the new Node to the next Node
			XMLNode<T1, T2>* node = new XMLNode<T1, T2>(key, value);
			nextNode->setNextNode(node);
		}
		else {
			addNodeRecursive(newNode, key, value);
		}
	}
}

/*
* Getters
*/

template <typename T1, typename T2>
int XMLTree<T1, T2>::getNodeId() {
	// Increment, then return the new Node id
	return ++nodeId;
}

template <typename T1, typename T2>
int	XMLTree<T1, T2>::getLevel() const {
	return level;
}

template <typename T1, typename T2>
T1 XMLTree<T1, T2>::getTreeKey() const {
	return key;
}

template <typename T1, typename T2>
T2 XMLTree<T1, T2>::getTreeValue() const {
	return value;
}

template <typename T1, typename T2>
bool XMLTree<T1, T2>::isValid() const {
	return !isEmpty() && !hasErrors();
}

template <typename T1, typename T2>
bool XMLTree<T1, T2>::isEmpty() const {
	return nextLevel.empty() && XMLNode<T1, T2>::isNodeEmpty();
}

template <typename T1, typename T2>
bool XMLTree<T1, T2>::hasErrors() const {
	return errors > 0;
}

template <typename T1, typename T2>
int XMLTree<T1, T2>::getErrors() const {
	return errors;
}

template <typename T1, typename T2>
int XMLTree<T1, T2>::getWarnings() const {
	return warnings;
}



template <typename T1, typename T2>
std::vector<XMLTree<T1, T2>*> XMLTree<T1, T2>::getTreesInPreOrder() {
	return nextLevel;
}

template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> XMLTree<T1, T2>::getNodesInPreOrder() {
	std::vector<std::pair<T1, T2>> traverse;

	// Recursively begin at the tree root Node
	getNodesInPreOrderRecursive(this, traverse);

	return traverse;
}

template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> XMLTree<T1, T2>::getNodesInOrder() {
	std::vector<std::pair<T1, T2>> traverse;

	// Recursively begin at the tree root Node
	getNodesInOrderRecursive(this, traverse);

	return traverse;
}

/*
* Setters
*/

template <typename T1, typename T2>
void XMLTree<T1, T2>::setLevel(int level) {
	this->level = level;
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::setTreeKey(T1 key) {
	this->key = key;
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::setTreeValue(T2 value) {
	this->value = value;
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::setErrors(int errors) {
	this->errors = errors;
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::setWarnings(int warnings) {
	this->warnings = warnings;
}

template <typename T1, typename T2>
bool XMLTree<T1, T2>::addTree(XMLTree<T1, T2>* tree) {
	bool added = false;

	if (tree->getLevel() == this->level + 1) {
		nextLevel.push_back(tree);
		added = true;
	}

	return added;
}

template <typename T1, typename T2>
void XMLTree<T1, T2>::addNode(T1 key, T2 value) {
	// Get the root Node key
	T1 rootNodeKey = XMLNode<T1, T2>::getNodeKey();
	T2 rootNodeValue = XMLNode<T1, T2>::getNodeValue();

	// Save key and value in root Node if empty
	if (XMLNode<T1, T2>::isNodeEmpty()) {
		XMLNode<T1, T2>::setNodeKey(key);
		XMLNode<T1, T2>::setNodeValue(value);
	}
	// Recursively check if key and value are less or equal to the root Node key and value, or come are it
	else if (key <= rootNodeKey && value <= rootNodeValue) {
		XMLNode<T1, T2>* newNode = XMLNode<T1, T2>::getPrevNode();

		if (newNode == nullptr) {
			// Add the new Node to the root Node
			XMLNode<T1, T2>* node = new XMLNode<T1, T2>(key, value);
			XMLNode<T1, T2>::setPrevNode(node);
		}
		else {
			addNodeRecursive(newNode, key, value);
		}
	}
	// Key and value must come after the root Node key and value. Recursively check.
	else {
		XMLNode<T1, T2>* newNode = XMLNode<T1, T2>::getNextNode();

		if (newNode == nullptr) {
			// Add the new Node to the root Node
			XMLNode<T1, T2>* node = new XMLNode<T1, T2>(key, value);
			XMLNode<T1, T2>::setNextNode(node);
		}
		else {
			addNodeRecursive(newNode, key, value);
		}
	}
}
