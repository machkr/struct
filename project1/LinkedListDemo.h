#pragma once

#include "CyclicLinkedList.h"
#include "DoublyLinkedList.h"
#include "MenuList.h"
#include "LinkedList.h"
#include <iostream>
#include <vector>

template<typename Type> 
class LinkedListDemo
{
	friend class MenuList;
	private: 
		CyclicLinkedList<Type> * cll;
		DoublyLinkedList<Type> * dll;
		
		MenuList * mainMenu;
		void buildMenus();

		void createCyclic (vector<int>& prev)
		{
			if (cll == nullptr)
			{
				cll = new CyclicLinkedList<Type>();
				cout << "Cyclic Linked List created successfully." << endl << endl;
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
				dll = new DoublyLinkedList<Type>();
				cout << "Doubly Linked List created successfully." << endl << endl;
			}
			else
			{
				cout << endl << "Doubly Linked List already exists!" << endl << endl;
			}
		}

		void insertPushFront (vector<int>& prev)
		{
			Type data;
			cout << "Value to insert: ";

			try
			{
				cin >> data;
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}
			
            if (prev[0] == 1) // If Cyclic Linked List was chosen
			{
                if (cll == nullptr)
				{
                    cout << "Cyclic Linked List does not exist!" << endl;
                    return;
                }
				cll->push_front(data);
            } else if (prev[0] == 2)// If Doubly Linked List was chosen
			{
                if (dll == nullptr)
				{
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
			Type data;
			cout << "Value to insert: ";

			try
			{
				cin >> data;
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}
			
            if (prev[0] == 1)
			{
                if (cll == nullptr)
				{
                    cout << "Cyclic Linked List does not exist!" << endl;
                    return;
                }
				cll->push_back(data);
            }
            else if (prev[0] == 2)
			{
                if (dll == nullptr)
				{
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
                if (prev[0] == 1)
				{
                    if (cll == nullptr)
					{
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cout << cll->pop_front() << " has been popped." << endl << endl;
                }
				else if (prev[0] == 2)
				{
                    if (dll == nullptr)
					{
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					cout << dll->pop_front() << " has been popped." << endl << endl;
                }
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		}

		void removeErase (vector<int>& prev)
		{
			int count;
			Type data;
			cout << "Value to erase: ";

			try
			{
				cin >> data;
			}

			catch (...)
			{
				cout << "Error reading input! Try again." << endl << endl;
				return;
			}
			try
			{
				if (prev[0] == 1)
				{
                    if (cll == nullptr)
					{
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					count = cll->erase(data);
				}
				else if (prev[0] == 2)
				{
                    if (dll == nullptr)
					{
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
			}
			catch (const underflow_error& e)
			{
				cout<< e.what() << endl;
				return;
			}
			cout << "Deleted " << count << " nodes from list." << endl << endl;
		}

		void accessSize (vector<int>& prev)
		{
			try
			{
                if (prev[0] == 1)
				{
                    if (cll == nullptr)
					{
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cout << "Size is " << cll->getSize() << "." << endl << endl;
                }
				else if (prev[0] == 2)
				{
                    if (dll == nullptr)
					{
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					cout << "Size is " << dll->getSize() << "." << endl << endl;
                }
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		}

		void accessEmpty(vector<int>& prev)
		{
            if (prev[0] == 1)
			{
                if (cll == nullptr)
				{
                    cout << "Cyclic Linked List does not exist!" << endl;
                    return;
                }
				cout << "The list " << (cll->empty() ? "is" : "is not") << " empty." << endl << endl;
            }
			else if (prev[0] == 2)
			{
                if (dll == nullptr)
				{
                    cout << "Doubly Linked List does not exist!" << endl;
                    return;
                }
				cout << "The list " << (dll->empty() ? "is" : "is not") << " empty." << endl << endl;
            }
		}

		void accessFront(vector<int>& prev)
		{
			try
			{
                if (prev[0] == 1)
				{
                    if (cll == nullptr)
					{
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cout << "Front is " << cll->front() << endl << endl;
                }
				else if (prev[0] == 2)
				{
                    if (dll == nullptr)
					{
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					cout << "Front is " << dll->front() << endl << endl;
                }
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		}

		void accessBack (vector<int>& prev)
		{
			try
			{
                if (prev[0] == 1)
				{
                    if (cll == nullptr)
					{
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cout << "Back is " << cll->back() << endl << endl;
                }
				else if (prev[0] == 2)
				{
                    if (dll == nullptr)
					{
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					cout << "Back is " << cll->back() << endl << endl;
                }
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		}

		void accessCount(vector<int>& prev)
		{
			Type data;
			cout << "Value to count: ";

			try
			{
				cin >> data;
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}

			try
			{
                if (prev[0] == 1)
				{
                    if (cll == nullptr)
					{
                        cout << "Cyclic Linked List does not exist!" << endl;
                        return;
                    }
					cout << endl << "Counted " << cll->count(data) << " instances of \"" << data << "\"." << endl << endl;
                }
				else if (prev[0] == 2)
				{
                    if (dll == nullptr)
					{
                        cout << "Doubly Linked List does not exist!" << endl;
                        return;
                    }
					cout << endl << "Counted " << dll->count(data) << " instances of \"" << data << "\"." << endl << endl;
                }
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
				return;
			}
		}

		void outputCyclic (vector<int>& prev)
		{
            if (cll == nullptr)
			{
                cout << "Cyclic Linked List does not exist!" << endl;
                return;
            }
			try
			{
				cll->print();
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		}

		void outputDoubly (vector<int>& prev)
		{
            if (dll == nullptr)
			{
                cout << "Doubly Linked List does not exist!" << endl;
                return;
            }
			try
			{
				dll->print();
			}
			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		}
				

	public: 
		LinkedListDemo() : cll(nullptr), dll(nullptr) {}
		void run()
		{
			buildMenus();
			mainMenu->run();
		}

};
