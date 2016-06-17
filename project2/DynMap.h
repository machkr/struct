#pragma once
#include <iostream>
#include "LinkedList.h"
#include "DynContainer.h"

using namespace std;

template <class K, class V>
class DynMap : public DynContainer {
	public:
		static const int INITIAL_SIZE = 8;
	private:
		LinkedList<V> * array;
		int count;
		int initialSize;
		int arraySize;
		int hash(K const &key);
	
	public:
		DynMap();

		void insert(K const &key, V const &val);
		V search(K const &key);
		void del(K const &key);

		int size() const { return count; }
		bool empty() const { return count == 0; }
		int capacity() const { return arraySize; }
		int display() const;
		void clear();
		void initializeArray(LinkedList<V> * a, int size);
};

