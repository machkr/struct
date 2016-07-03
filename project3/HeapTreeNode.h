#include <iostream>

using namespace std;

template<class type> class HeapTreeNode
{
private:
	int key;
	type data;

public:
	HeapTreeNode(int key, type data) : key(key), data(data) {}
	HeapTreeNode() {}

	~HeapTreeNode() {}

	int getKey()
	{
		return key;
	}

	type getData()
	{
		return data;
	}
};