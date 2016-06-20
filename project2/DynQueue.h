#include <iostream>

using namespace std;

template <class type>

class DynQueue
{
private:
	type *queueArray;		//Array
	int count;				//Counter
	int ihead;				//Head index
	int itail;				//Tail index
	int initialSize;		//Array capacity (should be 13 if using default constructor) 
	int arraySize;			//Current array size
	bool eraseFlag = false;

public:
	//Constructors

	DynQueue(int size) : count(0), ihead(0), itail(0)
	{
		if (size <= 0)
		{
			initialSize = 1;
		}
		else 
		{
			initialSize = size;
		}

		arraySize = initialSize;
		queueArray = new type[arraySize];
	}

	DynQueue() : count(0), initialSize(13), arraySize(13), ihead(0), itail(0)
	{
		queueArray = new type[arraySize];
	}

	//Destructor
	~DynQueue()									//Needs to delete the memory allocated for the whole array!
	{
		delete[] queueArray;
	}

	//Accessors

	type front()		
	{	
		if (this->empty()) throw underflow_error("Error: the queue is empty.");
		return queueArray[ihead];
	}

	type back()
	{	
		if (this->empty()) throw underflow_error("Error: the queue is empty.");
		return queueArray[itail];
	}

	int size() const
	{	
		return count;
	}

	bool empty()
	{	
		return count == 0;
	}

	int capacity()
	{	
		return arraySize;
	}

	void display()
	{
		int num = 0;

		cout << "Attempting to display the queue..." << endl;

		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		cout << "Here's the queue, from front to back:" << endl;

		for (int i = ihead; i <= itail; i++)
		{
			cout << "Element " << num << ": " << queueArray[i] << endl;
			num++;
		}

		cout << endl;
	}

	//Mutators

	void enqueue(type const &data)
	{
		if (!eraseFlag)
		{
			cout << "Attempting to enqueue \"" << data << "\"..." << endl;
		}

		if (count == 0)
		{
			ihead = itail;
		}
		else if (count == arraySize)
		{
			int num = 0;
			type *newArray = new type[arraySize * 2];

			for (int i = ihead; i <= itail; i++)
			{
				if (num < count) { newArray[num] = queueArray[i]; }
				else newArray[i].clear();
				num++;
			}

			if (!eraseFlag)
			{
				cout << "Warning: the queue is full (" << count << "/" << arraySize << ")." << endl;
				cout << "The array size has been doubled to accept " << (arraySize * 2) << " elements." << endl;
			}

			arraySize = 2 * arraySize;
			queueArray = newArray;
			ihead = 0;
			itail = count;
		}
		else
		{
			itail++;
		}

		queueArray[itail] = data;
		count++;

		if (!eraseFlag)
		{
			cout << "\"" << data << "\" enqueued successfully." << endl << endl;
		}
	}

	type dequeue()
	{	
		int num = 0;

		if (!eraseFlag)
		{
			cout << "Attempting to dequeue from the queue..." << endl;
		}

		if (this->empty()) throw underflow_error("Error: the queue is empty.");

		type temp = front();
		queueArray[ihead].clear();
		count--;
		ihead++;

		if (((double)count / (double)arraySize <= 0.25) && (arraySize > initialSize))
		{
			type *newArray = new type[arraySize / 2];

			for (int i = ihead; i <= itail; i++)
			{
				if (num < count) { newArray[num] = queueArray[i]; }
				else newArray[i].clear();
				num++;
			}

			if (!eraseFlag)
			{
				cout << "Warning: the queue is nearly empty (" << count << "/" << arraySize << ")." << endl;
				cout << "The array size has been halved to accept " << arraySize / 2 << " elements." << endl << endl;
			}

			arraySize = arraySize / 2;
			queueArray = newArray;
			ihead = 0;
			itail = count - 1;
		}

		if (!eraseFlag)
		{
			cout << "The queue has been dequeued successfully (Removed \"" << temp << "\")." << endl << endl;
		}

		return temp;
	}

	void clear()									//Removes all elements in the queue. The array is resized to the initial size. (O(1))
	{	
		cout << "Attempting to clear the queue..." << endl;

		if (this->empty()) throw underflow_error("Error: the queue is empty.");

		for (int i = ihead; i <= itail; i++)
		{
			queueArray[i].clear();
		}

		count = 0;
		ihead = 0;
		itail = 0;
		arraySize = initialSize;
		cout << "The queue has been cleared successfully." << endl << endl;
	}

	int erase(type const & data)                    //Removes elements from the front that contains the element equal to the argument. If afterwards the array is 1/4 full and the array size is greater than the initial size, the size of array is halved. Return number of elements that were deleted. Underflow may be used. 
	{												//Dequeue every element to compare. Use a temporary queue to hold elements that are not equal to the argument. After main queue is empty, return elements that are in the temporary queue back to the main one. Calculate running time in report!
		int num = 0;
		DynQueue<type> temp = DynQueue<type>(arraySize);

		eraseFlag = true;
		temp.eraseFlag = true;

		cout << "Attempting to erase \"" << data << "\"..." << endl;

		if (this->empty()) throw underflow_error("Error: the queue is empty.");

		for (int i = ihead; i <= itail; i++)
		{
			if (data == queueArray[i])
			{
				dequeue();
				num++;
			}
			else
			{
				temp.enqueue(dequeue());
			}
		}

		for (int i = temp.ihead; i <= temp.itail; i++)
		{
			enqueue(temp.dequeue());
		}

		if (num == 1)
		{
			cout << num << " instance of \"" << data << "\" has been erased successfully." << endl << endl;
		}
		else
		{
			cout << num << " instances of \"" << data << "\" have been erased successfully." << endl << endl;
		}

		eraseFlag = false;
		temp.eraseFlag = false;
		return num;
	}
};