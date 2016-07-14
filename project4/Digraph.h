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

		void insert(string name1, string name2, double weight) {}

		void del(string name) {}
		
		int indegree(string name) {}

		int outdegree(string name) {}

		void shortPath(string name1, string name2) {}

		double distance(string name1, string name2) {}

};


