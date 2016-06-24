#include "LinkedList.h"

template <class Type>
class GenTree;

template <class Type>
class GenTreeNode {
	friend class GenTree;

	private: 
		int key;
		Type value;

		LinkedList<GenTreeNode> children;
	
	public: 
		GenTreeNode(int key_, Type value_) : 
			key(key_),
			value(value_) 
		{}

};
