#pragma once
#include <iostream>
#include "DoubleNode.h"
#include "LinkedList.h"
using namespace std;

template<class Type> class DoublyLinkedList
{
private:
	DoubleNode<Type> * head;
	DoubleNode<Type> * tail;
	int size;

	/*DoubleNode<Type> *head;
	DoubleNode<Type> *tail;
	int size;*/

public:
	//DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {};

	int getSize() const
	{ 
		return size;
	}

	// Returns true if list is empty. False otherwise. 
	bool empty() const
	{								
		return head == nullptr;
	}
    
	// Retrieves object stored in the node pointed to by the head pointer. 
	// Throws an underflow if list is empty. 
	Type front() const
	{			        
		if (empty()) throw underflow_error("List is empty.");
        return head->getData();
	}
	
	// Retrieves object stored in the node pointed to by the tail pointer. 
	// Throws an underflow if list is empty. 
	Type back() const
	{		
		if (empty()) throw underflow_error("List is empty.");
		return tail->getData();
	}

	int count(Type const &toCount) const
	{
		int count = 0;
		DoubleNode<Type> *curNode;
		DoubleNode<Type> *nextNode;

		curNode = nextNode = head;

		while (nextNode != nullptr)
		{
			curNode = nextNode;
			nextNode = curNode->next;

			if (curNode->data == toCount)
			{
				count++;
			}
		}
		return count;
	}

	void push_front(Type const &newFront)
	{
		DoubleNode<Type> *newNode = new DoubleNode<Type>(newFront, nullptr, head);
		if (size == 0)
		{
			tail = newNode;
			head = newNode;
		} else { 
			head->previous = newNode;
			head = newNode;
		}
		size++;
	}

	void push_back(Type const &newBack)
	{
		DoubleNode<Type> *newNode = new DoubleNode<Type>(newBack, tail, nullptr);
		if (size == 0)
		{
			head = newNode;
			tail = newNode;
		} else { 
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}

	Type pop_front()
	{
		if (empty()) throw underflow_error("List is empty.");

		Type data;
		DoubleNode<Type> *popNode = head;
		head = popNode->next;

		if (head == nullptr)
		{
			tail = nullptr;
		}

		head->previous = nullptr;
		data = popNode->data;
		delete popNode;
		size--;
		return data;
	}

	int erase(Type const &toDelete)
	{
		DoubleNode<Type> *curNode = head->next;
		DoubleNode<Type> *nextNode;
		int count = 0;

		while (curNode != nullptr)
		{
			nextNode = curNode->next;
			if (curNode->data == toDelete)
			{
				curNode->previous->next = curNode->next;
				curNode->next->previous = curNode->previous;
				delete curNode;
				count++;
				size--;
			}
			curNode = nextNode;
		}
		return count;
	}

	void print()
	{
		DoubleNode<Type> *curNode = this->head;

		if (this->size == 0)
		{
			throw underflow_error("List is empty.");
			return;
		}

		do
		{
			cout << curNode->data << " ";
			curNode = curNode->next;
		} while (curNode != nullptr);

		cout << endl << endl;
	}

	~DoublyLinkedList()
	{
		if (empty()) throw underflow_error("The list is empty.");

		DoubleNode<Type> *current = head;

		while (current->next != nullptr)
		{
			delete current->previous;
			size--;
		}

		head = nullptr;
		tail = nullptr;
	}

};
