#ifndef MENU_CLASS
#define MENU_CLASS

#include <iostream>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

class MenuList;

//typedef void (*MenuFunction)(vector<int>&);
typedef function<void(vector<int>&)> MenuFunction;

struct Option {
	string text;
	MenuFunction f;
};

class MenuList {
	private:
		vector<Option> options;
		vector<int> previousChoices;
		bool main;
		string title;
		int size;
	public:
		MenuList(const string& title_);
		void add(string text_);
		void add(string text_, MenuFunction f_);
		void run();
		void run(vector<int>& previousChoices_);
		string getTitle();
		int getSize();
		void setIsMain(bool b);
		bool getIsMain() const;

		static MenuFunction SubMenu(MenuList * menuList);
		static MenuFunction Action(void (*action_function)(vector<int>& previousChoices));
};

#endif
