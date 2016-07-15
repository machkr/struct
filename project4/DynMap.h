#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include "LinkedList.h"

using namespace std;


template <class K, class V>
class DynMap;

template <class K, class V>
struct MapNode {
	K key;
	V val;
	bool operator==(const MapNode& right) {
		return (key == right.key);
	}
};

// https://xkcd.com/974/
template <class K, class V>
class MapIterator {

	private:
		DynMap<K,V> * map;
		int curIndex;
		typename LinkedList<MapNode<K,V>>::iterator curIt;

	public:	
		// Constructors
		MapIterator() : 
			map(nullptr), 
			curIndex(0) 
		{}

		MapIterator(DynMap<K,V> * map_, int curIndex_) : 
			map(map_),
			curIndex(curIndex_)
		{
			// Return iterator to beginning of first LL in map, or return iterator 
			// to end of last LL in map
			if (curIndex != map->bucketsFilled) 
				curIt = map->array[ map->filled[curIndex] ]->begin();
			else 
				curIt = map->array[ map->filled[ map->bucketsFilled - 1 ] ]->end();
		}

		MapIterator(const MapIterator<K,V>& obj) :
			map(obj.map), 
			curIndex(obj.curIndex),
			curIt(obj.curIt)
		{}

		MapIterator<K,V>& operator=(const MapIterator<K,V>& rhs)
		{
			map = rhs.map;
			curIndex = rhs.curIndex;
			curIt = rhs.curIt;
			return *this;
		}

		// Comparators
		bool operator==(const MapIterator<K,V>& rhs)
		{ 
			return (curIt == rhs.curIt) && (curIndex == rhs.curIndex);
		}
		bool operator!=(const MapIterator<K,V>& rhs)
		{ 
			return (curIt != rhs.curIt) || (curIndex != rhs.curIndex); 
		}

		// Incrementors
		MapIterator<K,V>& operator++()
		{ 
			curIt++;
			if (curIt == map->array[ map->filled[curIndex] ]->end() && 
					curIndex < map->bucketsFilled) 
			{
				curIndex++;
				curIt = map->array[ map->filled[curIndex] ]->begin();
			}
			return *this; 
		}

		MapIterator<K,V>& operator++(int)
		{ 
			curIt++;
			if (curIt == map->array[ map->filled[curIndex] ]->end() && 
					curIndex < map->bucketsFilled) 
			{
				curIndex++;
				curIt = map->array[ map->filled[curIndex] ]->begin();
			}
			return *this; 
		}

		// Dereferencers
		V operator*()
		{ 
			V data = (*curIt).val;
			return data;
		}
		V operator->()
		{ 
			V data = (*curIt).val;
			return data; 
		}
};

template <class K, class V>
class DynMap 
{
	friend class MapIterator<K,V>;

	public:
		static const int INITIAL_SIZE = 8;
	private:
		LinkedList< MapNode<K,V> > ** array;
		int *filled;
		int count;
		int bucketsFilled;
		int initialSize;
		int arraySize;
		double loadFactor;

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
			for (string::const_iterator it = key.begin(); it != key.end(); it++)
			{
				n = (1103515245 * (n + (*it)) + 12345) % 4294967296;
			} 
			return (unsigned int)(n % size);
		}
		
	public:
		DynMap(double loadFactor_) : 
				array(new LinkedList< MapNode<K,V> >*[4]),
				filled(new int[4]),
				count(0), 
				bucketsFilled(0),
				initialSize(4),
				arraySize(4),
				loadFactor(loadFactor_)
		{
			initializeArray(array, arraySize);
		}

		void insert(K const &key, V const &val)  
		{	
			// Double array size if count > arraySize/2
			if (((double)count / (double)arraySize) > loadFactor) doubleSize();

			unsigned int h = hash(key, arraySize);
			if (array[h] == nullptr) 
			{
				array[h] = new LinkedList<MapNode<K,V>>();
				filled[bucketsFilled++] = h;
			}
			else
			{ 
				// Find duplicate keys
				SingleNode< MapNode<K,V> > * curNode = array[h]->getHead();
				while(curNode!=nullptr)
				{
					if (curNode->getData().key == key)
					{
						array[h]->erase(curNode->getData());
						break;
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
			if (array[h] == nullptr) throw underflow_error("Key not found");

			SingleNode<MapNode<K,V>> * curNode = array[h]->getHead();
			while (curNode != nullptr) 
			{
				if (curNode->getData().key == key) return curNode->getData().val;		
				curNode = curNode->getNext();
			}
			throw underflow_error("Key not found");
		}

		bool exists(K const &key) 
		{
			try
			{
				search(key);
			}
			catch (const underflow_error& e)
			{
				return false;
			}
			return true;
		}

		LinkedList<MapNode<K,V>>* getLL(K const &key)
		{
			unsigned int h = hash(key, arraySize);
			if (array[h] == nullptr) throw underflow_error("Key not found");
			return array[h];
		}

		void del(K const &key) 
		{
			unsigned int h = hash(key, arraySize);
			if (array[h] == nullptr) throw underflow_error("Key not found");

			SingleNode<MapNode<K,V>> * curNode = array[h]->getHead();
			while (curNode != nullptr) 
			{
				if (curNode->getData().key == key) 
				{
					array[h]->erase({key,curNode->getData().val});
					if (array[h]->empty())
					{
						delete array[h];
						
						// Delete from filled entry
						for (int i = 0; i < bucketsFilled; i++)
						{
							if (filled[i] == h)
							{
								while (i < bucketsFilled)
								{
									filled[i] = filled[i+1];
									i++;
								}
								bucketsFilled--;
							}
						}

					}
					return;
				}
				curNode = curNode->getNext();
			}
			throw underflow_error("Key not found");
		}
		
		void doubleSize() 
		{
			// Double filled array
			int * newFilled = new int[arraySize*2];
			delete[] filled;
			filled = newFilled;

			bucketsFilled = 0;

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
						{
							newArray[h] = new LinkedList<MapNode<K,V>>();
							filled[bucketsFilled++] = h;
						}
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
				if (array[i] != nullptr)
					delete array[i];
			}
			delete array;
			array = new LinkedList<MapNode<K,V>>*[initialSize];	
			arraySize = initialSize;
			initializeArray(array,arraySize);
		};

		void initializeArray(LinkedList<MapNode<K,V>> ** a, int size) 
		{
			for (int i=0; i < size; i++) 
				a[i] = nullptr;
		}

		// Iterator
		typedef MapIterator<K,V> iterator;
		typedef MapIterator<const K, const V> const_iterator;

		iterator begin() { return iterator(this, 0); }
		iterator end() { return iterator(this, bucketsFilled); }
		
};

