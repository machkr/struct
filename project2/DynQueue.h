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

		this->arraySize = initialSize;

		queueArray = new type[initialSize];

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
		return this->arraySize;
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

		for (int i = this->ihead; i <= this->itail; i++)
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
		if (this->eraseFlag == true)
		{

		if (count == 0)
		{
			ihead = itail;
			queueArray[ihead] = data;
			count++;
			return;

		}

		else if (count == this->arraySize)
			{
				int temp = 0;
				type *newArray = new type[arraySize*2];

				for (int i = this->ihead; i <= this->itail; i++)
				{
					if (temp < this->count) { newArray[i] = this->queueArray[i]; }
					else { newArray[i].clear(); }

					temp++;
				}

				this->arraySize *= 2; 
				this->queueArray = newArray;
			}

			

			this->itail++;
			this->queueArray[itail] = data;
			count++;
			return;
		}

		//Non-erase Call
		cout << "Attempting to enqueue \"" << data << "\"..." << endl;

		if (this->count == 0)
		{
			this->ihead = this->itail;
			queueArray[ihead] = data;
			this->count++;
			cout << "\"" << data << "\" enqueued successfully." << endl << endl;
			return;

		}

		else if (this->count == this->arraySize)
		{
			int temp = 0;
			type *newArray = new type[arraySize * 2];

			for (int i = this->ihead; i <= this->itail; i++)
			{
				if (temp < this->count) { newArray[i] = queueArray[i]; }
				else { newArray[i].clear(); }

				temp++;
			}

			this->arraySize *= 2;
			queueArray = newArray;
			cout << endl << "The array size has been doubled to accept " << arraySize << " elements." << endl << endl;
		}


		this->itail++;
		this->queueArray[itail] = data;
		this->count++;
		cout << "\"" << data << "\" enqueued successfully." << endl << endl;
	}

	type dequeue()								//Removes element at the front of the queue. If after it's removed, the array is 1/4 full and array size is greater than the initial size, size of the array is halved. This may throw an underflow. (O(1) on average)
	{	
		//Erase Call
		if (this->eraseFlag == true) 
		{
			if (this->empty()) throw underflow_error("Error: the queue is empty."); 

			type temp = this->front();
			queueArray[ihead].clear();
			count--;
			ihead++;

			if (((double)this->count / (double)this->arraySize <= 0.25) && (this->arraySize > this->initialSize))
			{
				type *newArray = new type[this->arraySize/2];
				int tempNumber = 0;

				for (int i = this->ihead; i <= this->itail; i++)
				{
					if (tempNumber < this->count) { newArray[i] = this->queueArray[i]; }
					else { newArray[i].clear(); }	

					tempNumber++;
				}

				this->arraySize /= 2;
				this->queueArray = newArray;

			}

			return temp;
		}

		//Non-erase call
		cout << "Attempting to dequeue from the queue..." << endl;

		if (this->empty()) throw underflow_error("Error: the queue is empty.");

		type temp = this->front();
		this->queueArray[ihead].clear();
		this->count--;
		this->ihead++;

		if (((double)count / (double)arraySize <= 0.25) && (arraySize > initialSize))
		{
		
			type *newArray = new type[arraySize];
			int tempNumber = 0;

			for (int i = ihead; i <= itail; i++)
			{
				if (tempNumber < count) { newArray[i] = queueArray[i]; }
				else { newArray[i].clear(); }

				tempNumber++;
			}

			this->arraySize /= 2;
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

			for (int i = this->ihead; i <= itail; i++)
			{
				queueArray[i].clear();
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

		for (int i = this->ihead; i <= this->itail; i++)
		{
			queueArray[i].clear();
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

		for (int i = this->ihead; i <= this->itail; i++)
		{
			if (data == queueArray[i])
			{
				this->dequeue();
				num++;
				this->display();
			}
			else
			{
				cout << "How many times does this print statement get called?" << endl;
				temp.enqueue(this->dequeue());
			}

		}

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
		temp.eraseFlag = false;
		
		return num;
	}
};
