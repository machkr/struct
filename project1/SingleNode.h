#pragma once
#include <iostream>
using namespace std;

template <class Type> class SingleNode
{
public:
	Type data;
	SingleNode * next;
	SingleNode() : data(0), next(nullptr)	//Default Constructor
	{
		//Nothing? 
	}
	SingleNode(Type const & data, SingleNode * next)	 //Constructor
	{
		this->data = data;
		this->next = next;
	}

	Type getData() const{		//Data accessor
		return this->data;
	}

	SingleNode *getNext() const {		//Next accessor
		return this->next;
	}

	~SingleNode();		//Default Destructor
};

