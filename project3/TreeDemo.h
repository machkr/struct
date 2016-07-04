#pragma once
#include <iostream>
#include <string>
#include "MenuList.h"
#include "GenTree.h"
#include "MaxHeapTree.h"

class TreeDemo 
{
	private:
		GenTree<string> *gen;
		MaxHeapTree<string> *heap;
		void* avl;

		MenuList * mainMenu;
		MenuList * genMenu;
		MenuList * heapMenu;
		MenuList * avlMenu;

		MenuList * genAccessMenu;
		MenuList * heapAccessMenu;
		MenuList * avlAccessMenu;

		MenuList * genTraversalMenu;
		MenuList * avlTraversalMenu;

		MenuList * genMutatorMenu;
		MenuList * heapMutatorMenu;
		MenuList * avlMutatorMenu;

		MenuList * heapDisplayMenu;

		void buildMenus();

		/********************
		 *  Menu Functions  *
		 *******************/

		// Create Functions
		void createGen(vector<int> &prev);
		void createHeap(vector<int> &prev);
		void createAvl(vector<int> &prev);
		
		// Common Methods
		void root(vector<int> &prev);
		void size(vector<int> &prev);
		void height(vector<int> &prev);
		void heightNode(vector<int> &prev);
		void depth(vector<int> &prev);
		void empty(vector<int> &prev);
		void leaves(vector<int> &prev);
		void siblings(vector<int> &prev);
		void commonAncestor(vector<int> &prev);
		void find(vector<int> &prev);

		void preOrder(vector<int> &prev);
		void postOrder(vector<int> &prev);
		void levelOrder(vector<int> &prev);
		void inOrder(vector<int> &prev);
		void toFile(vector<int> &prev);

		void build(vector<int> &prev);
		void clear(vector<int> &prev);
		void insert(vector<int> &prev);
		void del(vector<int> &prev);

		void array(vector<int> &prev);
		void list(vector<int> &prev);
		void tree(vector<int> &prev);

	public: 
		void run() 
		{
			buildMenus();
			mainMenu->run();
		}
};