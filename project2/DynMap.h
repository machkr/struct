#pragma once
#include <iostream>
#include "LinkedList.h"
#include "DynContainer.h"

using namespace std;

template <class K, class V>
struct MapNode {
	K key;
	V val;
	bool operator==(const MapNode& right) {
		return (key == right.key);
	}
};

template <class K, class V>
class DynMap {
	public:
		static const int INITIAL_SIZE = 8;
	private:
		LinkedList<MapNode<K,V>> ** array;
		int count;
		int initialSize;
		int arraySize;
		int hash(K const &key, int size) 
		{
			return 1;
		}
	
	public:
		DynMap() : 
				array(new LinkedList<MapNode<K,V>>*[INITIAL_SIZE]),
				count(0), 
				initialSize(INITIAL_SIZE),
				arraySize(INITIAL_SIZE)
		{
			initializeArray(array, arraySize);
		}

		void insert(K const &key, V const &val)  
		{	
			// Double array size if count > arraySize/2
			if ( count > (arraySize / 2) )
				doubleSize();

			int h = hash(key, arraySize);
			if (array[h] == nullptr) 
				array[h] = new LinkedList<MapNode<K,V>>();
				
			array[h]->push_back({key,val});
			
		}

		V search(K const &key) 
		{
			int h = hash(key, arraySize);
			if (array[h] == nullptr) 
				throw underflow_error("Key not found");

			SingleNode<MapNode<K,V>> * curNode = array[h]->getHead();
			while (curNode != nullptr) 
			{
				if (curNode->getData().key == key)
					return curNode->getData().val;
				
				curNode = curNode->getNext();
			}
			throw underflow_error("Key not found");
		}

		void del(K const &key) 
		{
			int h = hash(key, arraySize);
			if (array[h] == nullptr)
				throw underflow_error("Key not found");

			SingleNode<MapNode<K,V>> * curNode = array[h]->getHead();
			while (curNode != nullptr) 
			{
				if (curNode->getData().key == key) 
				{
					array[h]->erase({key,curNode->getData().val});
					return;
				}
				curNode = curNode->getNext();
			}
			throw underflow_error("Key not found");
		}
		
		void doubleSize() 
		{
			LinkedList<MapNode<K,V>> ** newArray = new LinkedList<MapNode<K,V>>*[arraySize*2];
			initializeArray(newArray, arraySize*2);
			for (int i=0; i < arraySize; i++) 
			{
				if (array[i] != nullptr) 
				{
					// Really should define an iterator class for LL...
					SingleNode<MapNode<K,V>> * curNode = array[i]->getHead();
					while (curNode != nullptr) 
					{
						int h = hash(curNode->getData().key, arraySize*2);
						if (newArray[h] == nullptr) 
							newArray[h] = new LinkedList<MapNode<K,V>>();
						newArray[h]->push_back(curNode->getData());
						curNode = curNode->getNext();
					}
					delete array[i];
				}
			}

			LinkedList<MapNode<K,V>> ** temp = array;
			array = newArray;
			delete temp;
			arraySize = arraySize * 2;
		}

		int size() const { return count; }
		bool empty() const { return count == 0; }
		int capacity() const { return arraySize; }
		void display() const {}	;
		void clear() {};

		void initializeArray(LinkedList<MapNode<K,V>> ** a, int size) 
		{
			for (int i=0; i < size; i++) 
				a[i] = nullptr;
		}
};

