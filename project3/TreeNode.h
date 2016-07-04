#pragma once
#include <iostream>



using namespace std;


template<class Type>
class TreeNode{
//private:  
public:

int key;
Type value;

TreeNode<Type> * parent;
TreeNode<Type> * left; 
TreeNode<Type> * right;


//public:
	TreeNode() : key(0), parent(0), left(0), right(0), value(0) {}

	TreeNode(const Type & value) : key(0), parent(0), left(0), right(0) 
	{
		this->value = value;
	}

	void visit() {
		cout << this->key << ", " << this->value << endl;
	}

	void preorder() {
		this->visit();
		if (left != nullptr) left->preorder();
		if (right != nullptr) right->preorder();
	}
	void inorder() {
		if (left != nullptr) left->inorder();
		this->visit();
		if (right != nullptr) right->inorder();
	}
	void postorder() {
		if (left != nullptr) left->postorder();
		if (right != nullptr) right->postorder();
		this->visit();
	}
	void levelorder() {
		if (this == nullptr) return;
	}

~TreeNode() {};

};