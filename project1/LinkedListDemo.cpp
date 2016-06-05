#include "LinkedListDemo.h"

void LinkedListDemo::buildMenus() {

	MenuList * createMenu;
	MenuList * insertMenu;
	MenuList * insertMethodMenu;
	MenuList * removeMenu;
	MenuList * removeMethodMenu;
	MenuList * accessMenu;
	MenuList * accessMethodMenu;
	MenuList * outputMenu;
	
	mainMenu = new MenuList("Please select an option:");
	mainMenu->setIsMain(true);
	mainMenu->add("Create List", MenuList::SubMenu(createMenu));
	mainMenu->add("Insert Node", MenuList::SubMenu(insertMenu));
	mainMenu->add("Remove Node", MenuList::SubMenu(removeMenu));
	mainMenu->add("Access List", MenuList::SubMenu(accessMenu));
	mainMenu->add("Output List", MenuList::SubMenu(outputMenu));

	createMenu = new MenuList("Please select the type of list to create:");
	createMenu->add("Cyclic Linked List");
	createMenu->add("Doubly Linked List");

	insertMenu = new MenuList("Please select the list to insert into:");
	insertMenu->add("Cyclic Linked List");
	insertMenu->add("Doubly Linked List");

	insertMethodMenu = new MenuList("Please select the insertion method:");
	insertMethodMenu->add("Push Front");
	insertMethodMenu->add("Push Back");
	insertMethodMenu->add("Positional");

	removeMenu = new MenuList("Please select the list to remove from:");
	removeMenu->add("Cyclic Linked List", MenuList::SubMenu(removeMethodMenu));
	removeMenu->add("Doubly Linked List", MenuList::SubMenu(removeMethodMenu));

	removeMethodMenu = new MenuList("Please select the deletion method:");
	removeMethodMenu->add("Pop Front");
	removeMethodMenu->add("Erase");
	removeMethodMenu->add("Positional");
	
	accessMenu = new MenuList("Please select the list to access:");
	accessMenu->add("Cyclic Linked List", MenuList::SubMenu(accessMethodMenu));
	accessMenu->add("Doubly Linked List", MenuList::SubMenu(accessMethodMenu));

	accessMethodMenu = new MenuList("Please select the accessor method:");
	accessMethodMenu->add("Size");
	accessMethodMenu->add("Empty");
	accessMethodMenu->add("Front");
	accessMethodMenu->add("Back");
	accessMethodMenu->add("Count");

	outputMenu = new MenuList("Please select the list to print:");
	outputMenu->add("Cyclic Linked List");
	outputMenu->add("Doubly Linked List");

}
	 
void LinkedListDemo::run() {
	buildMenus();
	mainMenu->run();
}

int main() {
	LinkedListDemo demo;
	demo.run();
	return 0;
}


