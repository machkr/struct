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

																								// Destructor
	~MaxHeapTree() { clear(); }

	//-----------//
	// Accessors //
	//-----------//
	HeapTreeNode<type> getMax()																	// Returns the node with the maximum value (in max heap tree, the root)
	{
		return heap[1];
	}

	int getSize()																				// Returns the number of elements in the binary heap
	{
		return count;
	}

	int getHeight(int index)																	// Returns the height of binary heap
	{
		int height = 0;

		while (left(index) != -1)
		{
			index = left(index);
			height++;
		}

		return height;
	}

	int left(int parentIndex)																	// Returns the index of a node's left child, given its index
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

	int right(int parentIndex)																	// Returns the index of a node's right child, given its index
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

	int parent(int childIndex)																	// Returns the index of a node's parent, given its index
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
		if (empty()) throw underflow_error("Error: the heap is empty.");
		return (int)(ceil(double(count) / double(2)));
	}

	//----------//
	// Mutators //
	//----------//
	void buildTree(string filename)																// Builds a new binary heap from text file
	{
		int key;
		type data;

		ifstream istream(filename);

		if (!istream.is_open()) { throw underflow_error("Error: unable to open file."); }

		heap = new HeapTreeNode<type>[size + 1];
		cout << endl;

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
		if (count == size)																		// If full, double the size
		{
			HeapTreeNode<type> *newHeap = new HeapTreeNode<type>[(size * 2) + 1];

			for (int i = 1; i <= count; i++)
			{
				newHeap[i] = heap[i];
			}

			cout << "Warning: heap is full (" << count << "/" << size << ")." << endl;

			size = size * 2;
			heap = newHeap;

			cout << "The size of the heap has been doubled to accept "
				<< size << " elements." << endl << endl;
		}

		HeapTreeNode<type> *node = new HeapTreeNode<type>(key, data);
		heap[count + 1] = *node;
		count++;
		heapify_up(count);																		// Use of the heapify_up alogrithm to maintain heap property
	}

	void deleteMax()																			// Removes maximum node (root) from the heap, maintaining heap property
	{
		if (empty()) throw underflow_error("Error: the heap is empty.");

		int temp = getMax().getKey();

		if ((double)count / (double)size <= 0.25)												// If nearing empty, halve the size
		{
			HeapTreeNode<type> *newHeap = new HeapTreeNode<type>[(size / 2) + 1];

			for (int i = 1; i <= count; i++)
			{
				newHeap[i] = heap[i];
			}

			cout << "Warning: the heap is nearly empty (" << count << "/"
				<< size << ")." << endl;

			size = size / 2;
			heap = newHeap;

			cout << "The size of the heap has been halved to accept "
				<< size << " elements." << endl;
		}

		swap(1, count);
		count--;
		heapify_down(1);																		// Use of the heapify_down algorithm to maintain heap property

		cout << "The maximum has been deleted successfully (Removed \""
			<< temp << "\").";
	}

	void swap(int indexA, int indexB)															// Swaps two nodes, given their indices
	{
		HeapTreeNode<type> temp = heap[indexA];
		heap[indexA] = heap[indexB];
		heap[indexB] = temp;
	}

	void heapify_up(int index)																	// Sorting algorithm for insertion (bottom >> top)
	{
		if (index >= 1 && parent(index) >= 1 &&													// Check to make sure the index and parent index are valid
			heap[parent(index)].getKey() < heap[index].getKey())								// If the parent's key is less than the current node's key
		{
			swap(index, parent(index));															// Swap those two nodes
			heapify_up(parent(index));															// And continue heapifying, recursively
		}
	}

	void heapify_down(int index)																// Sorting algorithm for deletion (top >> bottom)
	{
		int lChild = left(index);																// Storing left child's index
		int rChild = right(index);																// Storing right child's index

		if (lChild >= 1 && rChild >= 1 &&														// Check to make sure the children indices are valid
			heap[lChild].getKey() < heap[rChild].getKey())										// If the left child's key is less than the right child's key
		{
			lChild = rChild;																	// Set the left child index to that of the right (not swap)
		}

		if (lChild > 1)																			
		{
			swap(index, lChild);																// Swap the node called on with the index in lChild
			heapify_down(lChild);																// And continue heapifying, recursively
		}
	}

	//----------//
	// Displays //
	//----------//
	void displayArray()																			// Displays the binary heap as an array of keys
	{
		if (empty()) { throw underflow_error("Error: the heap is empty."); }

		cout << "[";

		for (int i = 1; i <= count; i++)
		{
			cout << heap[i].getKey();
			if (i != count) cout << " ";
		}

		cout << "]";
	}

	void displayList()																			// Displays the binary heap as a list of nodes
	{
		if (empty()) { throw underflow_error("Error: the heap is empty."); }

		for (int i = 1; i <= count; i++)
		{
			cout << "Node ";
			cout << setfill('0') << setw(2) << i << ". Key: " << heap[i].getKey() << endl;
			cout << "\t Data: " << heap[i].getData() << endl;
		}
	}

	void displayTree()																			// Displays the binary heap as a tree
	{
		if (empty()) { throw underflow_error("Error: the heap is empty."); }

		int start = 1;																			// Index of first node on level	
		int end = 1;																			// Index of last node on level
		int length;																				// Length of current row
		int numLevels = int(ceil(log(float(count)) / log(2.0)));								// Number of levels, calculated by number of nodes

		for (int curLevel = 0; curLevel < numLevels; curLevel++)								// Iterate through the levels of the tree
		{
			displayLevel(numLevels, curLevel, start, end);										// Display the current level
			length = end - start + 1;															// Calculate length of the current level
			start = end + 1;																	// Find starting index of next level
			end = min(end + (2 * length), count);												// Find ending index of next level
		}
	}

	void displayLevel(int rows, int curLevel, int start, int end)								// Displays a level of the binary heap (used by displayheap)
	{
		int skip = int(pow(2.0, rows - curLevel) - 1);											// Space between items in a level

		for (int i = start; i <= end; i++)														// Iterate through the current level
		{
			cout << setfill(' ') << setw(skip) << " ";											// Set the blank space left of the key at i
			cout << setfill('0') << setw(2) << heap[i].getKey();								// Display the key at i (padded with zeroes)
			cout << setfill(' ') << setw(skip) << " ";											// Set the blank space right of the key at i
		}

		cout << endl << endl;
	}
};