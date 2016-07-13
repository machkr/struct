#pragma once
#include <string>
#include "Vertex.h"
#include "Edge.h"
#include "DynMap.h"
#include "LinkedList.h"

using namespace std;

template <class Type> 
class Graph
{
	friend class Vertex<Type>;

	typedef typename LinkedList<Edge<Type>>::iterator LLIterator;
	typedef DynMap<string, LinkedList<Edge<Type>>> Map;
	typedef typename DynMap<string, LinkedList<Edge<Type>>>::iterator MapIterator;

	private:
		Map vertices;
		int numVertices;
		int numEdges;

	public:
		Graph() {};

		bool empty() { return numVertices == 0; }

		int degree(string name) 
		{
			Vertex<Type> v;
			try { v = vertices.search(name); }
			catch(const underflow_error& e) { 
				throw underflow_error("Vertex " + name + " cannot be found");
			}

			return v.degree();
		}

		int edgeCount() { return numEdges; }

		bool isConnected() {}

		double adjacent( string name1, string name2 )
		{
			// Find vertices
			Vertex<Type> v1;
			Vertex<Type> v2;
			try { v1 = vertices.search(name1); }
			catch (const underflow_error& e) {
				throw underflow_error("Vertex " + name1 + " cannot be found");
			}
				
			try { v2 = vertices.search(name2); }
			catch (const underflow_error& e) {
				throw underflow_error("Vertex " + name2 + " cannot be found");
			}

			if (v1 == v2) 
				return 0;

			// Look to see if edge exists
			LLIterator it;
			for (it = v1.edges.begin(); it != v1.edges.end(); it++) 
			{
				if (it->v == &v2) 
					return it->weight;
			}

			// 1000 represents infinity. No connection between v1 and v2
			return 1000;
		}

		void DFS(string name) {}

		void BFS(string name) {}

		void MST(string name) {}

		void buildGraph() {}

		void clear() {}

		void reset() {
			MapIterator it = vertices.begin();
			for(it = vertices.begin(); it != vertices.end(); it++) {
				if (it->visited)
					it->visited = false;
			}
		
		}

		void insert(string name1, string name2, double weight) {}

		void del(string name) {}

};

		

			

	



