#pragma once

// Class forwarding
template <typename T1, typename T2>
class XMLTree;

template <typename T1, typename T2>
class XMLNode {
	private:
		int								id;
		T1								key;
		T2								value;
		bool							empty;

		XMLNode<T1, T2>*				prevNode;
		XMLNode<T1, T2>*				nextNode;

	public:
		XMLNode();
		XMLNode(T1 key, T2 value);

		virtual ~XMLNode();

		// Getters
		int					getId() const;
		T1					getNodeKey() const;
		T2					getNodeValue() const;
		bool				isNodeEmpty() const;
		XMLNode<T1, T2>*	getPrevNode() const;
		XMLNode<T1, T2>*	getNextNode() const;

		// Setters
		void				setNodeKey(T1 key);
		void				setNodeValue(T2 value);
		void				setPrevNode(XMLNode<T1, T2>* prevNode);
		void				setNextNode(XMLNode<T1, T2>* nextNode);
};

template <typename T1, typename T2>
// Shows how to use the initializer list to tell c++11 or later compiler to init the templated
// class variables to the default values for their actual types.
// Prior to c++11:
// Node<T1, T2>::Node() : key(), value() {
// }
XMLNode<T1, T2>::XMLNode() : key{}, value{} {
	id = XMLTree<T1, T2>::getNodeId();
	empty = true;
	prevNode = nullptr;
	nextNode = nullptr;
}

template <typename T1, typename T2>
XMLNode<T1, T2>::XMLNode(T1 key, T2 value) {
	id = XMLTree<T1, T2>::getNodeId();
	this->key = key;
	this->value = value;
	empty = false;
	prevNode = nullptr;
	nextNode = nullptr;
}

template <typename T1, typename T2>
XMLNode<T1, T2>::~XMLNode() {
}

/*
* Getters
*/

template <typename T1, typename T2>
int	XMLNode<T1, T2>::getId() const {
	return id;
}

template <typename T1, typename T2>
T1 XMLNode<T1, T2>::getNodeKey() const {
	return key;
}

template <typename T1, typename T2>
T2 XMLNode<T1, T2>::getNodeValue() const {
	return value;
}

template <typename T1, typename T2>
bool XMLNode<T1, T2>::isNodeEmpty() const {
	return	prevNode == nullptr && nextNode == nullptr && key.empty();
}

template <typename T1, typename T2>
XMLNode<T1, T2>* XMLNode<T1, T2>::getPrevNode() const {
	return prevNode;
}

template <typename T1, typename T2>
XMLNode<T1, T2>* XMLNode<T1, T2>::getNextNode() const {
	return nextNode;
}

/*
* Setters
*/

template <typename T1, typename T2>
void XMLNode<T1, T2>::setNodeKey(T1 key) {
	this->key = key;
	empty = false;
}

template <typename T1, typename T2>
void XMLNode<T1, T2>::setNodeValue(T2 value) {
	this->value = value;
}

template <typename T1, typename T2>
void XMLNode<T1, T2>::setPrevNode(XMLNode<T1, T2>* prevNode) {
	this->prevNode = prevNode;
}

template <typename T1, typename T2>
void XMLNode<T1, T2>::setNextNode(XMLNode<T1, T2>* nextNode) {
	this->nextNode = nextNode;
}
