#pragma once
#include <iostream>
#include "SingleNode.h"
using namespace std;

template<class Type> class LinkedList{
private:
	SingleNode<Type> * head;
	SingleNode<Type> * tail;
	int size;

public:
	LinkedList(): head(nullptr), tail(nullptr), size(0){}

	// Accessors begin

	// Returns Number of items in the list.
	int size() const { 
		return this->size
	}

	// Returns true if list is empty. False otherwise. 
	bool empty() const {								
		return head == nullptr;
	}
    
	// Retrieves object stored in the node pointed to by the head pointer. 
	// Throws an underflow if list is empty. 
	Type front() const {			        
		if (empty()) throw underflow_error("List is empty.");
        return head->getData();
	}
	
	// Retrieves object stored in the node pointed to by the tail pointer. 
	// Throws an underflow if list is empty. 
	Type back() const {		
		if (empty()) throw underflow_error("List is empty.");
		return tail->getData();
	}

	//Returns Head Pointer
	SingleNode<Type> *head() const {			
		return head;
	}

	//Returns Tail Pointer
	SingleNode<Type> *tail() const {			
		return tail;
	}

	//Returns number of nodes in the linked list storing a value equal to the argument
	int count(Type const & list) const {			
		int count = 0;
		SingleNode<Type> * curNode;
		SingleNode<Type> * nextNode;

		curNode = nextNode = nullptr;

		while (nextNode != nullptr) {
			curNode = nextNode;
			nextNode = curNode->next;
			
			if (curNode->data == toCount) {
				count++;
			}
		}	
		return count;
	}

	//Mutators begin

	// Creates a new SingleNode<Type> storing the argument, next pointer set to
	// current head. Head is then set to the argument node. If list is 
	// initially empty, tail pointr is set to point to new node.
	void push_front(Type const & newFront) {			
		SingleNode<Type> * newNode = new SingleNode<Type>(newFront, head);
		head = newNode;
		if (size == 0) {
			tail = newNode;
		}
		size++;
		return;
	}

	// Places new node at the back of the list. Find the tail, and point tail's
	// next to new node. 
	void push_back(Type const & newBack) {               

		SingleNode<Type> * newNode = new SingleNode<type>(newBack, nullptr);
		tail->next = newNode;
		size++;	
		return;
	}
	// Delete the node(s) at the front of the linked list and, as necessary, 
	// update the head and tail pointers. Return object stored in node being 
	// popped. Throw an underflow exception if list is empty.
	Type pop_front()								
	{
		if (empty()) throw underflow_error("List is empty.");
		Type data = head->data;
		delete head;
		size--;
		return data;
	}

	// Deletes the node(s) (from the front) in the linked list that contains the
	// element equal to the argument (use == to test). As necessary, update the
	// head, tail, and next of all applicable nodes in list. Return number of 
	// nodes that were deleted. 
	int erase(Type const & toDelete) {         
		int count = 0;
		SingleNode<Type> * curNode;
		SingleNode<Type> * nextNode;
		SingleNode<Type> * pastNode;

		curNode = nextNode = pastNode = head; 
		while (nextNode != nullptr) {
			pastNode = curNode;
			curNode = nextNode;
			nextNode = curNode->next;
			if (curNode->data == toDelete) {
				if (curNode == head) {
					head = nextNode;
				}
				if (curNode == tail) {
					// If theres only one node in the list, head = tail = nullptr
					if (curNode == head && curNode == tail) {
						head = tail = nullptr;
					} else {
						tail = pastNode;
					}
				}
				pastNode->next = nextNode;
				delete curNode;
				size--;
				count++;		
			}
		}
		return count;
	}

	//Desktop Test 2

	~LinkedList(); //Must delete all nodes in the linked list when called!!!!! DON'T FORGET BOYOS!!!!
};
