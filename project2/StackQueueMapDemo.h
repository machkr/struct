#include <iostream>
#include <string>
#include "DynStack.h"
#include "DynQueue.h"
#include "MenuList.h"

template<typename type>

class StackQueueMapDemo
{ 
	private:
		//DynMap<K,V> *map;
		void *map;
		DynStack<type> *stack;
		//void *stack;
		//DynQueue<string> *queue;
		void *queue;

		MenuList *mainMenu;
		MenuList *stackMenu;
		MenuList *qMenu;
		MenuList *mapMenu;

		void buildMenus();

		/********************
		 *  Menu Functions  *
		 ********************/

		// Create Functions
		void createStack(vector<int> &prev);
		void createQueue(vector<int> &prev);
		void createMap(vector<int> &prev);

		// DynContainer 
		void size(vector<int> &prev)
		{
			cout << "The size is " << stack->size() << "." << endl << endl; 
		};

		void empty(vector<int> &prev)
		{
			cout << (stack->empty() ? "Yes." : "No.") << endl << endl;
		};

		void capacity(vector<int> &prev)
		{
			cout << "The capacity is " << stack->capacity() << "." << endl << endl;
		};

		void display(vector<int> &prev)
		{
			try
			{
				stack->display();
			}

			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		};

		void clear(vector<int> &prev)
		{
			try
			{
				stack->clear();
			}

			catch (const underflow_error& e)
			{
				cout << e.what() << endl;
			}
		};

		// DynStack
		void stackTop(vector<int> &prev)
		{
			cout << "The top of the stack is \"" << stack->top() << "\"." << endl << endl;
		};

		void stackPush(vector<int> &prev)
		{
			type data;
			cout << "Data to push: ";

			try
			{
				cin >> data;
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}

			cout << "Attempting to push \"" << data << "\"..." << endl;
			stack->push(data);
			cout << "\"" << data << "\" has been pushed successfully." << endl << endl;
		};

		void stackPop(vector<int> &prev)
		{
			cout << "Attempting to pop the stack..." << endl;
			cout << "The stack has been popped successfully (Removed \"" << stack->pop() << "\")." << endl << endl;
		};

		// Dyn Queue
		void qFront(vector<int> &prev)
		{
		
		};

		void qBack(vector<int> &prev)
		{
		
		};

		void qEnqueue(vector<int> &prev)
		{
		
		};
		void qDequeue(vector<int> &prev)
		{
		
		};
		
		// Stack and Queue
		void erase(vector<int> &prev)
		{
			type data;
			cout << "Data to erase: ";

			try
			{
				cin >> data;
			}

			catch (...)
			{
				cout << endl << "Error reading input! Try again." << endl << endl;
				return;
			}

			stack->erase(data);
		};

		// DynMap
		void mapInsert(vector<int> &prev)
		{
		
		};

		void mapSearch(vector<int> &prev)
		{
		
		};

		void mapDelete(vector<int> &prev)
		{
		
		};

	public:
		void run()
		{
			buildMenus();
			mainMenu->run();
		}
};
