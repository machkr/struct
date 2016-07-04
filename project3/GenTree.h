#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "GenTreeNode.h"
#include "SimpleQueue.h"

using namespace std;

template <class Type>
class GenTree {
	private:
		GenTreeNode<Type> * root;
		int size;

		// Private Recursive Methods
		
		int getHeight(GenTreeNode<Type>* node) {
			if (node->children.getSize() == 0) {
				return 0;
			} 
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			int max = 0;
			for (it = ll->begin(); it != ll->end(); it++) {
				int count = getHeight( *it );
				if (count > max) max = count;
			}
				
			return 1 + max;
		}
	
		int getDepth(GenTreeNode<Type> * node) {
			if (node->parent == nullptr) {
				return 0;
			}
			return 1 + getDepth(node->parent);
		}

		int leaves(GenTreeNode<Type>* node) {
			if (node->children.getSize() == 0) {
				return 1;
			}
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			int numLeaves = 0;
			for (it = ll->begin(); it != ll->end(); it++) {
				numLeaves += leaves(*it);
			}
			return numLeaves;

		}

		GenTreeNode<Type>* findNode(Type& value, GenTreeNode<Type>* node) {
			if (node == nullptr) 
				return nullptr;

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				if ((*it)->value == value) 
					return *it;
				else 
					return findNode(value, *it);
			}
			return nullptr;
		}

		GenTreeNode<Type>* findNodeByKey(int key, GenTreeNode<Type>* node) {
			if (node == nullptr) 
				return nullptr;

			if (node->key == key) 
				return node;

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				if ((*it)->key == key) {
					return *it;
				} else { 
					GenTreeNode<Type> * child = findNodeByKey(key, *it);
					if (child != nullptr) 
						return child;
				}
			}
			return nullptr;
		}

		void preorder(ostream& os, GenTreeNode<Type>* node) {

			os << node->getKey() << " " << node->getValue() << endl;

			int depth = getDepth(node);

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				os << string(depth + 1, '\t');
				preorder(os, *it);
			}
		}

		void postorder(GenTreeNode<Type>* node) {

			if (node->children.getSize() == 0) {
				cout << node->getKey() << " " << node->getValue() << endl;	
				return;
			}

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				postorder(*it);
			}

			cout << node->getKey() << " " << node->getValue() << endl;	
		}
		
		void levelorder(GenTreeNode<Type>* node) {

			SimpleQueue<GenTreeNode<Type>*> q(32);
			q.enqueue(node);
			while (!q.empty()) {
				GenTreeNode<Type> * n = q.dequeue();
				cout << n->key << " " << n->value << endl;

				// Enqueue children
				LinkedList<GenTreeNode<Type>*> * ll = &(n->children);
				typename LinkedList<GenTreeNode<Type>*>::iterator it;
				for (it = ll->begin(); it != ll->end(); it++) {
					q.enqueue(*it);
				}
			}

		}

		GenTreeNode<Type>* insert(int key, Type value, GenTreeNode<Type>* parent, 
				bool overwrite) {
			if (overwrite) {
				parent->children.erase(findNodeByKey(key, root));
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


	public: 
		
		GenTree() :
			root(nullptr),
			size(0)
		{}

		~GenTree() {
			delete root;
		}
		

		// Public Accessors

		GenTreeNode<Type>* getRoot() { return root; }

		int getSize() { return size; }

		int getHeight() { 
			if (root == nullptr) {
				throw underflow_error("Root doesn't exist");
			}
			return getHeight(root); 
		}

		int getHeight(int key) {
			GenTreeNode<Type>* node = findNodeByKey(key, root);
			if (node == nullptr) {
				throw underflow_error("Key doesn't exist.");
			}
			return getHeight(node);
		}


		int getDepth(int key) {
			GenTreeNode<Type> * node = findNodeByKey(key, root);
			if (node == nullptr) 
				throw underflow_error("Key not found");

			return getDepth(node);
		}


		bool empty() { return size==0; }

		
		int leaves() {
			if (root == nullptr)
				throw underflow_error("Root doesn't exist");

			return leaves(root);
				
		}

		int siblings(int key) {
			GenTreeNode<Type>* node = findNodeByKey(key, root);
			if (node == nullptr) 
				throw underflow_error("Key not found");

			return node->parent->children.getSize() - 1;
		}

		GenTreeNode<Type>* findCommonAncestor(int key1, int key2) {
			GenTreeNode<Type> * n1 = findNodeByKey(key1,root);
			GenTreeNode<Type> * n2 = findNodeByKey(key2,root);

			if (n1 == nullptr || n2 == nullptr) 
				throw underflow_error("Key not found");

			n1 = n1->parent;
			n2 = n2->parent;

			if (n1 == nullptr || n2 == nullptr) 
				return root;

			GenTreeNode<Type> * p1;
			GenTreeNode<Type> * p2;

			for (p1=n1; p1 != nullptr; p1=p1->parent) {
				for (p2=n2; p2 != nullptr; p2=p2->parent) {
					if (p1==p2) 
						return p1;
				}
			}	
			return nullptr;
			
		}

		GenTreeNode<Type>* findNode(Type& value) {
			findNode(value, root);
		}


		void toFile(string fileName) {
			ofstream file(fileName, ios::out);

			if (!file)
				throw underflow_error("File could not be opened");

			preorder(file, root);
			file.close();
		}


		// Public Traversal
		
		void preorder() {
			if (root == nullptr) 
				throw underflow_error("Root doesn't exist");

			preorder(cout, root);
		}

		void postorder() {
			if (root == nullptr)
				throw underflow_error("Root is empty");

			postorder(root);
		}

		
		void levelorder() {
			if (root == nullptr) 
				throw underflow_error("Root is empty");

			levelorder(root);
		}


		// Public Mutators

		void buildTree(string fileName) {
			ifstream file;
			file.open(fileName, ios::in);
			int level = -1;

			if (!file) 
				throw underflow_error("Error opening file");

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
				
				// Determine parent
				if (newLevel > level)
					parent = last;
				if (newLevel < level) {
					for (int i = 0; i < level - newLevel; i++) {
						parent = parent->getParent();
					}
				}
				if (root == nullptr) {
					parent = root;
				} 
	
				// Parse line
				istringstream ss(line);
				int key;
				string value;
				ss >> key;
				value = ss.str();
				int spacePos = value.find(" ");
				value = value.substr(spacePos + 1, value.length() - spacePos);

				if (value == "") break;

				last = insert(key, value, parent, false);
				level = newLevel;
			}
			file.close();
		}

		void clear() {
			delete root;
			size = 0;
			root = nullptr;
		}

		GenTreeNode<Type>* insert(int key, Type value, int parentKey, 
				bool overwrite) {
			GenTreeNode<Type> * parent = findNodeByKey(parentKey, root);

			if (!overwrite && findNodeByKey(key, root) != nullptr) {
				throw overflow_error("Key already exists!");
			}
			return insert(key, value, parent, overwrite);
		}


		int del(Type value) {
			delete findNode(value, root);
		}

};
