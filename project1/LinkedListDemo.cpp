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
	mainMenu->add("Create List", MenuList::SubMenu(createMenu), true);
	mainMenu->add("Insert Node", MenuList::SubMenu(insertMenu), true);
	mainMenu->add("Remove Node", MenuList::SubMenu(removeMenu), true);
	mainMenu->add("Access List", MenuList::SubMenu(accessMenu), true);
	mainMenu->add("Output List", MenuList::SubMenu(outputMenu), true);

	createMenu->add("Cyclic Linked List", action(createCyclic), false); 
	createMenu->add("Doubly Linked List", action(createDoubly), false);

	insertMenu->add("Cyclic Linked List", MenuList::SubMenu(insertMethodMenu), true);
	insertMenu->add("Doubly Linked List", MenuList::SubMenu(insertMethodMenu), true);

	insertMethodMenu->add("Push Front", action(insertPushFront), false);
	insertMethodMenu->add("Push Back", action(insertPushBack), false);

	removeMenu->add("Cyclic Linked List", MenuList::SubMenu(removeMethodMenu), true);
	removeMenu->add("Doubly Linked List", MenuList::SubMenu(removeMethodMenu), true);

	removeMethodMenu->add("Pop Front", action(removePopFront), false);
	removeMethodMenu->add("Erase", action(removeErase), false);
	
	accessMenu->add("Cyclic Linked List", MenuList::SubMenu(accessMethodMenu), true);
	accessMenu->add("Doubly Linked List", MenuList::SubMenu(accessMethodMenu), true);

	accessMethodMenu->add("Size", action(accessSize), false);
	accessMethodMenu->add("Empty", action(accessEmpty), false);
	accessMethodMenu->add("Front", action(accessFront), false);
	accessMethodMenu->add("Back", action(accessBack), false);
	accessMethodMenu->add("Count", action(accessCount), false);

	outputMenu->add("Cyclic Linked List", action(outputCyclic), false);
	outputMenu->add("Doubly Linked List", action(outputDoubly), false);

}

int main() {
	LinkedListDemo demo;
	demo.run();
	return 0;
}


