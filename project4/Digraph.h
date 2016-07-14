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
				throw underflow_error("Vertex " + name1 + " cannot be found");
				
			if (!this->vertices.exists(name2))
				throw underflow_error("Vertex " + name2 + " cannot be found");
				

			if (weight == 0 )
				throw invalid_argument("Weight cannot be 0");

			// Create new edges
			Vertex<Type>* v1 = this->vertices.search(name1); 
			Vertex<Type>* v2 = this->vertices.search(name2);

			Edge<Type> newEdge(v2, weight);

			// Remove existing edge from v1 
			LLIterator it;
			for (it = v1->edges.begin(); it != v1->edges.end(); it++) {
				if ((*it).v == v2) {
					v1->edges.erase(*it);
				}
			}
			
			// Push edges into appropriate vertex
			v1->edges.push_back(newEdge);

			this->numEdges++;
		}

		void del(string name) {}
		
		int indegree(string name) {}

		int outdegree(string name) {}

		void shortPath(string name1, string name2) {}

		double distance(string name1, string name2) {}

};


