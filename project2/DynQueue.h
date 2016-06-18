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
	int arraySize;			//Current array size
	bool eraseFlag = false;

public:

	int initialSize; //Array capacity (should be 13 if using default constructor) 
	//Constructors

	DynQueue(int size) : count(0), ihead(0), itail(0), arraySize(0)
	{
		if (size <= 0)
		{
			this->initialSize = 1;
		}
		else 
		{
			this->initialSize = size;
		}

		queueArray = new type[this->initialSize];

	}

	DynQueue() : count(0), initialSize(13), arraySize(0), ihead(0), itail(0)
	{
		queueArray = new type[initialSize];
	}

	//Destructor
	~DynQueue()									//Needs to delete the memory allocated for the whole array!
	{
		this->clear();
	}

	//Accessors

	type front() const							//Returns object at front of queue. Underflow exception.		
	{	
		if (count==0) cerr << ("Error: the queue is empty.") << endl;
		return queueArray[ihead];
	}

	type back() const							//Returns object at bck of queue. Underflow exception.
	{	
		if (count==0) cerr << ("Error: the queue is empty.") << endl;
		return queueArray[itail];
	}

	int size() const							//Returns number of elemets currently stored in the queue. (O(1))
	{	
		return count;
	}

	bool empty()								//Returns true if queue is empty, false otherwise. (O(1))
	{	
		return count == 0;
	}

	int capacity()								//Returns the current size of the array. (O(1)) 
	{	
		return arraySize;
	}

	void display()								//Prints the content of the Queue. (O(n))
	{
		int number = 1;

		cout << "Attempting to display the queue..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is empty.") << endl << endl;
			return;
		}

		cout << "Here's the queue, from front to back:" << endl;

		for (int i = ihead; i < (itail+1); i++)
		{
			cout << "Element " << number << ": " << queueArray[i] << endl;
			number++;
		}

		cout << endl;
	}

	//Mutators

	void enqueue(type const &data)				//Insert new element at the back of the queue. If array is full, size of array is first doubled. (O(1) on average)
	{
		//Erase Call
		if (eraseFlag == true)
		{

		if (this->count == 0)
		{
			ihead = itail;
			queueArray[ihead] = data;
			count++;
			return;

		}

		else if (this->count == this->arraySize)
			{
				int temp = 0;
				type *newArray = new type[arraySize*2];

				for (int i = ihead; i <= itail; i++)
				{
					if (temp < this->arraySize) newArray[i] = queueArray[i];
					else newArray[i] = NULL;
					temp++;
				}

				this->arraySize *= 2; 
				queueArray = newArray;
			}

			

			itail++;
			queueArray[itail] = data;
			this->count++;
			return;
		}

		//Non-erase Call
		cout << "Attempting to enqueue \"" << data << "\"..." << endl;

		if (count == 0)
		{
			ihead = itail;
			queueArray[ihead] = data;
			count++;
			cout << "\"" << data << "\" enqueued successfully." << endl << endl;
			return;

		}

		else if (count == arraySize)
		{
			int temp = 0;
			type *newArray = new type[arraySize * 2];

			for (int i = ihead; i <= itail; i++)
			{
				if (temp < arraySize) newArray[i] = queueArray[i];
				else newArray[i] = NULL;
				temp++;
			}

			arraySize *= 2;
			queueArray = newArray;
			cout << endl << "The array size has been doubled to accept " << arraySize << " elements." << endl << endl;
		}


		itail++;
		queueArray[itail] = data;
		count++;
		cout << "\"" << data << "\" enqueued successfully." << endl << endl;
	}

	type dequeue()								//Removes element at the front of the queue. If after it's removed, the array is 1/4 full and array size is greater than the initial size, size of the array is halved. This may throw an underflow. (O(1) on average)
	{	
		int tempNumber = 0;

		//Erase Call
		if (eraseFlag == true) 
		{
			if (this->empty())
			{
				cerr << ("Error: the queue is empty.") << endl;
				return NULL;
			}

			type temp = this->front();
			queueArray[ihead] = NULL;
			count--;
			ihead++;

			if ((((double)count / (double)arraySize) <= 0.25) && (arraySize > initialSize))
			{
				type *newArray = new type[arraySize/2];

				for (int i = ihead; i <= itail; i++)
				{
					if (tempNumber < initialSize) newArray[i] = queueArray[i];
					else newArray[i] = NULL;
					tempNumber++;
				}
				arraySize /= 2;
				queueArray = newArray;

				}

			return temp;
		}

		//Non-erase call
		cout << "Attempting to dequeue from the queue..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is empty.") << endl;
			return NULL;
		}

		type temp = this->front();
		queueArray[ihead] = NULL;
		count--;
		ihead++;

		if ((((double)count / (double)arraySize) <= 0.25) && (arraySize > initialSize))
		{
			arraySize /= 2;
			type *newArray = new type[arraySize];

			for (int i = ihead; i < itail; i++)
			{
				if (tempNumber < initialSize) newArray[i] = queueArray[i];
				else newArray[i] = NULL;
				tempNumber++;
			}

			arraySize /= 2;
			queueArray = newArray;
			cout << endl << "The array size has been halved to accept " << arraySize << " elements." << endl << endl;
		}

		cout << "The queue has been dequeued successfully (Removed \"" << temp << "\")." << endl << endl;

		return temp;
	}

	void clear()								//Removes all elements in the queue. The array is resized to the initial size. (O(1))
	{	
		//Erase Call
		if (eraseFlag == true)
		{
			if (this->empty())
			{
				return;
			}

			for (int i = ihead; i <= itail; i++)
			{
				queueArray[i] = NULL;
				count--;
				ihead++;
			}

			arraySize = initialSize;
			return;		
		}

		//Non-Erase Call
		cout << "Attempting to clear the queue..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is already empty.") << endl;
			return;
		}

		for (int i = ihead; i <= itail; i++)
		{
			queueArray[i] = NULL;
			count--;
			ihead++;
		}

		arraySize = initialSize;
		cout << "The queue has been cleared successfully." << endl << endl;
	}

	int erase(type const & data)                    //Removes elements from the front that contains the element equal to the argument. If afterwards the array is 1/4 full and the array size is greater than the initial size, the size of array is halved. Return number of elements that were deleted. Underflow may be used. 
	{												//Dequeue every element to compare. Use a temporary queue to hold elements that are not equal to the argument. After main queue is empty, return elements that are in the temporary queue back to the main one. Calculate running time in report!
		int num = 0;
		DynQueue<type> temp = DynQueue<type>(count);

		eraseFlag = true;
		temp.eraseFlag = true;

		cout << "Attempting to erase \"" << data << "\"..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the queue is empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the queue is empty.");
			return 0;
		}

		for (int i = ihead; i <= itail; i++)
		{
			if (data == queueArray[i])
			{
				this->dequeue();
				num++;
			}
			else
			{
				temp.enqueue(this->dequeue());
			}

		}

		this->clear();

		for (int i = temp.ihead; i <= (temp.itail); i++)
		{
			this->enqueue(temp.dequeue());
			/*type tempData = temp.front();
			temp.dequeue();
			this->enqueue(tempData);*/
		}

		temp.clear();

		if (num == 1)
		{
			cout << num << " instance of \"" << data << "\" has been erased successfully." << endl << endl;
		}
		else
		{
			cout << num << " instances of \"" << data << "\" have been erased successfully." << endl << endl;
		}

		eraseFlag = false;
		
		return num;
	}
};