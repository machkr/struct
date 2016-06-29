#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "GenTreeNode.h"

using namespace std;

template <class Type>
class GenTree {
	private:
		GenTreeNode<Type> * root;
		int size;
		int height;
	
	public: 
		GenTree() :
			root(nullptr),
			size(0),
			height(0)
		{}

		~GenTree() {}

		GenTreeNode<Type>* getRoot() { return root; }

		int getSize() { return size; }
		int getHeight() { return height; }

		int getHeight(int key) {
							
		}

		int getDepth(int key) {
			
		}

		bool empty() { return size==0; }
		int leaves() {}
		int siblings(int key) {}
		GenTreeNode<Type>* findCommonAncestor(int key1, int key2) {}
		GenTreeNode<Type>* findNode(Type& value, GenTreeNode<Type>* node) {
			if (node == nullptr) 
				return nullptr;

			if (node->children.getSize() == 0) 
				return nullptr;

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it < ll->end(); it++) {
				if ((*it).value = value) 
					return &(*it);
				else 
					return findNode(value, &(*it));
			}

			return nullptr;

		}

		GenTreeNode<Type>* findNodeByKey(int key, GenTreeNode<Type>* node) {
			if (node == nullptr) 
				return nullptr;

			if (node->children.getSize() == 0) 
				return nullptr;

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it < ll->end(); it++) {
				if ((*it).key = key) 
					return &(*it);
				else 
					return findNodeByKey(key, &(*it));
			}

			return nullptr;

		}

		void preorder(GenTreeNode<Type>* node) {}
		void postorder(GenTreeNode<Type>* node) {}
		void levelorder(GenTreeNode<Type>* node) {}

		void buildTree(string fileName) {
			ifstream file("fileName");
			int level = -1;

			GenTreeNode<Type> * parent = root = nullptr;
			GenTreeNode<Type> * last = root;
			while (file.good()) {
				string line;
				getline(file, line);

				// Count tabs
				int newLevel = 0;
				string::iterator it;
				for (it = line.begin(); it != line.end(); it++) {
					if (*it == '\t') 
						newLevel++;
					else
						break;
				}

				if (newLevel > level)
					parent = last;

				if (newLevel < level) 
					parent = parent->getParent();

				if (root == nullptr) {
					parent = root;
				} 
	
				istringstream ss(line);
				int key;
				string value;
				ss >> key;
				value = ss.str();

				last = insert(key, value, parent);
				level = newLevel;
			}
		}

		void clear() {
			delete root;
			root = nullptr;
		}

		GenTreeNode<Type>* insert(int key, Type value, int parentKey) {
			GenTreeNode<Type> * parent = findNodeByKey(parentKey, root);

			if (findNodeByKey(key, root) != nullptr) {
				throw overflow_error("Key already exists!");
			}

			GenTreeNode<Type> * newNode = new GenTreeNode<Type>(key, value, parent);
			if (parent == nullptr) {
				root = newNode;
			} else {
				parent->children.push_back(newNode);
			}
			size++;
			return newNode;
		}

		int del(Type value) {
			//try { 
				delete findNode(value);
			//} catch (const underflow_error& e) {
			//	throw e;
			//}
		}
	

};
