#pragma once
#include <iostream>

using namespace std;

template<class HeapType> class HeapNode
{
private:
	double key;
	int vertex;
	HeapType data;

public:
	HeapNode(double _key, int _vertex, HeapType _data) : key(_key), vertex(_vertex), data(_data) {}
	HeapNode() {}

	~HeapNode() {}

	double getKey()
	{
		return key;
	}

	void setKey(double _key)
	{
		key = _key;
	}

	int getVertex()
	{
		return vertex;
	}

	void setVertex(int _vertex)
	{
		vertex = _vertex;
	}

	HeapType getData()
	{
		return data;
	}

	void setData(HeapType _data)
	{
		data = _data;
	}
};
