#include "Menu.h"
#include <iostream>

using namespace std;

bool flag1 = false;
bool flag2 = false;

void create();
void insert();
void remove();
void output();

int main()
{
	int option = 0;
	bool flag = true;

	cout << ">>>>> Menu Program <<<<<" << endl;

	while (flag)
	{
		cout << endl << "Please select an option:" << endl;
		cout << "  1. Create List" << endl;
		cout << "  2. Insert Node" << endl;
		cout << "  3. Remove Node" << endl;
		cout << "  4. Output List" << endl;
		cout << "  5. Quit" << endl;
		cout << endl << "> ";

		cin >> option;

		switch (option)
		{
		case 1:	create();
			continue;

		case 2: insert();
			continue;

		case 3: remove();
			continue;

		case 4: output();
			continue;

		case 5:	break;

		default: cout << "Invalid option: please try again." << endl << endl;
			continue;
		}
	}
}

void create()
{
	int option;
	bool flag = true;

	while (flag)
	{
		cout << endl << "Please select the type of list to create:" << endl;
		cout << "  1. Cyclic Linked List" << endl;
		cout << "  2. Doubly Linked List" << endl;
		cout << "  3. Cancel" << endl;
		cout << endl << "> ";

		cin >> option;

		switch (option)
		{
			case 1:	if (flag1)
				{
					cout << endl << "You have already created a cyclic linked list." << endl;
					continue;
				}
				else
				{
					//code to create cyclic linked list
					cout << endl << "List created successfully." << endl;
					flag1 = true;
					break;
				}

			case 2: if (flag2)
				{
					cout << endl << "You have already created a doubly linked list." << endl;
					continue;
				}
				else
				{
					//code to create doubly linked list
					cout << endl << "List created successfully." << endl;
					flag2 = true;
					break;
				}

			case 3: break;

			default: cout << "Invalid option: please try again." << endl << endl;
				continue;
		}

		flag = false;
	}
}

void insert()
{
	int option;
	bool flag = true;
	bool subflag;

	while (flag)
	{
		cout << endl << "Please select the list to insert into:" << endl;
		cout << "  1. Cyclic Linked List" << endl;
		cout << "  2. Doubly Linked List" << endl;
		cout << "  3. Cancel" << endl;
		cout << endl << "> ";

		cin >> option;

		switch (option)
		{
		case 1:	if (flag1)
				{
					subflag = true;

					while (subflag)
					{
						cout << endl << "Please select the insertion method:" << endl;
						cout << "  1. Push Front" << endl;
						cout << "  2. Push Back" << endl;
						cout << "  3. Positional" << endl;
						cout << "  4. Cancel" << endl;
						cout << endl << "> ";

						cin >> option;

						switch (option)
						{
							case 1: //code to push front in cyclic linked list
								cout << endl << "Node inserted successfully." << endl;
								continue;

							case 2: //code to push back in cyclic linked list
								cout << endl << "Node inserted successfully." << endl;
								continue;

							case 3: //code to insert node positionally in cyclic linked list
								cout << endl << "Node inserted successfully." << endl;
								continue;

							case 4: break;

							default: cout << "Invalid option: please try again." << endl << endl;
								continue;
						}

						subflag = false;
					}

					break;
				}
				else
				{
					cout << endl << "You have not created a cyclic linked list." << endl;
					continue;
				}

		case 2: if (flag2)
				{
					//code to insert node into doubly linked list
					cout << endl << "Node inserted successfully." << endl;
					break;
				}
				else
				{
					cout << endl << "You have not created a doubly linked list." << endl;
					continue;
				}

		case 3: break;

		default: cout << "Invalid option: please try again." << endl << endl;
			continue;
		}
		flag = false;
	}
}

void remove()
{
	int option;
	bool flag = true;

	while (flag)
	{
		cout << endl << "Please select the list to remove from:" << endl;
		cout << "  1. Cyclic Linked List" << endl;
		cout << "  2. Doubly Linked List" << endl;
		cout << "  3. Cancel" << endl;
		cout << endl << "> ";

		cin >> option;

		switch (option)
		{
		case 1:	if (flag1)
		{
			//code to delete node from cyclic linked list
			cout << endl << "Node removed successfully." << endl;
			break;
		}
				else
				{
					cout << endl << "You have not created a cyclic linked list." << endl;
					continue;
				}

		case 2: if (flag2)
		{
			//code to insert node into doubly linked list
			cout << endl << "Node inserted successfully." << endl;
			break;
		}
				else
				{
					cout << endl << "You have not created a doubly linked list." << endl;
					continue;
				}

		case 3: break;

		default: cout << "Invalid option: please try again." << endl << endl;
			continue;
		}
		flag = false;
	}
}

void output()
{

}