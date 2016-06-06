#pragma once

#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"
#include "MenuList.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>

class LinkedListDemo
{
	friend class MenuList;
	private: 
		CyclicLinkedList<double> * cll;
		DoublyLinkedList<double> * dll;
		
		MenuList * mainMenu;
		void buildMenus();

		void createCyclic (vector<int>& prev)
		{
			if (cll == nullptr)
			{
				cll = new CyclicLinkedList<double>();
				cout << endl << "Cyclic Linked List created successfully." << endl << endl;
			}
			else
			{
				cout << endl << "Cyclic Linked List already exists!" << endl << endl;
			}
		}

		void createDoubly (vector<int>& prev)
		{
			if (dll == nullptr)
			{
				dll = new DoublyLinkedList<double>();
				cout << endl << "Doubly Linked List created successfully." << endl << endl;
			}
			else
			{
				cout << endl << "Doubly Linked List already exists!" << endl << endl;
			}
		}

		void insertPushFront (vector<int>& prev)
		{
			double data;
			cout << "Value to insert: ";

			try
			{
				data = getDouble();
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}
			
            if (prev[0] == 1) {// If Cyclic Linked List was chosen
                if (cll == nullptr) {
                    cout << "Cyclic Linked List does not exist!" << endl;
                    return;
                }
				cll->push_front(data);
            } else if (prev[0] == 2) {// If Doubly Linked List was chosen
                if (dll == nullptr) {
                    cout << "Doubly Linked List does not exist!" << endl;
                    return;
                }
				dll->push_front(data);
            }
			else
			{
				cout << "There was an error saving the data" << endl << endl;
				return;
			}
			cout << endl << "Node inserted successfully." << endl << endl;
		}

		void insertPushBack (vector<int>& prev)
		{
			double data;
			cout << "Value to insert: ";

			try
			{
				data = getDouble();
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}
			
            if (prev[0] == 1) {// If Cyclic Linked List was chosen
                if (cll == nullptr) {
                    cout << "Cyclic Linked List does not exist!" << endl;
                    return;
                }
				cll->push_back(data);
            }
            else if (prev[0] == 2) { // If Doubly Linked List was chosen
                if (dll == nullptr) {
                    cout << "Doubly Linked List does not exist!" << endl;
                    return;
                }
				dll->push_back(data);
            }
			else
			{
				cout << "There was an error saving the data" << endl << endl;
				return;
			}
			cout << endl << "Node inserted successfully." << endl << endl;

		}

		void removePopFront (vector<int>& prev)
		{
            
			try {
                if (prev[0] == 1) {
                    if (cll == nullptr) {
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cout << cll->pop_front() << " has been popped." << endl << endl;
                } else if (prev[0] == 2) {
                    if (dll == nullptr) {
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					cout << dll->pop_front() << " has been popped." << endl << endl;
                }
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
			}
		}

		void removeErase (vector<int>& prev)
		{
			int count;
			double data;
			cout << "Value to erase: ";

			try
			{
				data = getDouble();
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}
			try {
				if (prev[0] == 1)
				{
                    if (cll == nullptr) {
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					count = cll->erase(data);
				}
				else if (prev[0] == 2)
				{
                    if (dll == nullptr) {
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					count = dll->erase(data);
				}
				else
				{
					cout << "There was an error erasing the data" << endl << endl;
					return;
				}
			} catch (const underflow_error& e) {
				cout<< e.what() << endl;
				return;
			}
			cout << endl << "Deleted " << count << " nodes from list." << endl << endl;
		}

		void accessSize (vector<int>& prev)
		{
			try {
                if (prev[0] == 1) {
                    if (cll == nullptr) {
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cll->getSize();
                } else if (prev[0] == 2) {
                    if (dll == nullptr) {
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					dll->getSize();
                }
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
			}
		}

		void accessEmpty(vector<int>& prev)
		{
            if (prev[0] == 1) {
                if (cll == nullptr) {
                    cout << "Cyclic Linked List does not exist!" << endl;
                    return;
                }
				cll->empty();
            } else if (prev[0] == 2) {
                if (dll == nullptr) {
                    cout << "Doubly Linked List does not exist!" << endl;
                    return;
                }
				dll->empty();
            }
		}

		void accessFront(vector<int>& prev)
		{
			try {
                if (prev[0] == 1) {
                    if (cll == nullptr) {
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cll->front();
                } else if (prev[0] == 2) {
                    if (dll == nullptr) {
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					dll->front();
                }
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
			}
		}

		void accessBack (vector<int>& prev)
		{
			try {
                if (prev[0] == 1) {
                    if (cll == nullptr) {
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
                    cll->back();
                } else if (prev[0] == 2) {
                    if (dll == nullptr) {
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					dll->back();
                }
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
			}
		}

		void accessCount(vector<int>& prev)
		{
			double applesauce;
			try {
                if (prev[0] == 1) {
                    if (cll == nullptr) {
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cll->count(applesauce);
                } else if (prev[0] == 2) {
                    if (dll == nullptr) {
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					dll->count(applesauce);
                }
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
				return;
			}
			cout << "Counted " << applesauce << " values.\n";
		}

		void outputCyclic (vector<int>& prev)
		{
            if (cll == nullptr) {
                cout << "Cyclic Linked List does not exist!" << endl;
                return;
            }
			try {
				cll->print();
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
			}
		}

		void outputDoubly (vector<int>& prev)
		{
            if (dll == nullptr) {
                cout << "Doubly Linked List does not exist!" << endl;
                return;
            }
			try {
				dll->print();
			} catch (const underflow_error& e) {
				cout << e.what() << endl;
			}
		}
				
		double getDouble()
		{
			double data;
			string input;
			cin >> input;

			try
			{
				data = stod(input);
			}

			catch (...)
			{
				throw invalid_argument("Error reading input.");
			}
			return data;
		}

	public: 
		LinkedListDemo() : cll(nullptr), dll(nullptr) {}
		void run()
		{
			buildMenus();
			mainMenu->run();
		}

};
