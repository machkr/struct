#ifndef MENU_CLASS
#define MENU_CLASS

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

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
		MenuList(const string& title_, bool main_);
		void addOption(string text_);
		void addOption(string text_, MenuFunction f_);
		void run();
		void run(vector<int>& previousChoices_);
		string getTitle();
		int getSize();
		void setIsMain(bool b);
		bool getIsMain() const;
};

#endif
