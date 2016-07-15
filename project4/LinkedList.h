#pragma once
#include <iostream>
#include "SingleNode.h"
//using namespace std;


template <class Type>
class LLIterator {

	private:
		SingleNode<Type> * cur;
	public:	
		// Constructors
		LLIterator() : cur(nullptr) {};
		LLIterator(SingleNode<Type> * ptr) : cur(ptr) {}
		LLIterator(const LLIterator<Type>& obj) :	cur(obj.cur) {}
		LLIterator<Type>& operator=(const LLIterator<Type>& rhs) {
			cur = rhs.cur;
			return *this;
		}

		// Comparators
		bool operator==(const LLIterator<Type>& rhs) { return cur == rhs.cur; }
		bool operator!=(const LLIterator<Type>& rhs) { return cur != rhs.cur; }

		// Incrementors
		LLIterator<Type>& operator++() { 
			cur = cur->getNext();
			return *this; 
		}
		LLIterator<Type>& operator++(int) { 
			cur = cur->getNext();
			return *this;
		}

		// Dereferencers
		Type operator*() { 
			Type data = cur->getData();
			return data;
		}
		Type operator->() { 
			Type data = cur->getData();
			return data; 
		}
};

template<class Type> class LinkedList
{
protected:
	SingleNode<Type> *head;
	SingleNode<Type> *tail;
	int size;

public:
	LinkedList(): head(nullptr), tail(nullptr), size(0){}

	// Accessors begin

	// Returns Number of items in the list.
	int getSize() const
	{ 
		return this->size;
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

	//Returns Head Pointer
	SingleNode<Type> *getHead() const
	{			
		return head;
	}

	//Returns Tail Pointer
	SingleNode<Type> *getTail() const
	{			
		return tail;
	}

	//Returns number of nodes in the linked list storing a value equal to the argument
	int count(Type const & toCount) const
	{			
		int count = 0;
		SingleNode<Type> * curNode;
		SingleNode<Type> * nextNode;

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

	//Mutators begin

	// Creates a new SingleNode<Type> storing the argument, next pointer set to
	// current head. Head is then set to the argument node. If list is 
	// initially empty, tail pointr is set to point to new node.
	void push_front(Type const & newFront)
	{			
		SingleNode<Type> * newNode = new SingleNode<Type>(newFront, head);
		head = newNode;
		if (size == 0)
		{
			tail = newNode;
		}
		size++;
		return;
	}

	// Places new node at the back of the list. Find the tail, and point tail's
	// next to new node. 
	void push_back(Type const & newBack)
	{               
		SingleNode<Type> * newNode = new SingleNode<Type>(newBack, nullptr);
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
	int erase(Type const & toDelete)
	{         
		int count = 0;
		SingleNode<Type> * curNode;
		SingleNode<Type> * nextNode;
		SingleNode<Type> * pastNode;

		curNode = nextNode = pastNode = head; 
		while (nextNode != nullptr)
		{
			pastNode = curNode;
			curNode = nextNode;
			nextNode = curNode->next;
			if (curNode->data == toDelete)
			{
				if (size == 1)
				{
					head = tail = nullptr;
					delete curNode;
					size--;
					count++;
					break;
				}

				if (curNode == head)
				{
					head = nextNode;
				}

				if (curNode == tail)
				{
						tail = pastNode;
				}

				pastNode->next = nextNode;
				delete curNode;
				size--;
				count++;		
			}
		}
		return count;
	}

	// Iterator
	typedef LLIterator<Type> iterator;
	typedef LLIterator<const Type> const_iterator;

	iterator begin() { return iterator(head); }
	iterator end()
	{ 
		if (tail == nullptr) return iterator(nullptr);
		else return iterator(tail->next);
	}

	// Destructor
	void deleteFollowing(SingleNode<Type> * cur)
	{
		if (cur->next != nullptr)
		{
			deleteFollowing(cur->next); 
		}
		cur->next = nullptr;
		delete cur;
	}
	
	~LinkedList()
	{
		if (head != nullptr) deleteFollowing(head);
	} 


};


