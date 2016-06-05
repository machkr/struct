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

	void push_front(Type const & newFront)
	{
		SingleNode<Type> * newNode = new SingleNode<Type>(newFront, head);
		head = newNode;
		tail->next = head;
		if (size == 0)
		{
			head = newNode;
			tail = newNode;
		}
		size++;
		return;
	}

	void push_back(Type const & newBack)
	{
		SingleNode<Type> * newNode = new SingleNode<Type>(newBack, head);
		if (size == 0)
		{
			tail = newNode;
			head = newNode;
		}
		else
		{
			tail->next = newNode;
		}

		tail = newNode;
		size++;

		return;
	}

	Type pop_front()
	{
		if (empty()) throw underflow_error("List is empty.");
		Type data = head->data;
		SingleNode<Type> * temp = new SingleNode<Type>(head->next->data, head->next->next);
		delete head;
		head = temp;
		tail->next = head;
		size--;
		return data;
	}

	int count(Type const & comparedData) const
	{
		int count = 0;
		SingleNode<Type> * curNode;
		SingleNode<Type> * nextNode;

		curNode = nextNode = head;

		while (nextNode != head)
		{
			curNode = nextNode;
			nextNode = curNode->next;

			if (curNode->data == comparedData)
			{
				count++;
			}
		}
		return count;
	}

	void print()
	{
		SingleNode<Type> *curNode = head;

		cout << endl;
		while (curNode->next != head)
		{
			cout << curNode->data << " " << ;
			curNode = curNode->next;
		}
		cout << endl;
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
		cout << "Number of nodes deleted: " << count << endl;
		return count;
	}


	~CyclicLinkedList() {

		SingleNode<Type> *current = head;
		SingleNode<Type> *previous = head;
		if (this->isEmpty()) {
			throw underflow_error("The list is empty.");
		}
		else {
			while (current->next != head) {
				if (current == head) {
					head = head->next;
					delete previous;
					size--;
				}
			}
		}
	}

};
