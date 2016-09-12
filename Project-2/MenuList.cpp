#include "MenuList.h"

MenuList::MenuList(const string& title_) : main(false), size(0), title(title_) {};

void MenuList::add(string text_)
{
	options.push_back({text_, nullptr, false});
}

void MenuList::add(string text_, MenuFunction f_)
{
	options.push_back({text_, f_, false});
}

void MenuList::add(string text_, MenuFunction f_, bool submenu_)
{
	options.push_back({text_, f_, submenu_});
}

void MenuList::remove(string text_)
{
	vector<Option>::iterator it;
	for (it = options.begin(); it < options.end(); it++)
	{
		if (it->text == text_)
		{
			options.erase(it);
			break;
		}
	}
}

void MenuList::run()
{
	while(1)
	{
		// Display options
		vector<Option>::iterator it;
		cout << title << endl;
		int i = 1;
		for (it=options.begin(); it < options.end(); i++, it++)
		{
			cout << i << ". " << (*it).text << endl;
		}
		if (main) cout << 0 << ". Quit";
		else cout << 0 << ". Back";
		cout << endl << "> ";

		// Get choice
		string choiceStr;
		cin >> choiceStr;
		cin.ignore();

		cout << endl;

		// Check that choice is valid
		int choice;
		try
		{
			choice = stoi(choiceStr);
		} catch (...)
		{
			cout << "Invalid choice. Try again." << endl;
			continue;
		}
		if (choice < 0 || choice >= i)
		{
			cout << "Invalid choice. Try again." << endl;
			continue;
		}

		// Back / Quit
		if (choice == 0) return;

		// Create copy of choice history to pass to function
		vector<int> allChoices(previousChoices);
		if (options[choice-1].submenu)
		{
			allChoices.insert(allChoices.begin(), choice);
		}

		// If function defined, call function for menu choice
		if (options[choice-1].f == nullptr)
		{
			continue;
		}
		options[choice-1].f(allChoices);
		 
	}
}

void MenuList::run(vector<int>& previousChoices_)
{
	previousChoices = previousChoices_;
	run();
}

string MenuList::getTitle()
{
	return title;
}

int MenuList::getSize()
{
	return size;
}

void MenuList::setIsMain(bool b)
{
	main = b;
}

bool MenuList::getIsMain() const
{
	return main;
}

MenuFunction MenuList::SubMenu(MenuList * menuList)
{
	return bind(static_cast<void(MenuList::*)(vector<int>&)> (&MenuList::run), menuList, _1);
}

MenuFunction MenuList::Action(void (*action_function)(vector<int>& previousChoices))
{
	return bind(action_function, _1);
}

/*MenuFunction MenuList::Action( void (LinkedListDemo::*)(vector<int>&), LinkedListDemo * obj) {
	return bind(action_function, obj, _1);
}*/

