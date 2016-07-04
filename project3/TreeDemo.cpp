#define action(f) bind(static_cast<void (TreeDemo::*)(vector<int>&)> (&TreeDemo::f) ,this,_1)
#include "TreeDemo.h"
#include <string>

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

	heapDisplayMenu = new MenuList("Please choose a display method: Heap");
	avlDisplayMenu = new MenuList("Please choose a display method: AVL Tree");

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
	genTraversalMenu->add("Save to File", action(toFile));
	
	genMutatorMenu->add("Build Tree From File", action(build));	
	genMutatorMenu->add("Clear", action(clear));
	genMutatorMenu->add("Insert", action(insert));
	genMutatorMenu->add("Delete", action(del));
	
}

void TreeDemo::createHeap(vector<int>& prev)
{
	heap = new MaxHeapTree<string>;

	heapMenu->remove("Create Heap");
	heapMenu->add("Access", MenuList::SubMenu(heapAccessMenu), true);
	heapMenu->add("Display", MenuList::SubMenu(heapDisplayMenu), true);
	heapMenu->add("Mutate", MenuList::SubMenu(heapMutatorMenu), true);
	
	heapAccessMenu->add("Max", action(root));
	heapAccessMenu->add("Size", action(size));
	heapAccessMenu->add("Height", action(height));
	heapAccessMenu->add("Empty", action(empty));
	heapAccessMenu->add("Leaves", action(leaves));

	heapDisplayMenu->add("Array", action(array));
	heapDisplayMenu->add("List", action(list));
	heapDisplayMenu->add("Tree", action(tree));

	heapMutatorMenu->add("Build Heap From File", action(build));	
	heapMutatorMenu->add("Clear", action(clear));
	heapMutatorMenu->add("Insert", action(insert));
	heapMutatorMenu->add("Delete Max", action(del));
}

void TreeDemo::createAvl(vector<int>& prev)
{
	avl = new AVLTree<string>;

	avlMenu->remove("Create AVL Tree");
	avlMenu->add("Access", MenuList::SubMenu(avlAccessMenu), true);
	avlMenu->add("Traverse", MenuList::SubMenu(avlTraversalMenu), true);
	avlMenu->add("Display", MenuList::SubMenu(avlDisplayMenu), true);
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

	avlDisplayMenu->add("Array", action(array));
	avlDisplayMenu->add("List", action(list));
	avlDisplayMenu->add("Tree", action(tree));
	
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
			cout << dec;
			break;
		case 2: // Heap
			cout << "Key: " << heap->getMax().getKey()
				<< ", Value: " << heap->getMax().getData();
			break;
		case 3: // AVL
			cout << avl->root->getKey();
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
			cout << heap->getSize();
			break;
		case 3: // AVL
			cout << avl->getSize();
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
		try { cout << gen->getHeight(); }
		catch (const underflow_error& e) { cout << "Error: " << e.what(); }
		break;
	case 2: // Heap
		try { cout << heap->getHeight(1); }
		catch (const underflow_error& e) { cout << "Error: " << e.what(); }
		break;
	case 3: // AVL
		try { cout << avl->getHeight(); }
		catch (const underflow_error& e) { cout << "Error: " << e.what(); }
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
			try { cout << gen->getHeight(key); }
			catch (...) { cout << "Error"; }
			break;
		case 3: // AVL
			try { cout << avl->getHeight(key); }
			catch (...) { cout << "Error";  }
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
			try { cout << gen->getDepth(key); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
		}
		case 3: // AVL
			int key;
			cout << "Key: ";
			cin >> key;
			try { cout << avl->getDepth(avl->root); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
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
			cout << ((gen->empty()) ? "True" : "False");
			break;
		case 2: // Heap
			cout << ((heap->empty()) ? "True" : "False");
			break;
		case 3: // AVL
			cout << ((avl->empty()) ? "True" : "False");
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
			try { cout << gen->leaves(); }
			catch (...) { cout << "Error"; }
			break;
		case 2: // Heap
			try { cout << heap->leaves(); }
			catch (...) { cout << "Error"; }
			break;
		case 3: // AVL
			try { cout << avl->leavesWrapper(avl->root); }
			catch (...) { cout << "Error"; }
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
			try { cout << gen->siblings(key); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
		}
		case 3: // AVL
		{
			int key;
			string value;
			cout << "Key: ";
			cin >> key;
			cout << "Value: ";
			getline(cin, value);

			TreeNode<string> *temp = new TreeNode<string>();
			temp->value = value;
			temp->key = key;

			try { cout << avl->siblingsWrapper(temp); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
		}
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
	try
	{
		GenTreeNode<string> * node = gen->findCommonAncestor(key1, key2);
		cout << "\n" << node << "\nKey: " << node->getKey() <<
			"\nValue: " << node->getValue();
	}
	catch (const underflow_error& e)
	{
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
			cout << "Key: ";
			int key;
			cin >> key;
			string value;
			getline(cin, value);
			try { cout << avl->find(key, value); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
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
			try { gen->preorder(); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
		case 3: // AVL
			try { avl->root->preorder(); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
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
			try { gen->postorder(); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
			break;
		case 3: // AVL
			try { avl->root->postorder(); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
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
			try { gen->levelorder(); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
		case 3: // AVL
			try { avl->levelOrder(avl->root); }
			catch (const underflow_error& e) { cout << "Error: " << e.what(); }
			break;
	}
	cout << endl << endl;
}

void TreeDemo::inOrder(vector<int> &prev) 
{
	// AVL
	cout << "(Inorder)" << endl;
	try { avl->root->inorder(); }
	catch (const underflow_error& e) { cout << "Error: " << e.what(); }
	cout << endl << endl;
}

void TreeDemo::toFile(vector<int> &prev)
{
	// GenTree
	string fileName;
	cout << "File Name: ";
	getline(cin, fileName);
	try { gen->toFile(fileName); }
	catch (const underflow_error& e)
	{
		cout << "Error: " << e.what();
		return;
	}

	cout << "Successfully wrote tree to: " << fileName << endl << endl;
}

void TreeDemo::build(vector<int> &prev) 
{
	cout << "(Build From File)" << endl;
	string fileName;
	cout << "Filename: ";
	getline(cin, fileName);

	switch (prev.back())
	{
		case 1: // Gen Tree
		{
			try
			{
				gen->buildTree(fileName);
				cout << "Successfully opened " << fileName;
			}
			catch (...) { cout << "Error opening " << fileName; }
			break;
		}
		case 2: // Heap
			try
			{
				heap->buildTree(fileName);
				cout << "Successfully opened " << fileName;
			}
			catch (...) { cout << "Error opening " << fileName; }
			break;
		case 3: // AVL
			try
			{
				avl->buildTree(fileName);
				cout << "Successfully opened " << fileName;
			}
			catch (...) { cout << "Error opening " << fileName; }
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
			cout << "General Tree cleared.";
			break;
		case 2: // Heap
			heap->clear();
			cout << "Max Heap Tree cleared.";
			break;
		case 3: // AVL
			avl->clear();
			cout << "AVL Tree cleared.";
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

			try { gen->insert(key, value, parent, false); }
			catch (const overflow_error& e)
			{
				cout << "Key already exists! Overwrite? (y/n): ";
				char overwrite;
				cin >> overwrite;
				if (overwrite == 'y')
				{
					gen->insert(key, value, parent, true);
				}
				else
				{
					break;
				}
			}
			catch (const underflow_error& e)
			{
				cout << "Error: " << e.what();
				break;
			}

			cout << "Successfully inserted.";
			break;
		}
		case 2: // Heap
		{
			int key;
			string value;

			cout << "Key: ";
			cin >> key;
			cin.ignore();
			cout << "Value: ";
			getline(cin, value);

			heap->insert(key, value);

			cout << "Successfully inserted.";
			break;
		}

		case 3: // AVL

			int key;
			string value;
			cout << "Key: ";
			cin >> key;
			cin.ignore();
			cout << "Value: ";
			getline(cin, value);

			avl->insert(key, value);

			cout << "Successfully inserted.";
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
		{
			string value;
			cout << "Value: ";
			getline(cin, value);
			try {
				gen->del(value);
				cout << "Successfully deleted";
			} catch (const underflow_error& e) {
				cout << "Error: " << e.what();
			}
			break;
		}
		case 2: // Heap
			try { heap->deleteMax(); }
			catch (const underflow_error& e) { cout << "Error" << e.what(); }
			break;
		case 3: // AVL
			int key;
			string value;
			cout << "Key: ";
			cin >> key;
			cout << "Value: ";
			getline(cin, value);

			TreeNode<string> *temp = new TreeNode<string>();
			temp->value = value;
			temp->key = key;
		
			try { avl->del(key, temp); }
			catch (const underflow_error& e) { cout << "Error" << e.what(); }
			break;
	
	}
	cout << endl << endl;
}

void TreeDemo::array(vector<int> &prev)
{
	cout << "(Display - Array)" << endl << endl;

	switch (prev.back())
	{
	case 2: // Heap
		try { heap->displayArray(); }
		catch (const underflow_error& e) { cout << e.what(); }
		break;
	case 3: // AVL
		break;
	}

	cout << endl << endl;
}

void TreeDemo::list(vector<int> &prev)
{
	cout << "(Display - List)" << endl << endl;

	switch (prev.back())
	{
	case 2: // Heap
		try { heap->displayList(); }
		catch (const underflow_error& e) { cout << e.what(); }
		break;
	case 3: // AVL
		break;
	}

	cout << endl << endl;
}

void TreeDemo::tree(vector<int> &prev)
{
	cout << "(Display - Tree)" << endl << endl;

	switch (prev.back())
	{
	case 2: // Heap
		try { heap->displayTree(); }
		catch (const underflow_error& e) { cout << e.what() << endl << endl; }
		break;
	case 3: // AVL
		break;
	}
}
