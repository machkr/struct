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

	int size() const { return count; }

	bool empty() const { return count == 0; }

	int capacity() const { return arraySize; }

	void display() const
	{
		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		for(int i = count - 1; i >= 0; i--)
		{
			cout << "Element " << i << ": " << stackArray[i] << endl;
		}

		cout << endl;
	}

	//Mutator Methods
	void push(type const &data)
	{	
		if (count == arraySize)
		{
			type *newArray = new type[2 * arraySize];

			for (int i = 0; i < (2 * arraySize); i++)
			{
				if (i < arraySize) newArray[i] = stackArray[i];
			}

			arraySize = 2 * arraySize;
			stackArray = newArray;
		}

		stackArray[count] = data;
		count++;
	}

	type pop()
	{	
		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		type temp = this->top();
		count--;

		if ((((double)count / (double)arraySize) <= 0.25) && (arraySize > initialSize))
		{
			type *newArray = new type[arraySize / 2];

			for (int i = 0; i < (arraySize / 2); i++)
			{
				if (i < arraySize) newArray[i] = stackArray[i];
			}

			stackArray = newArray;
			arraySize = arraySize / 2;
		}

		return temp;
	}

	void clear()
	{
		if (this->empty()) throw underflow_error("Error: the stack is empty.");

		count = 0;
		arraySize = initialSize;
	}

	int erase(type const &data)
	{
		int num = 0;

		DynStack<type> temp = DynStack<type>(count);

		eraseFlag = true;
		temp.eraseFlag = true;

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

		temp.eraseFlag = false;
		eraseFlag = false;
		return num;
	}
};
