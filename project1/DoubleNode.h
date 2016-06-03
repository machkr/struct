#pragma once
#include <iostream>
using namespace std;

template <class Type> class DoubleNode : public SingleNode
{
private:
	Type data;
	DoubleNode *previous;
	DoubleNode *next;
	friend class DoublyLinkedList;

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