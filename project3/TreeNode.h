#include <iostream>

using namespace std;

template<class Type>

Class TreeNode{
private:  

int key;

Type value;

TreeNode* parent;
TreeNode* Children[]; //in a linked list, hmm... this will be fun? nah not really... will change this later

public:

TreeNode() {}

~TreeNode( {};

};
