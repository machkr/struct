#include "BaseGraph.h"

template <class Type>
class Digraph : public BaseGraph<Type>
{

	// Typedefs
	typedef DynMap<string, Vertex<Type>*> Map;
	typedef typename LinkedList<Edge<Type>>::iterator LLIterator;
	typedef typename DynMap<string, Vertex<Type>*>::iterator MapIterator;

	public:

		Digraph() :
			BaseGraph<Type>()
		{}

		void insert(string name1, string name2, double weight) 
		{
			if (!this->vertices.exists(name1))
				throw underflow_error("Vertex " + name1 + " cannot be found.");
				
			if (!this->vertices.exists(name2))
				throw underflow_error("Vertex " + name2 + " cannot be found.");
				

			if (weight == 0) throw invalid_argument("Weight cannot be zero.");

			// Create new edges
			Vertex<Type>* v1 = this->vertices.search(name1); 
			Vertex<Type>* v2 = this->vertices.search(name2);

			Edge<Type> newEdge(v2, weight);

			// Remove existing edge from v1 
			LLIterator it;
			for (it = v1->edges.begin(); it != v1->edges.end(); it++)
			{
				if ((*it).v == v2) { v1->edges.erase(*it); }
			}
			
			// Push edges into appropriate vertex
			v1->edges.push_back(newEdge);

			this->numEdges++;
		}
		
		int indegree(string name) { return 0; }

		int outdegree(string name)
		{
			Vertex<Type> * v1 = this->vertices.search(name);
			return v1->getDegree();
		}

		void shortestPath(string name1, string name2) // Djikstra's Algorithm
		{}

		double distance(string name1, string name2) 
		{
			double totalWeight = 0;

			//pseudocode: determine all of the edges from vertex(name1) to vertex(name2)
			//pseudocode: totalWeight = weight of all edges found from above iteration.

			return totalWeight;
		}

};
