#define action(f) bind(static_cast<void (StackQueueMapDemo::*)(vector<int>&)> (&StackQueueMapDemo::f) ,this,_1)
#include "StackQueueMapDemo.h"

using namespace std;

void StackQueueMapDemo::buildMenus()
{
	// Initialize menus
	mainMenu = new MenuList("Please choose a container:");
	stackMenu = new MenuList("Please choose an action for the stack:");
	qMenu = new MenuList("Please choose an action for the queue:");
	mapMenu = new MenuList("Please choose an action for the hash table:");

	// Main Menu
	mainMenu->setIsMain(true);
	mainMenu->add("Stack", MenuList::SubMenu(stackMenu), true);
	mainMenu->add("Queue", MenuList::SubMenu(qMenu), true);
	mainMenu->add("Hash Table", MenuList::SubMenu(mapMenu), true);

	// Stack Menu
	stackMenu->add("Create Stack", action(createStack));
	
	// Queue Menu
	qMenu->add("Create Queue", action(createQueue));

	// Hash Map Menu
	mapMenu->add("Create Hash Table", action(createMap));
}

void StackQueueMapDemo::createStack(vector<int>& prev)
{
	int size;
	cout << "Please enter the size: ";
	cin >> size;
	cin.ignore();

	stack = new DynStack<string>(size);

	cout << "Stack created successfully." << endl << endl;

	stackMenu->remove("Create Stack");
	stackMenu->add("Push", action(stackPush));
	stackMenu->add("Pop", action(stackPop));
	stackMenu->add("Top", action(stackTop));
	stackMenu->add("Display", action(display));
	stackMenu->add("Show Is Empty?", action(empty));
	stackMenu->add("Show Size", action(size));
	stackMenu->add("Show Capacity", action(capacity));
	stackMenu->add("Clear Stack", action(clear));
	stackMenu->add("Erase Value", action(erase));

}

void StackQueueMapDemo::createQueue(vector<int>& prev)
{
	int size;
	cout << "Please enter the size of the queue: ";
	cin >> size;
	cin.ignore();

	queue = new DynQueue<string>(size);

	cout << "Queue created successfully." << endl << endl;
	
	qMenu->remove("Create Queue");
	qMenu->add("Enq Value", action(qEnqueue));
	qMenu->add("Deq Value", action(qDequeue));
	qMenu->add("Front", action(qFront));
	qMenu->add("Back", action(qBack));
	qMenu->add("Display", action(display));
	qMenu->add("Show Is Empty?", action(empty));
	qMenu->add("Show Size", action(size));
	qMenu->add("Show Capacity", action(capacity));
	qMenu->add("Clear Queue", action(clear));
	qMenu->add("Erase Value", action(erase));
}

void StackQueueMapDemo::createMap(vector<int>& prev)
{
	map = new DynMap<string,string>();

	mapMenu->remove("Create Hash Table");	
	mapMenu->add("Insert", action(mapInsert));
	mapMenu->add("Search", action(mapSearch));
	mapMenu->add("Delete", action(mapDelete));
	mapMenu->add("Display", action(display));
	mapMenu->add("Show Is Empty?", action(empty));
	mapMenu->add("Show Size", action(size));
	mapMenu->add("Show Capacity", action(capacity));
	mapMenu->add("Clear Hash Table", action(clear));
}


/***************
* DynContainer *
****************/

void StackQueueMapDemo::size(vector<int> &prev)
{
	cout << "(Size)" << endl;
	switch ( prev.back() ) 
	{
		
		case 1: // Stack
			cout << stack->size();
			break;

		case 2: // Queue
			cout << queue->size();
			break;

		case 3: // Map
			cout << map->size(); 
			break;
	}
	cout << endl << endl;
}

void StackQueueMapDemo::empty(vector<int> &prev)
{
	cout << "(Empty)" << endl;
	switch ( prev.back() ) 
	{
		
		case 1: // Stack
			cout << (stack->empty() ? "True." : "False.");
			break;

		
		case 2: // Queue
			cout << (queue->empty() ? "True." : "False.");
			break;

		
		case 3: // Map
			cout <<	(map->empty() ? "True." : "False.");
			break;
	}
	cout << endl << endl;
}

void StackQueueMapDemo::capacity(vector<int> &prev)
{
	cout << "(Capacity)" << endl;
	switch ( prev.back() ) 
	{	
		case 1: // Stack
			cout << stack->capacity();
			break;

		case 2: // Queue
			cout << queue->capacity();
			break;

		case 3: // Map
			cout << map->capacity();
			break;
	}
	cout << endl << endl;
}

void StackQueueMapDemo::display(vector<int> &prev)
{
	cout << "(Display)" << endl;
	switch ( prev.back() ) 
	{
		case 1: // Stack
			try
			{
				stack->display();
			}
			catch (const underflow_error& e)
			{
				cout << e.what();
			}
			break;

		case 2: // Queue
			try
			{
				queue->display();
			}
			catch (const underflow_error& e)
			{
				cout << e.what();
			}
			break;

		case 3: // Map
			try
			{
				map->display();
			}
			catch (const underflow_error& e)
			{
				cout << e.what();
			}
			break;
	}
}

void StackQueueMapDemo::clear(vector<int> &prev)
{
	cout << "(Clear)" << endl;
	switch ( prev.back() ) 
	{
		case 1: // Stack
			try
			{
				stack->clear();
			}
			catch (const underflow_error& e)
			{
				cout << e.what();
			}

			break;

		case 2: // Queue
			try
			{
				queue->clear();
			}
			catch (const underflow_error& e)
			{
				cout << e.what();
			}

			break;

		case 3: // Map
			map->clear();
			cout << "Hash Table cleared.";
			break;
	}

	cout << endl << endl;
}


/*********
 * Stack *
 *********/

void StackQueueMapDemo::stackTop(vector<int> &prev)
{
	cout << "(Top)" << endl;

	try
	{
		cout << "\"" << stack->top() << "\"" << endl << endl;
	}
	catch (const underflow_error& e)
	{
		cout << e.what() << endl << endl;
		return;
	}
}

void StackQueueMapDemo::stackPush(vector<int> &prev)
{
	string data;
	cout << "(Push)" << endl;
	cout << "Data: ";
	getline(cin, data);
	stack->push(data);
}

void StackQueueMapDemo::stackPop(vector<int> &prev)
{
	cout << "(Pop)" << endl;
	try
	{
		stack->pop();
	}
	catch (const underflow_error& e)
	{
		cout << e.what() << endl << endl;
		return;
	}
}


/*********
 * Queue *
 *********/

void StackQueueMapDemo::qFront(vector<int> &prev)
{
	cout << "(Front)" << endl;

	try
	{
		cout << "\"" << queue->front() << "\"" << endl << endl;
	}
	catch (const underflow_error& e)
	{
		cout << e.what() << endl << endl;
		return;
	}
}

void StackQueueMapDemo::qBack(vector<int> &prev)
{
	cout << "(Back)" << endl;

	try
	{
		cout << "\"" << queue->back() << "\"" << endl << endl;
	}
	catch (const underflow_error& e)
	{
		cout << e.what() << endl << endl;
		return;
	}
}

void StackQueueMapDemo::qEnqueue(vector<int> &prev)
{
	string data;
	cout << "(Enqueue)" << endl;
	cout << "Data: ";
	getline(cin, data);
	queue->enqueue(data);
}

void StackQueueMapDemo::qDequeue(vector<int> &prev)
{
	cout << "(Dequeue)" << endl;
	try
	{
		queue->dequeue();
	}
	catch (const underflow_error& e)
	{
		cout << e.what() << endl << endl;
		return;
	}
}


/*******************
 * Stack and Queue *
 *******************/

void StackQueueMapDemo::erase(vector<int> &prev)
{
	cout << "(Erase)" << endl << "Data: ";
	string data;
	getline(cin, data);

	switch (prev.back())
	{

	case 1: // Stack
		stack->erase(data);
		break;

	case 2: // Queue
		queue->erase(data);
		break;
	}
}


/**************
 * Hash Table *
 **************/

void StackQueueMapDemo::mapInsert(vector<int> &prev) 
{
	string key;
	string value;
	cout << "(Insert)\nKey: ";
	getline(cin,key);
	cout << "Value: ";
	getline(cin,value);
	map->insert(key,value);
	cout << endl;

}

void StackQueueMapDemo::mapSearch(vector<int> &prev) 
{
	string key;
	string value;
	cout << "(Search)\nKey: ";
	getline(cin,key);

	try
	{
		value = map->search(key);
	}
	catch (const underflow_error& e)
	{
		cout << e.what() << endl << endl;
		return;
	}

	cout << "Value: " << value << endl << endl;;
}

void StackQueueMapDemo::mapDelete(vector<int> &prev)
{
	string key;
	string value;
	cout << "(Delete)\nKey: ";
	getline(cin,key);

	try
	{
		map->del(key);
	}
	catch (const underflow_error& e)
	{
		cout << e.what();
		return;
	}

	cout << "Delete successful.";
	cout << endl << endl;
}