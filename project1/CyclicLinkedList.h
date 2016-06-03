#pragma once
#include <iostream>
#include "SingleNode.h"
using namespace std;

template<class Type> class CyclicLinkedList : public LinkedList
{
private:
	Node<Type> * head;
	Node<Type> * tail;
	int size;

public:
	CyclicLinkedList(): head(nullptr), tail(nullptr), size(0){}

	//Accessors begin

	int size() const { //Returns Number of items in the list.
		//return this->size
	}
	bool empty() const {								//Returns true if list is empty. False otherwise. 
		//return head == nullptr;
	}
	
	Type front() const {			//Retrieves object stored in the node pointed to by the head pointer. Throws an underflow if list is empty. 
		//if (empty == true);
	}
	
	Type back() const {				//Retrieves object stored in the node pointed to by the tail pointer. Throws an underflow if list is empty. 
		//if (empty == true);
	}

	SingleNode<Type> *head() const {			//Returns Head Pointer
		//return head;
	}

	SingleNode<Type> *tail() const {			//Returns Tail Pointer
		//return tail;
	}
	
	int count(Type const & list) const {			//Returns number of nodes in the linked list storing a value equal to the argument
		//if(data == data){}
	}

	//Mutators begin

	void push_front(Type const & newFront) {			//Creates a new SingleNode<Type> storing the argument, next pointer set to current head. Head is then set to the argument node. If list is initially empty, tail pointr is set to point to new node.

	}

	void push_back(Type const & newBack) {               //Places new node at the back of the list. Find the tail, and point tail's next to new node. 

	}

	Type pop_front()								//Delete the node(s) at the front of the linked list and, as necessary, update the head and tail pointers. Return object stored in node being popped. Throw an underflow exception if list is empty.
	{
		//if(empty == true){}
	}

	int erase(Type const & wrecked) {         //Deletes the node(s) (from the front) in the linked list that contains the element equal to the argument (use == to test). As necessary, update the head, tail, and next of all applicable nodes in list. Return number of nodes that were deleted. 

		//return size;
	}

	//Desktop Test 2

	~CyclicLinkedList() {}; //Must delete all nodes in the linked list when called!!!!! DON'T FORGET BOYOS!!!!
};
