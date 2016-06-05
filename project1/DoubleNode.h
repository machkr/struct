#pragma once
#include <iostream>
#include "SingleNode.h"
using namespace std;

template <class Type> class LinkedList;
template <class Type> class DoublyLinkedList;

template <class Type> class DoubleNode : public SingleNode<Type>
{
private:
	Type data;
	DoubleNode *previous;
	DoubleNode *next;
	friend class LinkedList<Type>;
	friend class DoublyLinkedList<Type>;

public:
	DoubleNode() : data(0), previous(nullptr), next(nullptr) {}

	DoubleNode(Type const &data, DoubleNode *previous, DoubleNode *next)
	{
		this->data = data;
		this->previous = previous;
		this->next = next;
	}

	Type getData() const
	{
		return this->data;
	}

	DoubleNode *getNext() const
	{
		return this->next;
	}

	DoubleNode *getPrevious() const
	{
		return this->previous;
	}

	~DoubleNode() {};
};