#pragma once
#include <iostream>
using namespace std;

template <class Type> class LinkedList;
template <class Type> class CyclicLinkedList;

template <class Type> class SingleNode
{
protected:
	Type data;
	SingleNode *next;
	friend class LinkedList<Type>;
	friend class CyclicLinkedList<Type>;
	
//	template <class U> friend class CyclicLinkedList;

public:
	SingleNode() : data(0), next(nullptr) {}				//Default Constructor

	SingleNode(Type const &data, SingleNode *next)			//Constructor
	{
		this->data = data;
		this->next = next;
	}

	Type getData() const									//Data accessor
	{
		return this->data;
	}

	SingleNode *getNext() const								//Next accessor
	{
		return this->next;
	} 

	~SingleNode() {};										//Default Destructor
};
