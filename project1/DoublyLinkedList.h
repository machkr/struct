#pragma once
#include "DoubleNode.h"
using namespace std;

template<class Type> class DoublyLinkedList : public LinkedList
{
private:

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {};

	//int size() const {};

	//bool empty() const {};

	//front() inherited from base class

	//back() inherited from base class

	/*DoubleNode<Type> *head() const
	{
		return head;
	}

	DoubleNode<Type> *tail() const
	{
		return tail;
	}*/

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

		head->previous = newNode;
		head = newNode;

		if (size == 0)
		{
			tail = newNode;
		}

		size++;
	}

	void push_back(Type const &newBack)
	{
		DoubleNode<Type> *newNode = new DoubleNode<Type>(newBack, tail, nullptr);

		tail->next = newNode;
		tail = newNode;

		if (size == 0)
		{
			head = newNode;
		}

		size++;
	}

	Type pop_front()
	{
		if (empty()) throw underflow_error("List is empty.");

		DoubleNode<Type> *popNode = head;
		head = popNode->next;

		if (head == nullptr)
		{
			tail = nullptr;
		}

		head->previous = nullptr;
		return popNode->data;
		delete popNode;
	}

	int erase(Type const &toDelete)
	{
		DoubleNode<Type> *curNode = head->next;
		DoubleNode<Type> *nextNode;
		int count;

		while (curNode != head)
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
		DoubleNode<Type> *curNode = head;

		cout << endl;
		while (curNode->next != nullptr)
		{
			cout << curNode->data << " " << ;
			curNode = curNode->next;
		}
		cout << endl;
	}

	~DoublyLinkedList() {};
};