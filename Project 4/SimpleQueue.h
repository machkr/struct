#pragma once

template <class Type>
class SimpleQueue {
	private: 
		Type *array;
		int front;
		int back;
		int arraySize;
		int count;
	
	public: 
		SimpleQueue(int size) :
			arraySize(size),
			front(0),
			back(-1),
			count(0)
		{
			array = new Type[arraySize];
		}

		SimpleQueue() :
			arraySize(1),
			front(0),
			back(-1),
			count(0)
		{
			array = new Type[arraySize];
		}

		void enqueue(Type data)
		{
			if (count == arraySize) { doubleArray(); }
			back = (back + 1) % arraySize;
			array[back] = data;
			count++;
		}

		Type dequeue()
		{
			Type temp = array[front];
			front = (front + 1) % arraySize;
			count--;
			return temp;
		}

		void doubleArray()\
		{
			Type *newArray = new Type[arraySize*2];
			int size = count;

			for (int i = 0; i < size; i++)
			{
				newArray[i] = dequeue();
			}

			front = 0;
			back = size - 1;
			arraySize = arraySize*2;
			array = newArray;
			count = size;
		}

		bool empty() { return count == 0; }
		Type getFront() { return array[front]; }
		Type getBack() { return array[back]; }
		int getCount() { return count; }
		int getSize() { return arraySize; }
};
