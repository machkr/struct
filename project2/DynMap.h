#pragma once
#include <iostream>
#include <string>
#include <iterator>
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
class DynMap : public DynContainer {
	public:
		static const int INITIAL_SIZE = 8;
	private:
		LinkedList<MapNode<K,V>> ** array;
		int count;
		int bucketsFilled;
		int initialSize;
		int arraySize;

		/******************
		 * Hash Functions *
		******************/
		unsigned int hash(int const &key, int size) const
		{
			unsigned long n = (unsigned long)key;
			n = ((1103515245 * n) + 12345) % 4294967296;
			return (unsigned int) n % size;
		}

		unsigned int hash(char const &key, int size) const 
		{
			unsigned long n = (unsigned long)key;
			n = ((1103515245 * n) + 12345) % 4294967296;
			return (unsigned int) n % size;

		}
	
		unsigned int hash(string const &key, int size) const 
		{
			unsigned long n = 1;
			for (string::const_iterator it = key.begin(); it != key.end(); it++) {
				n = (1103515245 * (n + (*it)) + 12345) % 4294967296;
			} 
			return (unsigned int)(n % size);
		}
		
	public:
		DynMap() : 
				array(new LinkedList<MapNode<K,V>>*[4]),
				count(0), 
				bucketsFilled(0),
				initialSize(4),
				arraySize(4)
		{
			initializeArray(array, arraySize);
		}

		void insert(K const &key, V const &val)  
		{	
			// Double array size if count > arraySize/2
			if ( count > (arraySize / 2) )
				doubleSize();

			unsigned int h = hash(key, arraySize);
			if (array[h] == nullptr) {
				array[h] = new LinkedList<MapNode<K,V>>();
				bucketsFilled++;
			} else { 
				// Find duplicate keys, replace if found
				SingleNode<MapNode<K,V>> * curNode = array[h]->getHead();
				while(curNode!=nullptr)
				{
					if (curNode->getData().key == key)
					{
						array[h]->erase(curNode->getData());
						array[h]->push_back({key,val});
					}
					curNode = curNode->getNext();
				}
			}
				
			array[h]->push_back({key,val});
			count++;
			
		}

		V search(K const &key) 
		{
			unsigned int h = hash(key, arraySize);
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
			unsigned int h = hash(key, arraySize);
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
						unsigned int h = hash(curNode->getData().key, arraySize*2);
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

		void display() const 
		{
			if (empty())
				throw underflow_error("Hash Table is empty");

			for (int i = 0; i < arraySize; i++) 
			{
				if (array[i] == nullptr) continue;
				
				SingleNode<MapNode<K,V>> * curNode = array[i]->getHead();
				while(curNode != nullptr) {
					MapNode<K,V> curMapNode = curNode->getData();
					unsigned int h = hash(curMapNode.key, arraySize);
					cout << "Key: " << curMapNode.key << endl;
					cout << "Value: " << curMapNode.val << endl ;
					cout << "Hash: " << h << endl << endl;
					curNode = curNode->getNext();
				}
			}
		}	

		void clear() 
		{
			for (int i = 0; i < arraySize; i++) 
			{
				if (array[i] == nullptr) continue;
				delete array[i];
			}
			delete array;
			array = new LinkedList<MapNode<K,V>>*[initialSize];	
			arraySize = initialSize;
		};

		void initializeArray(LinkedList<MapNode<K,V>> ** a, int size) 
		{
			for (int i=0; i < size; i++) 
				a[i] = nullptr;
		}
};

