#pragma once

#include "MenuList.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>

class LinkedListDemo {
	friend class MenuList;
	private: 
		LinkedList<double> * cll;
		LinkedList<double> * dll;
		
		MenuList * mainMenu;
		void buildMenus();

		void createCyclic (vector<int>& prev) {
			cll = new LinkedList<double>();
		}
		void createDoubly (vector<int>& prev) {
			dll = new LinkedList<double>();
		}

		void insertPushFront (vector<int>& prev) {
			double data;
			cout << "Value to insert: ";
			try {
				data = getDouble();
			} catch (...) {
				cout << endl << "Error reading input! Try again." << endl;
				return;
			}
			
			if (prev[0] == 1) // If Cyclic Linked List was chosen
				cll->push_front(data);
			else if (prev[0] == 2) // If Doubly Linked List was chosen
				dll->push_front(data);
			else {
				cout << "There was an error saving the data" << endl;
				return;
			}
			cout << endl << "Node inserted successfully." << endl << endl;
		}
		void insertPushBack (vector<int>& prev) {}
		void insertPositional (vector<int>& prev) {}
		
		void removePopFront (vector<int>& prev) {}
		void removeErase (vector<int>& prev) {}
		void removePositional (vector<int>& prev) {}
		
		void accessSize (vector<int>& prev) {}
		void accessEmpty (vector<int>& prev) {}
		void accessFront (vector<int>& prev) {}
		void accessBack (vector<int>& prev) {}
		void accessCount (vector<int>& prev) {}

		void outputCyclic (vector<int>& prev) {}
		void outputDoubly (vector<int>& prev) {}
				
		double getDouble() {
			double data;
			string input;
			cin >> input;
			try {
				data = stod(input);
			} catch (...) {
				throw invalid_argument("Error reading input.");
			}
			return data;
		}

	public: 
		LinkedListDemo() {}
		void run() {
			buildMenus();
			mainMenu->run();
		}

};

