#include "MenuList.h"

MenuList::MenuList(const string& title_, bool main_) : 
	main(main_),
	size(0),
	title(title_) {};

void MenuList::addOption(string text_) {
	options.push_back({text_, nullptr});
}

void MenuList::addOption(string text_, MenuFunction f_) {
	options.push_back({text_, f_});
}

void MenuList::run() {
	while(1) {
		// Display options
		vector<Option>::iterator it;
		cout << endl << title << endl;
		int i = 1;
		for (it=options.begin(); it < options.end(); i++, it++) {
			cout << i << ". " << (*it).text << endl;
		}
		if (main) cout << i << ". Quit";
		else cout << i << ". Back";
		cout << endl << "> ";

		// Get choice
		string choiceStr;
		cin >> choiceStr;

		cout << endl;

		// Check that choice is valid
		int choice;
		try {
			choice = stoi(choiceStr);
		} catch (...) {
			cout << "Invalid choice. Try again." << endl;
			continue;
		}
		if (choice < 1 || choice > i) {
			cout << "Invalid choice. Try again." << endl;
			continue;
		}

		// Back / Quit
		if (choice == i) return;

		// Call f chosen by menu
		vector<int> allChoices(previousChoices);
		allChoices.insert(allChoices.begin(), choice);
		options[choice-1].f(allChoices);
		 
	}

}

void MenuList::run(vector<int>& previousChoices_) {
	previousChoices = previousChoices_;
	run();
}

int MenuList::getSize() {
	return size;
}

void MenuList::setIsMain(bool b) {
	main = b;
}

bool MenuList::getIsMain() const {
	return main;
}

