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
	
	public: 
		GenTree() :
			root(nullptr),
			size(0)
		{}

		~GenTree() {}

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

		int getDepth(int key) {
			GenTreeNode<Type> * node = findNodeByKey(key, root);
			if (node == nullptr) 
				throw underflow_error("Key not found");

			return getDepth(node);
		}

		int getDepth(GenTreeNode<Type> * node) {
			if (node->parent == nullptr) {
				return 0;
			}
			return 1 + getDepth(node->parent);
		}

		bool empty() { return size==0; }

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

			for (p1=n1->parent; p1 != nullptr; p1=p1->parent) {
				for (p2=n1->parent; p2 != nullptr; p2=p2->parent) {
					if (p1==p2) 
						return p1;
				}
			}	
			return nullptr;
			
		}


		GenTreeNode<Type>* findNode(Type& value) {
			findNode(value, root);
		}

		GenTreeNode<Type>* findNode(Type& value, GenTreeNode<Type>* node) {
			if (node == nullptr) 
				return nullptr;

			if (node->children.getSize() == 0) 
				return nullptr;

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				if ((*it)->value = value) 
					return *it;
				else 
					return findNode(value, *it);
			}
			return nullptr;
		}

		GenTreeNode<Type>* findNodeByKey(int key, GenTreeNode<Type>* node) {
			if (node == nullptr) 
				return nullptr;

			if (node->children.getSize() == 0) 
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

		void preorder() {
			preorder(cout, root);
		}

		void toFile(string fileName) {
			ofstream file(fileName, ios::out);

			if (!file)
				throw underflow_error("File could not be opened");

			preorder(file, root);
			file.close();
		}
		
		void preorder(ostream& os, GenTreeNode<Type>* node) {

			os << node->getKey() << " " << node->getValue() << endl;

			if (node->children.getSize() == 0) {
				return;
			}
			int depth = getDepth(node);

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				os << string(depth, '\t');
				preorder(os, *it);
			}
		}

		void postorder() {
			postorder(root);
		}

		void postorder(GenTreeNode<Type>* node) {

			int depth = getDepth(node);
			if (node->children.getSize() == 0) {
				cout << string(depth, '\t');
				cout << node->getKey() << " " << node->getValue() << endl;	
				return;
			}

			LinkedList<GenTreeNode<Type>*> * ll = &(node->children);
			typename LinkedList<GenTreeNode<Type>*>::iterator it;
			for (it = ll->begin(); it != ll->end(); it++) {
				postorder(*it);
			}

			cout << string(depth, '\t');
			cout << node->getKey() << " " << node->getValue() << endl;	
		}
		
		void levelorder() {
			levelorder(root);
		}

		void levelorder(GenTreeNode<Type>* node) {
			
		}

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

		GenTreeNode<Type>* insert(int key, Type value, int parentKey, bool overwrite) {
			GenTreeNode<Type> * parent = findNodeByKey(parentKey, root);

			if (!overwrite && findNodeByKey(key, root) != nullptr) {
				throw overflow_error("Key already exists!");
			}
			return insert(key, value, parent, overwrite);
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

		int del(Type value) {
			//try { 
				delete findNode(value);
			//} catch (const underflow_error& e) {
			//	throw e;
			//}
		}
	

};
