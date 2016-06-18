#include "DynMap.h"
#include <string>

template <class K, class V> 
DynMap<K,V>::DynMap() : 
	array(new LinkedList<V>[initialSize]),
	count(0), 
	initialSize(INITIAL_SIZE),
	arraySize(INITIAL_SIZE)
{
	initializeArray(array, arraySize);
}


template <class K, class V> 
int DynMap<K,V>::hash(K const &key) 
{
	return 1;	
}


template <class K, class V> 
void DynMap<K,V>::insert(K const &key, V const &val) 
{
	// Double array size if count > arraySize/2
	if ( count > (arraySize / 2) )
	{
		LinkedList<V> * newArray = new LinkedList<V>[arraySize*2];
		initializeArray(newArray, arraySize*2);
		for (int i=0; i < arraySize; i++) 
		{
			newArray[hash(array[i]->key, arraySize*2)] = array[i];
		}
		LinkedList<V> * temp = array;
		array = newArray;
		delete array;
		arraySize = arraySize * 2;
	}

	int h = hash(key, arraySize);
	if (array[h] == nullptr) 
		array[h] = LinkedList<V>();
		
	array[h].push_back(val);
	
}

template <class K, class V>
V DynMap<K,V>::search(K const &key) 
{

}

template <class K, class V> 
void DynMap<K,V>::del(K const &key) 
{

}

template <class K, class V>
int DynMap<K,V>::display() const
{

}

template <class K, class V> 
void DynMap<K,V>::clear() 
{

}

template <class K, class V>
void DynMap<K,V>::initializeArray(LinkedList<V> * a, int size) {
	for (int i=0; i < size; i++) {
		a[i] = nullptr;
	}
}


	
//template class DynMap<string, string>;
