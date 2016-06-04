#include "MenuList.h"
#include <iostream>

using namespace std;
using namespace std::placeholders;

void PrintStuff(vector<int>& prevChoices) {
	cout << "HI THERE\n";
}

int main() {
	MenuList * mainMenu = new MenuList("Main Menu", true);
	MenuList * subMenu = new MenuList("Sub Menu", false);
	MenuFunction runPrintStuff = bind(&PrintStuff, _1); 
	subMenu->addOption("Print Stuff", runPrintStuff);
	MenuFunction runSubMenu = bind(static_cast<void(MenuList::*)(vector<int>&)> (&MenuList::run), subMenu, _1);
	mainMenu->addOption("Sub Menu", runSubMenu);
	mainMenu->run();
	return 0;
}
