#pragma once
#include <iostream>

using namespace std;

template<class type> class HeapNode
{
private:
	double key;
	int vertex;
	type data;

public:
	HeapNode(double _key, int _vertex, type _data) : key(_key), vertex(_vertex), data(_data) {}
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

	type getData()
	{
		return data;
	}

	void setData(type _data)
	{
		data = _data;
	}
};