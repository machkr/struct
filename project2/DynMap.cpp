#include "DynMap.h"

template <class K, class V> 
DynMap<K,V>::DynMap(int (*hashFunc_)()) : 
	array(new int[INITIAL_SIZE]),
	count(0), 
	initialSize(INITIAL_SIZE),
	arraySize(INITIAL_SIZE),
	hashFunc(hashFunc_); {}

/*
template <class K, class V> 
int DynMap<K,V>::hash(K const &key) 
{
	
}
*/

template <class K, class V> 
void DynMap<K,V>::insert(K const &key, V const &val) 
{
	// Double array size if count > arraySize/2
	if (count > (arraySize / 2) 
	{
		MapNode ** newArray = new MapNode[arraySize*2];
		initializeArray(newArray, arraySize*2);
		for (int i=0; i < arraySize; i++) 
		{
			newArray[hash(array[i]->key, arraySize*2)] = array[i];
		}
		MapNode ** temp;
		temp = array;
		array = newArray;
		delete array;
	}

	int h = hash(key, arraySize);
	if (array[h] == nullptr) 
		array[h] = LinkedList<MapNode>();
		
	array[h].push_back(MapNode({key,value});
	
}

template <class K, class V> 
void DynMap<K,V>::delete(K const &key) 
{

}

template <class K, class V>
int DynMap<K,V>::display() 
{

}

template <class K, class V> 
void DynMap<K,V>::clear() 
{

}

template <class K, class V>
void DynMap<K,V>::initializeArray(LinkedList * a, int size) {
	for (int i=0; i < size; i++) {
		a[i] = nullptr;
	}
}


	

