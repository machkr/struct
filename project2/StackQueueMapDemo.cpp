#define action(f) bind(static_cast<void (StackQueueMapDemo::*)(vector<int>&)> (&StackQueueMapDemo::f) ,this,_1)
#include "StackQueueMapDemo.h"

using namespace std;

void StackQueueMapDemo::buildMenus()
{
	// Initialize menus
	mainMenu = new MenuList("Please choose a container.");
	stackMenu = new MenuList("Please choose an action for: Stack");
	qMenu = new MenuList("Please choose an action for: Queue");
	mapMenu = new MenuList("Please choose an action: Hash Table");

	// Main Menu
	mainMenu->setIsMain(true);
	mainMenu->add("Stack", MenuList::SubMenu(stackMenu), true);
	mainMenu->add("Queue", MenuList::SubMenu(qMenu), true);
	mainMenu->add("Hash Table", MenuList::SubMenu(mapMenu), true);

	// Stack Menu
	stackMenu->add("Create Stack", action(createStack));
	
	// Queue Menu
	qMenu->add("Create Queue", action(createQueue));

	// Hash Map Menu
	mapMenu->add("Create Hash Table", action(createMap));
}

void StackQueueMapDemo::createStack(vector<int>& prev)
{
	/*
	 *  Create Stack Here
	 */

	stackMenu->remove("Create Stack");
	stackMenu->add("Push", action(stackPush));
	stackMenu->add("Pop", action(stackPop));
	stackMenu->add("Top", action(stackTop));
	stackMenu->add("Display", action(display));
	stackMenu->add("Show Is Empty?", action(empty));
	stackMenu->add("Show Size", action(size));
	stackMenu->add("Show Capacity", action(capacity));
	stackMenu->add("Clear Stack", action(clear));
	stackMenu->add("Erase Value", action(erase));

}

void StackQueueMapDemo::createQueue(vector<int>& prev)
{
	/*
	 *  Create Queue Here
	 */
	
	qMenu->remove("Create Queue");
	qMenu->add("Enq Value", action(qEnqueue));
	qMenu->add("Deq Value", action(qDequeue));
	qMenu->add("Front", action(qFront));
	qMenu->add("Back", action(qBack));
	qMenu->add("Display", action(display));
	qMenu->add("Show Is Empty?", action(empty));
	qMenu->add("Show Size", action(size));
	qMenu->add("Show Capacity", action(capacity));
	qMenu->add("Clear Queue", action(clear));
	qMenu->add("Erase Value", action(erase));

}

void StackQueueMapDemo::createMap(vector<int>& prev)
{
	/*
	 *  Create Map Here
	 */

	mapMenu->remove("Create Hash Table");	
	mapMenu->add("Insert", action(mapInsert));
	mapMenu->add("Search", action(mapSearch));
	mapMenu->add("Delete", action(mapDelete));
	mapMenu->add("Display", action(display));
	mapMenu->add("Show Is Empty?", action(empty));
	mapMenu->add("Show Size", action(size));
	mapMenu->add("Show Capacity", action(capacity));
	mapMenu->add("Clear Hash Table", action(clear));
}

int main()
{
	StackQueueMapDemo demo;
	demo.run();
	return 0;
}
