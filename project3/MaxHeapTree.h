#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "HeapTreeNode.h"

using namespace std;

template <class type> class MaxHeapTree
{
private:
	HeapTreeNode<type> *heap;
	int size;
	int count;

public:
	//Constructors
	MaxHeapTree() : heap(NULL), size(1), count(0) {}											// Default
	MaxHeapTree(int _size) : heap(NULL), size(_size), count(0) {}								// Given a size parameter

																								//Destructor
	~MaxHeapTree() { clear(); }

	//-----------//
	// Accessors //
	//-----------//
	HeapTreeNode<type> getMax()																	// Returns the node with the maximum value (in max heap tree, the root)
	{
		return heap[1];
	}

	int getCount()																				// Returns the number of elements in the binary heap
	{
		return count;
	}

	int getHeight(int i)																		// Returns the height of binary heap
	{
		if (heap[i] == NULL) return -1;

		int leftHeight = getHeight(left(i));
		int rightHeight = getHeight(right(i));

		if (leftHeight > rightHeight) return (leftHeight + 1);
		else return (rightHeight + 1);
	}

	int left(int parentIndex)													// Returns the index of a node's left child, given its index
	{
		int left = (2 * parentIndex);

		if (left < count)
		{
			return left;
		}
		else
		{
			return -1;
		}
	}

	int right(int parentIndex)													// Returns the index of a node's right child, given its index
	{
		int right = ((2 * parentIndex) + 1);

		if (right < count)
		{
			return right;
		}
		else
		{
			return -1;
		}

	}

	int parent(int childIndex)													// Returns the index of a node's parent, given its index
	{
		int parent = childIndex / 2;

		if (childIndex == 1)
		{
			return -1;
		}
		else
		{
			return parent;
		}
	}

	bool empty()																				// Returns the state of the binary heap
	{
		return count == 0;
	}

	int leaves()																				// Returns the number of leaves in the binary heap
	{
		return ceil(double(count) / double(2));
	}

	//----------//
	// Mutators //
	//----------//
	void buildTree()																			// Builds a new binary heap from text file
	{
		int key;
		type data;

		ifstream istream("Heap.txt");

		if (!istream.is_open())
		{
			cout << "Error: unable to open file." << endl << endl;
			return;
		}

		heap = new HeapTreeNode<type>[size + 1];

		while (!istream.eof())
		{
			istream >> key;
			istream.ignore();
			getline(istream, data);
			insert(key, data);
		}

		istream.close();
	}

	void clear()																				// Clears heap, freeing up all memory allocated to it
	{
		//delete tree;
		size = 0;
		count = 0;
		heap = NULL;
	}

	void insert(int key, type data)																// Inserts element into heap, maintaining heap property [[ Worst: O(log n), Avg: O(1) ]]
	{
		if (count == size)
		{
			HeapTreeNode<type> *newHeap = new HeapTreeNode<type>[(size * 2) + 1];

			for (int i = 1; i <= count; i++)
			{
				newHeap[i] = heap[i];
			}

			cout << "Warning: heap is full (" << count << "/" << size << ")." << endl;

			size = size * 2;
			heap = newHeap;

			cout << "The size of the heap has been doubled to accept " << size << " elements." << endl << endl;
		}

		HeapTreeNode<type> *node = new HeapTreeNode<type>(key, data);
		heap[count + 1] = *node;
		count++;
		heapify_up(count);
	}

	void deleteMax()
	{
		if (empty()) throw underflow_error("Error: the heap is empty.");

		int temp = getMax().getKey();

		if ((double)count / (double)size <= 0.25)
		{
			HeapTreeNode<type> *newHeap = new HeapTreeNode<type>[(size / 2) + 1];

			for (int i = 1; i <= count; i++)
			{
				newHeap[i] = heap[i];
			}

			cout << "Warning: the heap is nearly empty (" << count << "/" << size << ")." << endl;

			size = size / 2;
			heap = newHeap;

			cout << "The size of the heap has been doubled to accept " << size << " elements." << endl;
		}

		swap(1, count);
		count--;
		heapify_down(1);

		cout << "The maximum has been deleted successfully (Removed \"" << temp << "\")." << endl << endl;
	}

	void swap(int indexA, int indexB)
	{
		HeapTreeNode<type> temp = heap[indexA];
		heap[indexA] = heap[indexB];
		heap[indexB] = temp;
	}

	void heapify_up(int index)
	{
		if (index >= 1 && parent(index) >= 1 && heap[parent(index)].getKey() < heap[index].getKey())
		{
			swap(index, parent(index));
			heapify_up(parent(index));
		}
	}

	void heapify_down(int index)
	{
		int l = left(index);
		int r = right(index);

		if (l >= 1 && r >= 1 && heap[l].getKey() < heap[r].getKey())
		{
			l = r;
		}

		if (l > 1)
		{
			swap(index, l);
			heapify_down(l);
		}
	}

	//----------//
	// Displays //
	//----------//
	void displayArray()																			//Displays the binary heap as an array of keys
	{
		if (empty())
		{
			//throw underflow_error("Error: the heap is empty.")
			cout << "Error: the heap is empty." << endl << endl;
			return;
		}

		for (int i = 1; i <= count; i++)
		{
			cout << heap[i].getKey() << " ";
		}

		cout << endl << endl;
	}

	void displayList()																			// Displays the binary heap as a list of nodes
	{
		if (empty())
		{
			//throw underflow_error("Error: the heap is empty.")
			cout << "Error: the heap is empty." << endl << endl;
			return;
		}

		for (int i = 1; i <= count; i++)
		{
			cout << "Node ";
			cout << setfill('0') << setw(2) << i << ". Key: " << heap[i].getKey() << endl;
			cout << "\t Data: " << heap[i].getData() << endl;
		}

		cout << endl << endl;
	}

	void displayTree()																			// Displays the binary heap as a tree
	{
		if (empty())
		{
			//throw underflow_error("Error: the heap is empty.")
			cout << "Error: the heap is empty." << endl << endl;
			return;
		}

		int start = 1;																			// Index of first node on level	
		int end = 1;																			// Index of last node on level
		int length;																				// Length of current row
		int numLevels = int(ceil(log(float(count)) / log(2.0)));								// Number of levels

		for (int curLevel = 0; curLevel < numLevels; curLevel++)
		{
			displayLevel(numLevels, curLevel, start, end);
			length = end - start + 1;
			start = end + 1;
			end = min(end + (2 * length), count);
		}
	}

	void displayLevel(int rows, int curLevel, int start, int end)								// Displays a level of the binary heap (used by displayheap)
	{
		int skip = int(pow(2.0, rows - curLevel) - 1);											// Space between items in row

		for (int i = start; i <= end; i++)
		{
			cout << setfill(' ') << setw(skip) << " ";
			cout << setfill('0') << setw(2) << heap[i].getKey();
			cout << setfill(' ') << setw(skip) << " ";
		}

		cout << endl << endl;
	}
};