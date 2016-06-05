#pragma once

#include "MenuClass/MenuList.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>

class LinkedListDemo {
	private: 
		LinkedList<double> * cll;
		LinkedList<double> * dll;
		
		MenuList * mainMenu;
		void buildMenus();

		void createCyclic (vector<int>& prev) {
			cll = new LinkedList<double>();
		}
		void craeteDoubly (vector<int>& prev) {
			dll = new LinkedList<double>();
		}

		void insertPushFront (vector<int>& prev); 
		void insertPushBack (vector<int>& prev);
		void insertPositional (vector<int>& prev);
		
		void removePopFront (vector<int>& prev);
		void removeErase (vector<int>& prev);
		void removePositional (vector<int>& prev);
		
		void accessSize (vector<int>& prev);
		void accessEmpty (vector<int>& prev);
		void accessFront (vector<int>& prev);


	public: 
		LinkedListDemo() {}
		void run();

};

