#pragma once
#include <iostream>
#include "DoubleNode.h"
#include "LinkedList.h"
using namespace std;

template<class Type> class DoublyLinkedList : public LinkedList<Type>
{
private:

public:
	//DoublyLinkedList() : this->head(nullptr), this->tail(nullptr), this->size(0) {};

	int count(Type const &toCount) const
	{
		int count = 0;
		DoubleNode<Type> *curNode;
		DoubleNode<Type> *nextNode;

		curNode = nextNode = this->head;

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
		DoubleNode<Type> *newNode = new DoubleNode<Type>(newFront, nullptr, this->head);

		this->head->previous = newNode;
		this->head = newNode;

		if (this->this->size == 0)
		{
			this->tail = newNode;
		}
		this->this->size++;
	}

	void push_back(Type const &newBack)
	{
		DoubleNode<Type> *newNode = new DoubleNode<Type>(newBack, this->tail, nullptr);

		this->tail->next = newNode;
		this->tail = newNode;

		if (this->this->size == 0)
		{
			this->head = newNode;
		}

		this->this->size++;
	}

	Type pop_front()
	{
		if (empty()) throw underflow_error("List is empty.");

		Type data;
		DoubleNode<Type> *popNode = this->head;
		this->head = popNode->next;

		if (this->head == nullptr)
		{
			this->tail = nullptr;
		}

		this->head->previous = nullptr;
		data = popNode->data;
		delete popNode;
		return data;
	}

	int erase(Type const &toDelete)
	{
		DoubleNode<Type> *curNode = this->head->next;
		DoubleNode<Type> *nextNode;
		int count;

		while (curNode != this->head)
		{
			nextNode = curNode->next;
			if (curNode->data == toDelete)
			{
				curNode->previous->next = curNode->next;
				curNode->next->previous = curNode->previous;
				delete curNode;
				count++;
			}
			curNode = next;
		}
		return count;
	}

	void print()
	{
		DoubleNode<Type> *curNode = this->head;

		cout << endl;
		while (curNode->next != nullptr)
		{
			cout << curNode->data << " " << ;
			curNode = curNode->next;
		}
		cout << endl;
	}

	~DoublyLinkedList()
	{
		if (this->isEmpty()) throw underflow_error("The list is empty.");

		DoubleNode<Type> *current = this->head;

		while (current->next != nullptr)
		{
			delete current->previous;
			this->this->size--;
		}
		this->head = nullptr;
		this->tail = nullptr;
	}
};