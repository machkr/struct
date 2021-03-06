#include <iostream>

using namespace std;

template <class type>

class DynStack
{
private:
	type *stackArray;
	int count;
	int initialSize;
	int arraySize;
	bool eraseFlag = false;

public:
	//Constructor
	DynStack(): count(0), initialSize(1), arraySize(1)
	{
		stackArray = new type[arraySize];
	}

	DynStack(int size): count(0)
	{
		if(size <= 0)
		{
			initialSize = 1;
			arraySize = 1;
		}
		else
		{
			initialSize = size;
			arraySize = size;
		}

		stackArray = new type[arraySize];
	}

	//Destructor
	~DynStack()
	{
		delete[] stackArray;
	}

	//Accessor Methods

	type top() const
	{
		if (this->empty()) throw underflow_error("Error: the stack is empty.");
		return stackArray[count - 1];
	}

	int size() const
	{
		return count;
	}

	bool empty() const
	{
		return count == 0;
	}

	int capacity() const
	{
		return arraySize;
	}

	void display() const
	{
		cout << "Attempting to display the stack..." << endl;

		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		cout << "Here's the stack, from top to bottom:" << endl;

		for(int i = count - 1; i >= 0; i--)
		{
			cout << "Element " << i << ": " << stackArray[i] << endl;
		}

		cout << endl;
	}

	//Mutator Methods
	void push(type const &data)
	{
		if (!eraseFlag)
		{
			cout << "Attempting to push \"" << data << "\"..." << endl;
		}
		
		if (count == arraySize)
		{
			type *newArray = new type[2 * arraySize];

			for (int i = 0; i < (2 * arraySize); i++)
			{
				if (i < arraySize) newArray[i] = stackArray[i];
				else newArray[i].clear();
			}

			if (!eraseFlag)
			{
				cout << "Warning: the stack is full (" << count << "/" << arraySize << ")." << endl;
				cout << "The array size has been doubled to accept " << (arraySize * 2) << " elements." << endl;
			}

			arraySize = 2 * arraySize;
			stackArray = newArray;
		}

		stackArray[count] = data;
		count++;

		if (!eraseFlag)
		{
			cout << "\"" << data << "\" pushed successfully." << endl << endl;
		}
	}

	type pop()
	{
		if (!eraseFlag)
		{
			cout << "Attempting to pop the stack..." << endl;
		}
		
		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		type temp = this->top();
		stackArray[count - 1].clear();
		count--;

		if ((((double)count / (double)arraySize) <= 0.25) && (arraySize > initialSize))
		{
			type *newArray = new type[arraySize / 2];

			for (int i = 0; i < (arraySize / 2); i++)
			{
				if (i < arraySize) newArray[i] = stackArray[i];
				else newArray[i].clear();
			}

			if (!eraseFlag)
			{
				cout << "Warning: the stack is nearly empty (" << count << "/" << arraySize << ")." << endl;
				cout << "The stack size has been halved to accept " << arraySize / 2 << " elements." << endl;
			}

			stackArray = newArray;
			arraySize = arraySize / 2;
		}

		if (!eraseFlag)
		{
			cout << "The stack has been popped successfully (Removed \"" << temp << "\")." << endl << endl;
		}
		
		return temp;
	}

	void clear()
	{
		cout << "Attempting to clear the stack..." << endl;

		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		for (int i = 0; i < arraySize; i++)
		{
			stackArray[i].clear();
		}

		count = 0;
		arraySize = initialSize;
		cout << "The stack has been cleared successfully." << endl << endl;
	}

	int erase(type const &data)
	{
		int num = 0;

		DynStack<type> temp = DynStack<type>(count);

		eraseFlag = true;
		temp.eraseFlag = true;

		cout << "Attempting to erase \"" << data << "\"..." << endl;

		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		for (int i = count - 1; i >= 0; i--)
		{
			if (data == stackArray[i])
			{
				pop();
				num++;
			}
			else
			{
				temp.push(pop());
			}
		}

		for (int i = (temp.count) - 1; i >= 0; i--)
		{
			push(temp.pop());
		}

		if (num == 1)
		{
			cout << num << " instance of \"" << data << "\" has been erased successfully." << endl << endl;
		}
		else
		{
			cout << num << " instances of \"" << data << "\" have been erased successfully." << endl << endl;
		}
		
		temp.eraseFlag = false;
		eraseFlag = false;
		return num;
	}
};