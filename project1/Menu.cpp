#include "Menu.h"
#include <iostream>

using namespace std;

bool flag1 = false;
bool flag2 = false;

void create();
void insert();
void remove();
void access();
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
		cout << "  4. Access List" << endl;
		cout << "  5. Output List" << endl;
		cout << "  6. Quit" << endl;
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

		case 4: access();
			continue;

		case 5:	output();
			continue;

		case 6:	break;

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
							case 1: //code to push front in doubly linked list
								cout << endl << "Node inserted successfully." << endl;
								continue;

							case 2: //code to push back in doubly linked list
								cout << endl << "Node inserted successfully." << endl;
								continue;

							case 3: //code to insert node positionally in doubly linked list
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
	bool subflag;

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
					subflag = true;

					while (subflag)
					{
						cout << endl << "Please select the deletion method:" << endl;
						cout << "  1. Pop Front" << endl;
						cout << "  2. Erase" << endl;
						cout << "  3. Positional" << endl;
						cout << "  4. Cancel" << endl;
						cout << endl << "> ";

						cin >> option;

						switch (option)
						{
							case 1: //code to pop front in cyclic linked list
								cout << endl << "Node removed successfully." << endl;
								continue;

							case 2: //code to erase in cyclic linked list
								cout << endl << "Node(s) removed successfully." << endl;
								continue;

							case 3: //code to remove node positionally in cyclic linked list
								cout << endl << "Node removed successfully." << endl;
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
					subflag = true;

					while (subflag)
					{
						cout << endl << "Please select the deletion method:" << endl;
						cout << "  1. Pop Front" << endl;
						cout << "  2. Erase" << endl;
						cout << "  3. Positional" << endl;
						cout << "  4. Cancel" << endl;
						cout << endl << "> ";

						cin >> option;

						switch (option)
						{
						case 1: //code to pop front in doubly linked list
							cout << endl << "Node removed successfully." << endl;
							continue;

						case 2: //code to erase in doubly linked list
							cout << endl << "Node(s) removed successfully." << endl;
							continue;

						case 3: //code to remove node positionally in doubly linked list
							cout << endl << "Node removed successfully." << endl;
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

void access()
{
	int option;
	bool flag = true;
	bool subflag;

	while (flag)
	{
		cout << endl << "Please select the list to access:" << endl;
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
				cout << endl << "Please select the accessor method:" << endl;
				cout << "  1. Size" << endl;
				cout << "  2. Empty" << endl;
				cout << "  3. Front" << endl;
				cout << "  4. Back" << endl;
				cout << "  5. Count" << endl;
				cout << "  6. Cancel" << endl;
				cout << endl << "> ";

				cin >> option;

				switch (option)
				{
				case 1: //code to access the size of cyclic linked list
					cout << endl << "Size accessed successfully." << endl;
					continue;

				case 2: //code to access empty of cyclic linked list
					cout << endl << "Empty accessed successfully." << endl;
					continue;

				case 3: //code to access front of cyclic linked list
					cout << endl << "Front accessed successfully." << endl;
					continue;

				case 4: //code to access back of cyclic linked list
					cout << endl << "Back accessed successfully." << endl;
					continue;

				case 5: //code to access count of cyclic linked list
					cout << endl << "Count accessed successfully." << endl;
					continue;

				case 6: break;

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
			subflag = true;

			while (subflag)
			{
				cout << endl << "Please select the accessor method:" << endl;
				cout << "  1. Size" << endl;
				cout << "  2. Empty" << endl;
				cout << "  3. Front" << endl;
				cout << "  4. Back" << endl;
				cout << "  5. Count" << endl;
				cout << "  6. Cancel" << endl;
				cout << endl << "> ";

				cin >> option;

				switch (option)
				{
				case 1: //code to access the size of doubly linked list
					cout << endl << "Size accessed successfully." << endl;
					continue;

				case 2: //code to access empty of doubly linked list
					cout << endl << "Empty accessed successfully." << endl;
					continue;

				case 3: //code to access front of doubly linked list
					cout << endl << "Front accessed successfully." << endl;
					continue;

				case 4: //code to access back of doubly linked list
					cout << endl << "Back accessed successfully." << endl;
					continue;

				case 5: //code to access count of doubly linked list
					cout << endl << "Count accessed successfully." << endl;
					continue;

				case 6: break;

				default: cout << "Invalid option: please try again." << endl << endl;
					continue;
				}

				subflag = false;
			}

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
	int option;
	bool flag = true;

	while (flag)
	{
		cout << endl << "Please select the list to print:" << endl;
		cout << "  1. Cyclic Linked List" << endl;
		cout << "  2. Doubly Linked List" << endl;
		cout << "  3. Cancel" << endl;
		cout << endl << "> ";

		cin >> option;

		switch (option)
		{
		case 1:	if (flag1)
				{
					//code to print cyclic linked list
					break;
				}
				else
				{
					cout << endl << "You have not created a cyclic linked list." << endl;
					continue;
				}

		case 2: if (flag2)
				{
					//code to print doubly linked list
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