#pragma once
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "HeapNode.h"
#include "Vertex.h"

using namespace std;

template <class type> class MinHeap
{
private:
	HeapNode<type> * heap;
	int size;
	int capacity;
	int * position;

public:
	MinHeap() : size(0), capacity(1)
	{
		heap = new HeapNode<type>[capacity];
		position = new int[capacity];
	}

	MinHeap(int _capacity) : size(0), capacity(_capacity)
	{
		heap = new HeapNode<type>[capacity];
		position = new int[capacity];
	}

	~MinHeap()
	{ 
		clear();
	}

	int getLeft(int parentIndex)
	{
		int left = ((2 * parentIndex) + 1);

		if (left < size)
		{
			return left;
		}
		else
		{
			return -1;
		}
	}

	int getRight(int parentIndex)
	{
		int right = ((2 * parentIndex) + 2);

		if (right < size)
		{
			return right;
		}
		else
		{
			return -1;
		}
	}

	int getParent(int childIndex)
	{
		int parent = (childIndex - 1) / 2;

		if (childIndex == 1)
		{
			return -1;
		}
		else
		{
			return parent;
		}
	}

	bool isEmpty()
	{
		return size == 0;
	}

	bool isInHeap(int vertex)
	{
		return position[vertex] < size;
	}

	void swap(int indexA, int indexB)
	{
		HeapNode<type> temp = heap[indexA];
		heap[indexA] = heap[indexB];
		heap[indexB] = temp;
	}

	void insert(HeapNode<type> node, int position)
	{
		heap[position] = node;
	}

	void setPosition(int p, int x)
	{
		position[p] = x;
	}

	void setSize(int _size)
	{
		size = _size;
	}

	template <class Type>
	void heapify(int index)
	{
		int smallest = index;
		int left = getLeft(index);
		int right = getRight(index);

		if (left < size && heap[left].getKey() < heap[smallest].getKey())
			smallest = left;

		if (right < size && heap[right].getKey() < heap[smallest].getKey())
			smallest = right;

		if (smallest != index)
		{
			HeapNode<type> *smallestNode = new HeapNode<Vertex<Type>*>;
			*smallestNode = heap[smallest];
			HeapNode<type> *indexNode = new HeapNode<Vertex<Type>*>;
			*indexNode = heap[index];

			position[(*smallestNode).getVertex()] = index;
			position[(*indexNode).getVertex()] = smallest;

			swap(smallest, index);

			heapify<Type>(smallest);
		}
	}

	template <class Type>
	HeapNode<type> extractMin()
	{
		if (isEmpty()) throw underflow_error("Heap is empty.");

		HeapNode<type> root = heap[0];
		HeapNode<type> last = heap[size - 1];
		heap[0] = last;

		position[root.getVertex()] = size - 1;
		position[last.getVertex()] = 0;

		size--;
		heapify<Type>(1);

		return root;
	}

	void dKey(int vertex, double key)
	{
		int index = position[vertex];
		heap[index].setKey(key);

		while (index && heap[index].getKey() < heap[getParent(index)].getKey())
		{
			position[heap[index].getVertex()] = getParent(index);
			position[heap[getParent(index)].getVertex()] = index;
			swap(index, getParent(index));

			index = getParent(index);
		}
	}
	
	template<class Type>
	int findVertex(Vertex<Type> *v)
	{
		for (int i = 0; i < size; i++)
		{
			if (heap[i].getData() == v) return heap[i].getVertex();
			else continue;
		}

		return -1;
	}
};