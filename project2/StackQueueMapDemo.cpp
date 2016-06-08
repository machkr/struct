#define action(f) bind(static_cast<void (StackQueueMapDemo::*)(vector<int>&)> (&StackQueueMapDemo::f) ,this,_1)
#include "StackQueueMapDemo.h"

using namespace std;

void StackQueueMapDemo::buildMenus() {

	// Initialize menus
	mainMenu = new MenuList("Please choose a container.");
	MenuList * stackMenu = new MenuList("Please choose an action.");
	MenuList * qMenu = new MenuList("Please choose an action.");
	MenuList * mapMenu = new MenuList("Please choose an action.");

	// Main Menu
	mainMenu->setIsMain(true);
	mainMenu->add("Stack", MenuList::SubMenu(stackMenu));
	mainMenu->add("Queue", MenuList::SubMenu(qMenu));
	mainMenu->add("Hash Table", MenuList::SubMenu(mapMenu));

	// Stack Menu
	stackMenu->add("Push", action(stackPush));
	stackMenu->add("Pop", action(stackPop));
	stackMenu->add("Top", action(stackTop));
	stackMenu->add("Display", action(display));
	stackMenu->add("Show Is Empty?", action(empty));
	stackMenu->add("Show Size", action(size));
	stackMenu->add("Show Capacity", action(capacity));
	stackMenu->add("Clear Stack", action(clear));
	stackMenu->add("Erase Value", action(erase));
	
	// Queue Menu
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

	// Hash Map Menu
	mapMenu->add("Display", action(display));
	mapMenu->add("Show Is Empty?", action(empty));
	mapMenu->add("Show Size", action(size));
	mapMenu->add("Show Capacity", action(capacity));
	mapMenu->add("Clear Hash Table", action(clear));
	mapMenu->add("Erase Value", action(erase));

}

int main() {
	StackQueueMapDemo demo;
	demo.run();
	return 0;
}
