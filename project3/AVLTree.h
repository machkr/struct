#pragma once
#include "TreeNode.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

template <class Type>
class AVLTree {
private:
	int count = 0; //Used for Siblings Function 

public:
	AVLTree() : size(0), root(nullptr) { }

	TreeNode<Type> * root;
	int size;

	TreeNode<Type> getRoot()
	{
		return this->root;
	}

	int getSize() //private vs protected, think about whether or not we should do it this way. 
	{
		return this->size+1;
	}

	void levelOrder(TreeNode<Type> * node)
	{
		int height = getHeight(node);
		int i;
		for (i = 0; i <= height+2; i++) 
		{
			leveling(node, i);
		}
	}

	void leveling(TreeNode<Type> * node, int level)
	{
		if (node == nullptr)
		{
			return;
		}
		if (level == 1)
		{
			cout << node->key << ", " << node->value << endl;
		}
		else if (level > 1)
		{
			leveling(node->left, level - 1);
			leveling(node->right, level - 1);
		}
	}

	int getHeight()
	{
		int height = 0;
		TreeNode<Type> * temp = root;

		if (temp == nullptr)
		{
			return height;
		}

		while (temp->left != nullptr)
		{
				temp = temp->left;
				height++;
		}

		return height+1;
	}

	int getHeight(TreeNode<Type> * node)
	{
		int max_height = 0;

		if (node == nullptr)
		{
			return -1;
		}

		if (node != nullptr)
		{
			int left_height = getHeight(node->left);
			int right_height = getHeight(node->right);
			max_height = max(left_height, right_height); 
		}
		return max_height + 1;

	}

	int getHeight(int key)
	{
		int height = getHeight(root);

		TreeNode<Type> * pointer = root;

		while (pointer->key != key && pointer != nullptr)
		{
			if (key >= pointer->key)
			{
				pointer = pointer->right;
				height--;
			}

			if (key < pointer->key)
			{
				pointer = pointer->left;
				height--;
			}
		}

		if (key == pointer->key)
		{
			return height;
		}
	
		return height;

		/*int max_height = 0;
		if (root == nullptr)
		{
			return -1;
		}
		else if (root != nullptr)
		{
			int left_height = getHeight(root->left);
			int right_height = getHeight(root->right);
			max_height = max(left_height, right_height);
		}

		return max_height;*/
	}

	int getDepth(int key) 
	{
		int depth = 0;

		TreeNode<Type> * pointer = root;

		while (pointer->key != key && pointer != nullptr)
		{
			if (key >= pointer->key)
			{
				pointer = pointer->right;
				depth++;
			}

			if (key < pointer->key)
			{
				pointer = pointer->left;
				depth++;
			}
		}

		if (key == pointer->key)
		{
			return depth;
		}

		return depth;
	}

	int getDepth(TreeNode<Type> * node)
	{
		TreeNode<Type> * pointer = node;
		TreeNode<Type> * parent = node->parent;
		int depth = 0;
		while ((parent != nullptr))
		{
			pointer = parent;
			parent = parent->parent;
			depth++;
		}
		return depth;
	}

	bool empty()
	{
		return (root == nullptr);
	}

	int leavesWrapper(TreeNode<Type> * node) 
	{
		int num = leaves(node);
		count = 0;
		return num;
	}

	int leaves(TreeNode<Type> * node)
	{
		if ((node->left == nullptr) && (node->right == nullptr))
		{
			count++;
		}

		if (node->left != nullptr)
		{
			leaves(node->left);
		}

		if (node->right != nullptr)
		{
			leaves(node->right);
		}

		return count;
	}

	//SIBLINGS!
	/*int siblingsWrapper(TreeNode<Type> * node1)
	{
		TreeNode<Type> * temp = root; 
		int num = siblings(temp, node1);
		count = 0;
		return num;
	}

	int siblings(TreeNode<Type> * node, TreeNode<Type> * node1)
	{
		if ((getHeight(node1->key) == (getHeight(node->key))))
		{
			count++;
		}

		if (node->left != nullptr)
		{
			siblings(node->left, node1);
		}

		if (node->right != nullptr)
		{
			 siblings(node->right, node1);
		}

		return count;

	}

	int siblings(int key)
	{
		TreeNode<Type> * node = root;
		while (key != node->key && node!= nullptr)
		{
			if (node->next)
		}

		if (node == nullptr)
		{
			cout << "Could not find key!" << endl;
			return 0;
		}
		getHeight(key)
	}*/


	Type find(int key)
	{
		if (root == nullptr) return nullptr;

		TreeNode<Type> * pointer = root;

		while (key != pointer->key)
		{
			if (key < pointer->key)
			{
				pointer = pointer->left;
			}

			if (key > pointer->key)
			{
				pointer = pointer->right;
			}
		}

		if (pointer->key == key)
		{
			cout << "Node has been located! The data is: ";
			return pointer->value;
		}

		else
		{
			cout << "Could not locate the node! Sorry!" << endl;
			return nullptr;
		}
	}
		/*TreeNode<Type> * tempLeft = nullptr;
		TreeNode<Type> * tempRight = nullptr;


		if (pointer->left != nullptr)
		{
			tempLeft = find(pointer->left->key, data);
		}

		if (pointer->right != nullptr)
		{
			tempRight = find(pointer->right->key, data);
		}

		return tempLeft != nullptr ? tempLeft : tempRight;*/


	void buildTree(string file)
	{
		Type value;
		int key;

		ifstream input;
		input.open(file);

		if (!input) { throw underflow_error("Error: unable to open file."); }

		while (!input.eof())
		{
			if (root == nullptr)
			{
				input >> key;
				input.ignore();
				getline(input, value);
				TreeNode<Type> * lol = new TreeNode<Type>(value);
				lol->key = key;
				root = lol;
			}

			input >> key;
			input.ignore();
			getline(input, value);
			TreeNode<Type> * cake = new TreeNode<Type>(value,key);
			insert(cake->key, cake->value); 
		}

		input.close();
	}


	void clear()
	{
		delete this->root;
		this->root = nullptr;
		this->size = 0;

	}

	void display(TreeNode<Type> * currentNode, int height)
	{
		TreeNode<Type> * pointer = currentNode;
		if (pointer != nullptr)
		{
			display(pointer->right, height + 1);
			cout << endl;
			if (pointer == this->root) cout << "Root: ";
			int iterator = 0;
			for (iterator = 0; (pointer != this->root) && (iterator < height); iterator++) cout << "\t\t";

			cout << pointer->key << "," << pointer->value;
			display(pointer->left, height+1);
		}
	}

	TreeNode<Type> * left_Left_Rotation(TreeNode<Type> * node) //Right Rotation

	{

		TreeNode<Type>  *pointer;

		pointer = node->left;

		node->left = pointer->right;

		pointer->right = node;

		node->parent = pointer;

		pointer->parent = nullptr;

		return pointer;

	}

	TreeNode<Type> * left_Right_Rotation(TreeNode<Type> * node) //Left Right Rotation

	{

		TreeNode<Type> *pointer;

		pointer = node->left;

		node->left = right_Right_Rotation(pointer);

		return left_Left_Rotation(node);

	}

	TreeNode<Type> * right_Right_Rotation(TreeNode<Type> * node) //Left Rotation
	{

		TreeNode<Type> *pointer;

		pointer = node->right;

		node->right = pointer->left;

		pointer->left = node;

		node->parent = pointer;

		pointer->parent = nullptr;

		return pointer;

	}

	TreeNode<Type> * right_Left_Rotation(TreeNode<Type> * node)  //Right Left Rotation

	{

		TreeNode<Type> *pointer;

		pointer = node->right;

		node->right = left_Left_Rotation(pointer);

		return right_Right_Rotation(node);

	}

	int balanceFactor(TreeNode<Type> * node)
	{
		if (node->right != nullptr && node->left != nullptr)
		{
			int left_height = getHeight(node->left);
			int right_height = getHeight(node->right);
			return (left_height - right_height);
		}

		if (node->left == nullptr) 
		{
			return (0 - getHeight(node->right));
		}

		if (node->right == nullptr)
		{
			return (getHeight(node->left));
		}
		
		return 0;
	}

	TreeNode<Type> * balance(TreeNode<Type> * node)
	{
		int bal = balanceFactor(node);

		if (bal > 1)
		{
			if (balanceFactor(node->left) > 0)
			{
				node = left_Left_Rotation(node);
			}
			else
			{
				node = left_Right_Rotation(node);
			}
		}
		else if (bal < -1)
		{

			if (balanceFactor(node->right) > 0)
			{
				node = right_Left_Rotation(node);
			}
			else
			{
				node = right_Right_Rotation(node);
			}
		}
		return node;
	}


	TreeNode<Type> * insert(int key, Type data)
	{
		TreeNode<Type> * ptr = root;
		TreeNode<Type> * newNode = new TreeNode<Type>(data, key);

		if (root == nullptr)
		{
			root = newNode;
			root->left = root->right = root->parent = nullptr;
			size++;
			return root;
		}

		while (key < ptr->key && ptr->left != nullptr)
		{
			ptr = ptr->left;
		}

		while (key >= ptr->key && ptr->right != nullptr)
		{
			ptr = ptr->right;
		}

		while (key < ptr->key && ptr->left != nullptr)
		{
			ptr = ptr->left;
		}

		while (key >= ptr->key && ptr->right != nullptr)
		{
			ptr = ptr->right;
		}

		if (key < ptr->key)
		{
			newNode->parent = ptr;
			ptr->left = newNode;
		}

		else if (key >= ptr->key)
		{
			newNode->parent = ptr;
			ptr->right = newNode;
		}

		size++;
		root = balance(root);
		root = balance(root);
		return root;
	}

	void del(int key)
	{
				TreeNode<Type> * node = root;
				TreeNode<Type> * parent = nullptr;
		
			//While we're not reaching nullptr, we traverse the tree, going left or right depending on the key's value in comaprison to the current node's key's value.
			while (node != nullptr)
			{
					if (node->key == key)
					{
						break;	
					}

					else
					{
						parent = node;

						if (key < node->key && node->left!= nullptr) //If the key is less than the current node's key, we go point to the left child.
						{
							node = node->left;
						}

						else if (key >= node->key && node->right!= nullptr)//If the key is greater than or equal to the current node's key, we go point to the right child.
						{
							node = node->right;
						}
					}
			}
		
			if (node != nullptr && node->key == key)
			{
				
					if (node == root) 
					{
						deleteNode(root);						
					}
				
					else if (parent->left == node) 
					{
						deleteNode(parent->left);
					}
				
					else 
					{
						deleteNode(parent->right);
					}
			}

			else
			{
				cout << "The key could not be located." << endl << endl;
			}

			root = balance(root);	
			size--;
	}
	
		void deleteNode(TreeNode<Type> * & node)
		{
		
			TreeNode<Type> * parent = node;
			TreeNode<Type> * temp = node;
		
			//If the node being deleted's right is null, we want to point the node to the left. 
			if (node->right == nullptr) 
			{
				node = node->left;
			}
			//If the node being deleted's left is null, we want to point the node to the right.
			else if (node->left == nullptr) 
			{
				node = node->right;
			}
		
			//If neither are null, then assign temp to the deleted node's left, and make the deleted node the parent. 
			else
			{
				temp = node->left;
				parent = node;

				//While temp right isn't null, make the parent the temp, and make the temp go onwards to the right. 
				while (temp->right != nullptr)
				{
					parent = temp;
					temp = temp->right;
				}

				//After the above loop, we've found temp->right is now null, so we make the node equal to temp itself. 
				node = temp;

				//if the parent is equal to the deleted node, then we know that temp->left needs to go into parent's left. Else, it needs to go to the right. At this point, temp left can still be nullptr without issue.
				if (parent == node)
				{
					parent->left = temp->left;
				}

				else
				{
					parent->right = temp->left;
				}
			}
			delete temp;
	}

	~AVLTree() {};

};