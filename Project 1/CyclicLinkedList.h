#pragma once
#include <iostream>
#include "SingleNode.h"
#include "LinkedList.h"

using namespace std;

template<class Type> class CyclicLinkedList : public LinkedList<Type>
{
private:


public:

	//CyclicLinkedList() : this->head(nullptr), this->tail(nullptr), this->size(0) {}

	//Mutators begin

	void push_front(Type const & newFront)
	{
		SingleNode<Type> * newNode = new SingleNode<Type>(newFront, this->head);
		this->head = newNode;
		if (this->size == 0)
		{
			this->head = newNode;
			this->tail = newNode;
		}
		this->tail->next = this->head;
		this->size++;
		return;
	}

	void push_back(Type const & newBack)
	{
		SingleNode<Type> * newNode = new SingleNode<Type>(newBack, this->head);

		if (this->size == 0)
		{
			this->tail = newNode;
			this->head = newNode;
		}
		else
		{
			this->tail->next = newNode;
		}

		this->tail = newNode;
		this->size++;

		return;
	}

	Type pop_front()
	{
		if (this->empty()) throw underflow_error("List is empty.");
		Type data = this->head->data;
		if (this->size == 1)
		{
			delete this->head;
			this->head = this->tail = NULL;
			this->size=0;
			return data;
		}
		else if (this->size == 2)
		{
			SingleNode<Type> * temp = new SingleNode<Type>(this->head->next->data, this->head);
			delete this->head;
			this->head = temp;
			this->head->next = this->head;
			this->tail = this->head;
			this->tail->next = this->head;
			this->size--;
			return data;
		}

		else {
			SingleNode<Type> * temp = new SingleNode<Type>(this->head->next->data, this->head->next->next);
			delete this->head;
			this->head = temp;
			this->tail->next = this->head;
			this->size--;
			return data;
		}
	}

	int count(Type const & comparedData) const
	{
        if (this->head == nullptr)
		{
            throw underflow_error("List is empty");
        }
        
		int count = 0;
		SingleNode<Type> *curNode;
		SingleNode<Type> *nextNode;

		curNode = nextNode = this->head;

		while (nextNode != this->head)
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
		SingleNode<Type> *curNode = this->head;

		if (this->size == 0)
		{
			cout << "List is empty." << endl << endl;
			return;
		}

		do
		{
			cout << curNode->data << " ";
			curNode = curNode->next;
		} while (curNode != this->head);

		cout << endl << endl;
	}

	int erase(Type const & wrecked)         //Deletes the node(s) (from the front) in the linked list that contains the element equal to the argument (use == to test). As necessary, update the this->head, this->this->tail, and next of all applicable nodes in list. Return number of nodes that were deleted. 
	{
        if (this->head == nullptr) {
            throw underflow_error("List is empty.");
        }
		int count = 0;
		SingleNode<Type> * curNode;
		SingleNode<Type> * nextNode;
		SingleNode<Type> * pastNode;

		curNode = pastNode = this->head; 
		nextNode = curNode->next;
		while (nextNode != this->head)
		{
			pastNode = curNode;
			if (nextNode != this->head)
			{
				curNode = nextNode;
			}
			nextNode = curNode->next;
			if (curNode->data == wrecked)
			{
				if (this->size == 1)
				{
					this->head = this->tail = NULL;
					delete curNode;
					this->size--;
					count++;
					break;
				}

				if (curNode == this->head)
				{
					this->head = nextNode;
				}

				if (curNode == this->tail)
				{
					this->tail = pastNode;
				}

				pastNode->next = nextNode;
				delete curNode;
                curNode = pastNode;
				this->size--;
				count++;		
			}
		}
		return count;
	}


	~CyclicLinkedList() {

		SingleNode<Type> *current = this->head;
		SingleNode<Type> *previous = this->head;
		if (this->isEmpty())
		{
			throw underflow_error("The list is empty.");
		}
		else
		{
			while (current->next != this->head)
			{
				if (current == this->head)
				{
					this->head = this->head->next;
					delete previous;
					this->size--;
				}
			}
		}
	}

};
