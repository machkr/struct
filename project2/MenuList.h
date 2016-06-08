#ifndef MENU_CLASS
#define MENU_CLASS

#include <iostream>
#include <vector>
#include <functional>
#include <string>

class LinkedListDemo;

using namespace std;
using namespace std::placeholders;

class MenuList;

// MenuFunction is basically a function pointer. It points to the function you 
// would like called when a menu option is selected.
typedef function<void(vector<int>&)> MenuFunction;

// Each MenuList has a vector of Options. Each option contains text, 
// e.g. "Create List" and a MenuFunction that is called when the option is selected
struct Option {
	string text;
	MenuFunction f;
	bool submenu;
};

class MenuList {
	private:
		vector<Option> options;

		// Each menu has a vector of choices that were selected in the higher menus
		vector<int> previousChoices;

		bool main;
		int size;
		string title;

	public:
		MenuList(const string& title_);

		// Add a menu option to the Menu
		void add(string text_);
		void add(string text_, MenuFunction f_);
		void add(string text_, MenuFunction f_, bool submenu_);

		// Remove a menu option
		void remove(string text_);

		// Run the menu. The overloaded run takes a vector of previous menu options
		// that were selected. e.g. If "1. Create List" was selected, the first node
		// will be a 1. This is how all submenus are called
		void run();
		void run(vector<int>& previousChoices_);

		// Boring old accessors
		string getTitle();
		int getSize();

		// You can designate a menu as the "main" menu. All it does is print the word 
		// "Quit" instead of "Back" as the last menu option
		void setIsMain(bool b);
		bool getIsMain() const;

		// Making non-static member function pointers is complicated, so these
		// static methods hopefully simplify that. 
		// They return the MenuFunction type defined above. SubMenu takes a SubMenu and 
		// is used for making the hierarchal menus work. Action will take any
		// regular function (non-member method). 
		static MenuFunction SubMenu(MenuList * menuList);
		static MenuFunction Action(void (*action_function)(vector<int>& previousChoices));
};

#endif
