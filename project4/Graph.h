#include "BaseGraph.h"

template <class Type>
class Graph : public BaseGraph<Type>
{
	// Typedefs
	typedef DynMap<string, Vertex<Type>*> Map;
	typedef typename LinkedList<Edge<Type>>::iterator LLIterator;
	typedef typename DynMap<string, Vertex<Type>*>::iterator MapIterator;

	public:
		Graph() : BaseGraph<Type>()
		{}

		int degree(string name) 
		{
			if (!this->vertices.exists(name))
				throw underflow_error("Vertex " + name + " cannot be found");

			return this->vertices.search(name)->getDegree();
		}

		bool isConnected()
		{
			string name = this->vertices.begin()->getName();

			int BFS = this->BFS(name);
			int DFS = this->DFS(name);

			return (BFS == this->numVertices && DFS == this->numVertices);
		}

		void MST(string name) // Prim's Algorithm
		{}

		// Overloaded insert
		void insert(string name1, string name2, double weight) 
		{
			if (!this->vertices.exists(name1))
				throw underflow_error("Vertex " + name1 + " cannot be found");
				
			if (!this->vertices.exists(name2))
				throw underflow_error("Vertex " + name2 + " cannot be found");
				
			if (weight == 0) { throw invalid_argument ("Weight cannot be 0"); }

			// Create new edges
			Vertex<Type>* v1 = this->vertices.search(name1); 
			Vertex<Type>* v2 = this->vertices.search(name2);

			Edge<Type> newEdge1(v2, weight);
			Edge<Type> newEdge2(v1, weight);

			// Remove existing edge from v1 
			LLIterator it;
			for (it = v1->edges.begin(); it != v1->edges.end(); it++)
			{
				if ((*it).v == v2) { v1->edges.erase(*it); }
			}
			
			// Remove existing edge from v2
			for (it = v2->edges.begin(); it != v2->edges.end(); it++)
			{
				if ((*it).v == v1) { v2->edges.erase(*it); }
			}

			// Push edges into appropriate vertex
			v1->edges.push_back(newEdge1);
			v2->edges.push_back(newEdge2);

			this->numEdges++;
		}
};
