#include <iostream>

using namespace std;

template <class type>

class DynQueue
{
private:
	type *queueArray;		//Array
	int count;			//Counter
	int ihead;			//Head index
	int itail;			//Tail index
	int initialSize;		//Array capacity (should be 13 if using default constructor) 
	int arraySize;			//Current array size

public:

	//Constructors

	DynQueue(int size) : count(0), ihead(0), itail(0) {
		if (size <= 0)
		{
			initialSize = 1;
			arraySize = 0;
		}
		else {
			intialSize = size;
			arraySize = 0;
		}

		queueArray = new type[initialSize];

	}

	DyneQueue() : count(0), initialSize(13), arraySize(0), ihead(0), itail(0) {
		queueArray = new type[initialSize];
	}

	//Destructor
	~DyneQueue() {								//Needs to delete the memory allocated for the whole array!
		this->clear();
	}

	//Accessors

	type front() const {							//Returns object at front of queue. Underflow exception.		
		if (this->empty()) {
			throw underflow_error("Queue is Empty.");
		}
		return queueArray[ihead];
	}

	type back() const {							//Returns object at bck of queue. Underflow exception.
		if (this->empty()) {
			throw underflow_error("Queue is Empty.");
		}
		return queueArray[itail];
	}

	int size() const {							//Returns number of elemets currently stored in the queue. (O(1))
		return count;
	}

	bool empty() {								//Returns true if queue is empty, false otherwise. (O(1))
		return count == 0;
	}

	int capacity() {							//Returns the current size of the array. (O(1)) 
		return arraySize();
	}

	void display() const {							//Prints the content of the Queue. (O(n))

		cout << "Attempting to display the queue..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is empty.") << endl << endl;
			//if (this->empty()) throw underflow_error("Error: the queue is empty.");
			return;
		}

		cout << "Here's the queue, from front to back:" << endl;

		for (int i = count - 1; i >= 0; i--)
		{
			cout << "Element " << i << ": " << queueArray[i] << endl;
		}

		cout << endl;
	}

	//Mutators

	void enqueue(Type const & data) {					//Insert new element at the back of the queue. If array is full, size of array is first doubled. (O(1) on average)

		cout << "Attempting to enqueue \"" << data << "\"..." << endl;

		if (count == initialSize)
		{
			arraySize = 2 * initialSize;
			type *newArray = new type[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				if (i < initialSize) newArray[i] = queueArray[i];
				else newArray[i] = NULL;
			}

			queueArray = newArray;
			cout << endl << "The array size has been doubled to accept " << arraySize << " elements." << endl << endl;
		}

		queueArray[count] = data;
		count++;
		itail = count;
		cout << "\"" << data << "\" enqueued successfully." << endl << endl;
	}

	type dequeue() {								//Removes element at the front of the queue. If after it's removed, the array is 1/4 full and array size is greater than the initial size, size of the array is halved. This may throw an underflow. (O(1) on average)
		cout << "Attempting to dequeue the queue..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the queue is empty.");
			return NULL;
		}

		if (ihead == itail)
		{
			type temp = this->front();
			queueArray[]
		}

		type temp = this->front();
		queueArray[ihead] = NULL;
		count--;
		ihead++;

		if ((((double)count / (double)arraySize) <= 0.25) && (arraySize > initialSize))
		{
			arraySize /= 2;
			type *newArray = new type[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				if (i < initialSize) newArray[i] = queueArray[i];
				else newArray[i] = NULL;
			}

			queueArray = newArray;
			cout << endl << "The array size has been halved to accept " << arraySize << " elements." << endl << endl;
		}

		cout << "The queue has been dequeued successfully (Removed \"" << temp << "\")." << endl << endl;
		return temp;
	}

	void clear() {									//Removes all elements in the queue. The array is resized to the initial size. (O(1))
		cout << "Attempting to clear the queue..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is already empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the queue is empty.");
			return;
		}

		for (int i = 0; i < arraySize; i++)
		{
			queueArray[i] = NULL;
			count--;
			ihead++;
		}

		arraySize = initialSize;
		cout << "The queue has been cleared successfully." << endl << endl;
	}

	int erase(type const & data)                    //Removes elements from the front that contains the element equal to the argument. If afterwards the array is 1/4 full and the array size is greater than the initial size, the size of array is halved. Return number of elements that were deleted. Underflow may be used. 
													//Dequeue every element to compare. Use a temporary queue to hold elements that are not equal to the argument. After main queue is empty, return elements that are in the temporary queue back to the main one. Calculate running time in report!
	{
		int num = 0;
		DynQueue<type> temp = DynQueue<type>(count);

		cout << "Attempting to erase \"" << data << "\"..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the queue is empty.");
			return 0;
		}

		for (int i = count - 1; i >= 0; i--)
		{
			if (data == queueArray[i])
			{
				this->dequeue();
				num++;
			}
			else
			{
				temp.enqueue(dequeue());
			}
		}

		temp.display();

		for (int i = (temp.count) - 1; i >= 0; i--)
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
		
		return num;
	}
};
