#include "LinkedList.h"

template <class Type>
class GenTree;


template <class Type>
class GenTreeNode;

template <class Type>
class GenTreeNode {
	friend class GenTree<Type>;

	private: 
		int key;
		Type value;
		GenTreeNode<Type> * parent;

		LinkedList<GenTreeNode<Type>*> children;
	
	public: 
		GenTreeNode(int key_, Type value_, GenTreeNode<Type>* parent_) : 
			key(key_),
			value(value_),
			parent(parent_)
		{}

		void deleteChildren(GenTreeNode<Type> * node) {
			typename LinkedList<GenTreeNode<Type>*>::iterator it;

			if (node->children.getSize == 0)
				delete node;
				return;
					
			for (it = children.begin(); it < children.end(); it++) {
				deleteChildren(&(*it));
			}
		}	

		~GenTreeNode() {
			deleteChildren(this);
		}	
				
};
