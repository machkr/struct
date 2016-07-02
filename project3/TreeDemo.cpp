#define action(f) bind(static_cast<void (TreeDemo::*)(vector<int>&)> (&TreeDemo::f) ,this,_1)
#include "TreeDemo.h"

using namespace std;

void TreeDemo::buildMenus()
{
	// Initialize menus
	mainMenu = new MenuList("Please select a tree:");
	genMenu = new MenuList("Please choose an action for: General Tree");
	heapMenu = new MenuList("Please choose an action for: Heap");
	avlMenu = new MenuList("Please choose an action for: AVL Tree");

	genAccessMenu = new MenuList("Please choose an accessor method: General Tree");
	heapAccessMenu = new MenuList("Please choose an accessor method: Heap");
	avlAccessMenu = new MenuList("Please choose an accessor method: AVL Tree");

	genTraversalMenu = new MenuList("Please choose a traversal method: General Tree");
	avlTraversalMenu = new MenuList("Please choose a traversal method: AVL Tree");

	genMutatorMenu = new MenuList("Please choose a mutator method: General Tree");
	heapMutatorMenu = new MenuList("Please choose a mutator method: Heap");
	avlMutatorMenu = new MenuList("Please choose a mutator method: AVL Tree");

	// Main Menu
	mainMenu->setIsMain(true);
	mainMenu->add("General Tree", MenuList::SubMenu(genMenu), true);
	mainMenu->add("Heap", MenuList::SubMenu(heapMenu), true);
	mainMenu->add("AVL Tree", MenuList::SubMenu(avlMenu), true);

	genMenu->add("Create General Tree", action(createGen));
	heapMenu->add("Create Heap", action(createHeap));
	avlMenu->add("Create AVL Tree", action(createAvl));

}

void TreeDemo::createGen(vector<int>& prev)
{
	gen = new GenTree<string>;	

	genMenu->remove("Create General Tree");
	genMenu->add("Access", MenuList::SubMenu(genAccessMenu), true);
	genMenu->add("Traverse", MenuList::SubMenu(genTraversalMenu), true);
	genMenu->add("Mutate", MenuList::SubMenu(genMutatorMenu), true);
	
	genAccessMenu->add("Root", action(root));
	genAccessMenu->add("Size", action(size));
	genAccessMenu->add("Height", action(height));
	genAccessMenu->add("Height of Node", action(heightNode));
	genAccessMenu->add("Depth", action(depth));
	genAccessMenu->add("Empty", action(empty));
	genAccessMenu->add("Leaves", action(leaves));
	genAccessMenu->add("Siblings", action(siblings));
	genAccessMenu->add("Common Ancestor", action(commonAncestor));
	genAccessMenu->add("Find", action(find));

	genTraversalMenu->add("Preorder", action(preOrder));
	genTraversalMenu->add("Postorder", action(postOrder));
	genTraversalMenu->add("Level Order", action(levelOrder));
	
	genMutatorMenu->add("Build Tree From File", action(build));	
	genMutatorMenu->add("Clear", action(clear));
	genMutatorMenu->add("Insert", action(insert));
	genMutatorMenu->add("Delete", action(del));
	
}

void TreeDemo::createHeap(vector<int>& prev)
{
	heapMenu->remove("Create Heap");
	heapMenu->add("Access", MenuList::SubMenu(heapAccessMenu), true);
	heapMenu->add("Mutate", MenuList::SubMenu(heapMutatorMenu), true);
	
	heapAccessMenu->add("Max", action(root));
	heapAccessMenu->add("Size", action(size));
	heapAccessMenu->add("Height", action(height));
	heapAccessMenu->add("Empty", action(empty));
	heapAccessMenu->add("Leaves", action(leaves));

	heapMutatorMenu->add("Build Tree From File", action(build));	
	heapMutatorMenu->add("Clear", action(clear));
	heapMutatorMenu->add("Insert", action(insert));
	heapMutatorMenu->add("Delete Max", action(del));
}

void TreeDemo::createAvl(vector<int>& prev)
{
	avlMenu->remove("Create AVL Tree");
	avlMenu->add("Access", MenuList::SubMenu(avlAccessMenu), true);
	avlMenu->add("Traverse", MenuList::SubMenu(avlTraversalMenu), true);
	avlMenu->add("Mutate", MenuList::SubMenu(avlMutatorMenu), true);
	
	avlAccessMenu->add("Root", action(root));
	avlAccessMenu->add("Size", action(size));
	avlAccessMenu->add("Height", action(height));
	avlAccessMenu->add("Height of Node", action(heightNode));
	avlAccessMenu->add("Depth", action(depth));
	avlAccessMenu->add("Empty", action(empty));
	avlAccessMenu->add("Leaves", action(leaves));
	avlAccessMenu->add("Siblings", action(siblings));
	avlAccessMenu->add("Find", action(find));

	avlTraversalMenu->add("Preorder", action(preOrder));
	avlTraversalMenu->add("Postorder", action(postOrder));
	avlTraversalMenu->add("Level Order", action(levelOrder));
	avlTraversalMenu->add("In Order", action(inOrder));
	
	avlMutatorMenu->add("Build Tree From File", action(build));	
	avlMutatorMenu->add("Clear", action(clear));
	avlMutatorMenu->add("Insert", action(insert));
	avlMutatorMenu->add("Delete", action(del));
}


void TreeDemo::root(vector<int> &prev) 
{
	cout << "(Root)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			cout << "0x" << hex << long(gen->getRoot()) << endl;
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::size(vector<int> &prev) 
{
	cout << "(Size)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			cout << gen->getSize();
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::height(vector<int> &prev) 
{
	cout << "(Height)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			try {
				cout << gen->getHeight();
			} catch (...) {
				cout << "Error.";
			}
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::heightNode(vector<int> &prev) 
{
	int key;
	cout << "(Height of Node)" << endl;
	cout << "Enter key of node: ";
	cin >> key;
	switch (prev.back())
	{
		case 1: // Gen Tree
			try {
				cout << gen->getHeight(key);
			} catch (...) {
				cout << "Error";
			}
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::depth(vector<int> &prev) 
{
	cout << "(Depth)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
		{
			int key; 
			cout << "Key: ";
			cin >> key;
			try {
				cout << gen->getDepth(key);
			} catch (const underflow_error& e) {
				cout << "Error: " << e.what();
			}
			break;
		}
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::empty(vector<int> &prev) 
{
	cout << "(Empty)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			cout << gen->empty();
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::leaves(vector<int> &prev) 
{
	cout << "(Leaves)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			try {
				cout << gen->leaves();
			} catch (...) {
				cout << "Error";
			}
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::siblings(vector<int> &prev) 
{
	cout << "(Siblings)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
		{
			int key;
			cout << "Key: ";
			cin >> key;
			try {
				cout << gen->siblings(key);
			} catch (const underflow_error& e) {
				cout << "Error: " << e.what();
			}
			break;
		}
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::commonAncestor(vector<int> &prev) 
{
	cout << "(Common Ancestor)" << endl;
	int key1; 
	int key2;
	cout << "Key 1: ";
	cin >> key1;
	cout << "Key 2: ";
	cin >> key2;
	try {
		GenTreeNode<string> * node = gen->findCommonAncestor(key1, key2);
		cout << "\n" << node << "\nKey: " << node->getKey() << "\nValue: " << 
			node->getValue();
	} catch (const underflow_error& e) {
		cout << "Error: " << e.what();
	}
	cout << endl << endl;
}

void TreeDemo::find(vector<int> &prev) 
{
	cout << "(Find)" << endl;
	
	switch (prev.back())
	{
		case 1: // Gen Tree
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::preOrder(vector<int> &prev) 
{
	cout << "(Preorder)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::postOrder(vector<int> &prev) 
{
	cout << "(Postorder)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::levelOrder(vector<int> &prev) 
{
	cout << "(Level Order)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::inOrder(vector<int> &prev) 
{
	cout << "(Inorder)" << endl;

	cout << endl << endl;
}

void TreeDemo::build(vector<int> &prev) 
{
	cout << "(Build From File)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
		{
			string fileName;
			cout << "File Name: ";
			getline(cin, fileName);
			try {
				gen->buildTree("genTree.txt");
				cout << "Success fully opened " << fileName;
			} catch (...) {
				cout << "Error opening " << fileName;
			}
			break;
		}
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::clear(vector<int> &prev) 
{
	cout << "(Clear)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			gen->clear();
			cout << "General Tree cleared";
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::insert(vector<int> &prev) 
{
	cout << "(Insert)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
		{ 		
			int key;
			string value;
			int parent;
			cout << "Key: ";
			cin >> key;
			cin.ignore();
			cout << "Value: ";
			getline(cin, value);	
			cout << "Parent: ";
			cin >> parent;
			try {
				gen->insert(key, value, parent);
				cout << "Success";
			} catch (...) {
				cout << "Error";
			}
			break;
		}
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}

void TreeDemo::del(vector<int> &prev) 
{
	cout << "(Delete)" << endl;
	switch (prev.back())
	{
		case 1: // Gen Tree
			break;
		case 2: // Heap
			break;
		case 3: // AVL
			break;
	}
	cout << endl << endl;
}
