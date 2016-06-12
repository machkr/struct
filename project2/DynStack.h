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
		if (this->empty()) cerr << ("Error: the stack is empty.") << endl;
		//if (this->empty()) throw underflow_error("Error: the stack is empty.");
		
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

		if (this->empty())
		{
			cerr << ("Error: the stack is empty.") << endl << endl;
			//if (this->empty()) throw underflow_error("Error: the stack is empty.");
			return;
		}


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
		cout << "Attempting to push \"" << data << "\"..." << endl;

		if (count == arraySize)
		{
			int temp = arraySize;
			arraySize = 2 * arraySize;
			type *newArray = new type[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				if (i < temp) newArray[i] = stackArray[i];
				else newArray[i] = NULL;
			}

			stackArray = newArray;
			cout << endl << "The array size has been doubled to accept " << arraySize << " elements." << endl << endl;
		}

		stackArray[count] = data;
		count++;
		cout << "\"" << data << "\" pushed successfully." << endl << endl;
	}

	type pop()
	{
		cout << "Attempting to pop the stack..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the stack is empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the stack is empty.");
			return NULL;
		}

		type temp = this->top();
		stackArray[count - 1] = NULL;
		count--;

		if ((((double)count / (double)arraySize) <= 0.25) && (arraySize > initialSize))
		{
			arraySize /= 2;
			type *newArray = new type[arraySize];

			for (int i = 0; i < arraySize; i++)
			{
				if (i < initialSize) newArray[i] = stackArray[i];
				else newArray[i] = NULL;
			}

			stackArray = newArray;
			cout << endl << "The array size has been halved to accept " << arraySize << " elements." << endl << endl;
		}

		cout << "The stack has been popped successfully (Removed \"" << temp << "\")." << endl << endl;
		return temp;
	}

	void clear()
	{
		cout << "Attempting to clear the stack..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the stack is already empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the stack is empty.");
			return;
		}

		for (int i = 0; i < arraySize; i++)
		{
			stackArray[i] = NULL;
			count--;
		}

		arraySize = initialSize;
		cout << "The stack has been cleared successfully." << endl << endl;
	}

	int erase(type const &data)
	{
		int num = 0;
		DynStack<type> temp = DynStack<type>(count);

		cout << "Attempting to erase \"" << data << "\"..." << endl;

		if (this->empty())
		{
			cerr << ("Error: the stack is empty.") << endl;
			//if (this->empty()) throw underflow_error("Error: the stack is empty.");
			return 0;
		}

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
		
		return num;
	}
};