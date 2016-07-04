#pragma once
#include "TreeNode.h"
#include <fstream>
#include <string>

//int max(int num1, int num2)
//{
//	if (num1 >= num2)
//	{
//		return num1;
//	}
//
//	if (num2 >= num1)
//	{
//		return num2;
//	}
//
//	else return 0;
//}

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
		return this->size;
	}

	void levelOrder(TreeNode<Type> * node)
	{
		int height = getHeight(node);
		int i;
		for (i = 1; i <= height; i++) 
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

		while (temp->left != nullptr && temp->right != nullptr)
		{
			if (temp->left != nullptr)
			{
				temp = temp->left;
				height++;
			}

			if (temp->right != nullptr)
			{
				temp = temp->right;
				height++;
			}
		}

		return height;
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
			max_height = max(left_height, right_height); //make max function, dont use library.
		}

		return max_height + 1;
	}


	int getHeight(int key)
	{
		int max_height = 0;
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

		return max_height + 1;
	}

	int getDepth(TreeNode<Type> * node)
	{
		TreeNode<Type> * pointer = node;
		int depth = 0;
		while ((pointer->parent != nullptr))
		{
			pointer = pointer->parent;
			depth++;

		}
		return depth;
	}

	bool empty()
	{
		return (root == nullptr);
	}

	int leavesWrapper(TreeNode<Type> * node) {
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
	int siblingsWrapper(TreeNode<Type> * node1)
	{
		TreeNode<Type> * temp = root; 
		int num = siblings(temp, node1);
		count = 0;
		return num;
	}

	int siblings(TreeNode<Type> * node, TreeNode<Type> * node1)
	{
		if ((getHeight(node1) == (getHeight(node))))
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

	/*int siblings(int key)
	{
		getHeight(key)
	}*/


	TreeNode<Type> * find(int key, Type data)
	{
		cout << "Boop" << endl;

		TreeNode<Type> * pointer = this->root;
		pointer->key = key;

		if (pointer->value == data)
		{
			cout << "Found Node! Key: " << key << "  Data: " << data << endl;
			cout << "It has a height of " << getHeight(pointer) - 1 << " and a depth of " << getDepth(pointer) + 1 << endl;
			return pointer;
		}

		TreeNode<Type> * tempLeft = nullptr;
		TreeNode<Type> * tempRight = nullptr;


		if (pointer->left != nullptr)
		{
			tempLeft = find(pointer->left->key, data);
		}

		if (pointer->right != nullptr)
		{
			tempRight = find(pointer->right->key, data);
		}

		return tempLeft != nullptr ? tempLeft : tempRight;
	}


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
			//TreeNode<Type> * pointer = new TreeNode<Type>();
			//pointer->key = key;
			//pointer->value = value;
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
			cout << ", h=" << this->getHeight(pointer) << " d =" << getDepth(pointer);

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
		int left_height = getHeight(node->left);
		int right_height = getHeight(node->right);
		return (left_height - right_height);
	}

	TreeNode<Type> * balance(TreeNode<Type> * node)
	{
		int bal = balanceFactor(node);

		if (bal > 1)
		{
			if (balanceFactor(root->left) > 0)
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
		return root;
	}

	


	//Delete Attempts

	void Delete(TreeNode<Type> * node)
	{
	if (node != nullptr)
	{
	Delete(node->left);
	Delete(node->right);

	delete node;
	node = nullptr;
	}
	}

	int Min(TreeNode<Type> * node)
	{
	return node->left == nullptr ? node->key : Min(node->left);
	}


	TreeNode<Type> del(int key, TreeNode<Type> * node)
	{
	if (node == nullptr)
	{
	return * root;
	}

	if (key < node->key) return del(key, node->left);

	else if (key > node->key) return del(key, node->right);

	else
	{
	if ((node->left == nullptr) && (node->right == nullptr))
	{
	Delete(node);
	}
	else if ((node->left != nullptr) && (node->right != nullptr))
	{
	TreeNode<Type> * pointer = node;
	int min_key = Min(node->right);
	del(min_key, node);

	return * pointer;
	}
	else
	{
	TreeNode<Type> * temp = node;

	if (node->left == nullptr)
	{
	node = temp->right;
	temp->right = nullptr;
	}
	else
	{
	node = temp->left;
	temp->left = nullptr;
	}

	Delete(nullptr);

	}

	}

	size--;
	root = balance(root);
	return * root;
	} 

	~AVLTree() {};

};