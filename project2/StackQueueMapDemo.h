#include <iostream>
#include <string>
#include "MenuList.h"

template <class Type>
class StackQueueMapDemo { 
	private:
		//DynMap<K,V> * map;
		void * map;
		//DynStack<Type> * stack;
		void * stack;
		//DynQueue<Type> * queue;
		void * queue;

		MenuList * mainMenu;

		void buildMenus();

		// Menu Functions


