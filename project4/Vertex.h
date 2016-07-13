#pragma once
#include <string>
#include "LinkedList.h"
#include "Edge.h"

using namespace std;

template <class Type>
class Vertex 
{
	private:
		string name;
		Type data;
		bool visited;
		LinkedList<Edge<Type>> edges;
	
	public:
		Vertex(string name_, Type data_) :
			name(name_),
			data(data_),
			visited(false)
		{}

		int getDegree() { return edges.getSize(); }
		
		string getName() { return name; }

		Type getData() { return data; }

};


