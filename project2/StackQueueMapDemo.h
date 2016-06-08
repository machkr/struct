#include <iostream>
#include <string>
#include "MenuList.h"

class StackQueueMapDemo { 
	private:
		//DynMap<K,V> * map;
		void * map;
		//DynStack<Type> * stack;
		void * stack;
		//DynQueue<Type> * queue;
		void * queue;

		MenuList * mainMenu;
		MenuList * stackMenu;
		MenuList * qMenu;
		MenuList * mapMenu;

		void buildMenus();

		/********************
		 *  Menu Functions  *
		 *******************/

		// Create Functions
		void createStack(vector<int>& prev);
		void createQueue(vector<int>& prev);
		void createMap(vector<int>& prev);

		// DynContainer 
		void size(vector<int>& prev) {};
		void empty(vector<int>& prev) {};
		void capacity(vector<int>& prev) {};
		void display(vector<int>& prev) {};
		void clear(vector<int>& prev) {};

		// DynStack
		void stackTop(vector<int>& prev) {};
		void stackPush(vector<int>& prev) {};
		void stackPop(vector<int>& prev) {};

		// Dyn Queue
		void qFront(vector<int>& prev) {};
		void qBack(vector<int>& prev) {};
		void qEnqueue(vector<int>& prev) {};
		void qDequeue(vector<int>& prev) {};
		
		// Stack and Queue
		void erase(vector<int>& prev) {};

		// DynMap
		void mapInsert(vector<int>& prev) {};
		void mapSearch(vector<int>& prev) {};
		void mapDelete(vector<int>& prev) {};

	public:
		void run() {
			buildMenus();
			mainMenu->run();
		}

};
