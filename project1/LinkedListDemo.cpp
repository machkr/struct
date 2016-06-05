// I couldn't figure out a way to define this function elsewhere 
#define action(f) bind(static_cast<void (LinkedListDemo::*)(vector<int>&)> (&LinkedListDemo::f) ,this,_1)

#include "LinkedListDemo.h"

void LinkedListDemo::buildMenus() {

	// Menu's must be initialized before they are passed to the SubMenu method
	mainMenu = new MenuList("Please select an option:");
	MenuList * createMenu = new MenuList("Please select the type of list to create:");
	MenuList * insertMenu = new MenuList("Please select the list to insert into:");
	MenuList * insertMethodMenu = new MenuList("Please select the insertion method:");
	MenuList * removeMenu = new MenuList("Please select the list to remove from:");
	MenuList * removeMethodMenu = new MenuList("Please select the deletion method:");
	MenuList * accessMenu = new MenuList("Please select the list to access:");
	MenuList * accessMethodMenu = new MenuList("Please select the accessor method:");
	MenuList * outputMenu = new MenuList("Please select the list to print:");

	//Add elements to the menus
	mainMenu->setIsMain(true);
	mainMenu->add("Create List", MenuList::SubMenu(createMenu));
	mainMenu->add("Insert Node", MenuList::SubMenu(insertMenu));
	mainMenu->add("Remove Node", MenuList::SubMenu(removeMenu));
	mainMenu->add("Access List", MenuList::SubMenu(accessMenu));
	mainMenu->add("Output List", MenuList::SubMenu(outputMenu));

	createMenu->add("Cyclic Linked List", action(createCyclic)); 
	createMenu->add("Doubly Linked List", action(createDoubly));

	insertMenu->add("Cyclic Linked List", MenuList::SubMenu(insertMethodMenu));
	insertMenu->add("Doubly Linked List", MenuList::SubMenu(insertMethodMenu));

	insertMethodMenu->add("Push Front", action(insertPushFront));
	insertMethodMenu->add("Push Back", action(insertPushBack));
	insertMethodMenu->add("Positional", action(insertPositional));

	removeMenu->add("Cyclic Linked List", MenuList::SubMenu(removeMethodMenu));
	removeMenu->add("Doubly Linked List", MenuList::SubMenu(removeMethodMenu));

	removeMethodMenu->add("Pop Front", action(removePopFront));
	removeMethodMenu->add("Erase", action(removeErase));
	removeMethodMenu->add("Positional", action(removePositional));
	
	accessMenu->add("Cyclic Linked List", MenuList::SubMenu(accessMethodMenu));
	accessMenu->add("Doubly Linked List", MenuList::SubMenu(accessMethodMenu));

	accessMethodMenu->add("Size", action(accessSize));
	accessMethodMenu->add("Empty", action(accessEmpty));
	accessMethodMenu->add("Front", action(accessFront));
	accessMethodMenu->add("Back", action(accessBack));
	accessMethodMenu->add("Count", action(accessCount));

	outputMenu->add("Cyclic Linked List", action(outputCyclic));
	outputMenu->add("Doubly Linked List", action(outputDoubly));

}

int main() {
	LinkedListDemo demo;
	demo.run();
	return 0;
}


