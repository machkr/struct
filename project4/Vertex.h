#pragma once
#include <string>
#include "LinkedList.h"
#include "Edge.h"

using namespace std;

template <class Type>
class Graph;

template <class Type>
class Vertex 
{
	friend class Graph<Type>;

	private:
		string name;
		Type data;
		bool visited;
	
	public:
		Vertex(string name_, Type data_) :
			name(name_),
			data(data_),
			visited(false)
		{}

		int getDegree() { return edges.getSize(); }
		
		string getName() { return name; }

		Type getData() { return data; }

		bool isVisited() { return visited; }

		void setVisited(bool value) { visited = value; }

		LinkedList<Edge<Type>> edges;
};


