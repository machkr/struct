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

		void enqueue(Type data) {
			if (count == arraySize) {
				doubleArray();
			}
			back = (back + 1) % arraySize;
			array[back] = data;
			count++;
		}

		Type dequeue() {
			Type temp = array[front];
			front = (front + 1) % arraySize;
			count--;
			return temp;
		}

		void doubleArray() {
			Type *newArray = new Type[arraySize*2];
			int size = count;
			for (int i = 0; i < size; i++) {
				newArray[i] = dequeue();
			}
			arraySize = arraySize*2;
			array = newArray;
			count = size;
		}

		bool empty() { return count == 0; }
};
