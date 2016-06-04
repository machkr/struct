#pragma once
#include <iostream>
#include "SingleNode.h"
using namespace std;

template<class Type> class CyclicLinkedList : public LinkedList
{
private:


public:

	CyclicLinkedList() : head(nullptr), tail(nullptr), size(0) {}

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

		SingleNode<Type> *current = head;
		SingleNode<Type> *previous = head;
		int count = 0;
		if (this->isEmpty()) {
			throw underflow_error("The list is empty.");
		}
		else {
			while (current->next != head) {
				if (current->data == wrecked) {
					if (current == head) {
						head = head->next;
						delete previous;
						size--;
						count++;
					}
					else {
						SingleNode<Type> *temp = current->next;
						current->data = current->next->data;
						current->next = current->next->next;
						delete temp;
						size--;
						count++;
					}
				}
				previous = current;
				current = current->next;
			}
			if (current->data == wrecked) {
				previous->next = nullptr;
				delete current;
				size--;
				count++;
			}
		}
		cout << "Number of nodes deleted:";
		return count;
	}


	~CyclicLinkedList() {

		SingleNode<Type> *current = head;
		SingleNode<Type> *previous = head;
		if (this->isEmpty()) {
			throw underflow_error("The list is empty.");
		}
		else {
			while (current->next != nullptr) {
				if (current == head) {
					head = head->next;
					delete previous;
					size--;
				}
			}
		}
	}

};
