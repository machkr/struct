#include "BaseGraph.h"

template <class Type>
class Digraph : public BaseGraph<Type>
{

	// Typedefs
	typedef DynMap<string, Vertex<Type>*> Map;
	typedef typename LinkedList<Edge<Type>>::iterator LLIterator;
	typedef typename DynMap<string, Vertex<Type>*>::iterator MapIterator;

	public:

		Digraph() : BaseGraph<Type>()
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
		
		int indegree(string name)
		{
			int count = 0;
			LLIterator lit;
			MapIterator mit = this->vertices.begin();
			Vertex<Type> * vPointer = this->vertices.search(name);
			while (mit != this->vertices.end())
			{
				lit = mit->edges.begin();

				while (lit != mit->edges.end())
				{
					if ((*lit).v == vPointer)
					{
						count++;
					}

					lit++;
				}

				mit++;
			}

			return count;
		}


		int outdegree(string name)
		{
			Vertex<Type> *v1 = this->vertices.search(name);
			return v1->getDegree();
		}


		void shortestPath(string name1, string name2) // Djikstra's Algorithm
		{
				
			/*Vertex<Type> * v1 = this->vertices.search(name1);
			Vertex<Type> * v2 = this->vertices.search(name2);
			LLIterator lit;
			MapIterator mit = this->vertices.begin();
			Vertex<Type> destinationArray[numVertices - 1];
			Vertex<Type> finalArray[numVertices - 1];
			Vertex<Type> currentBestVertex;
			int currentBestWeight = 1000;
			int bestWeight = 1000;
			double weightArray[numVertices - 1];
			int i = 0;
			int j = 0;
			int temp = 0;

			//If both vertices are the same, we return v1. 
			if (v1 == v2)
			{
				return v1;
			}

			while (mit != this->vertices.end())
			{
				for (lit = mit->edges.begin(); lit != mit->edges.end(); lit++)
				{
					//Finds all vertices that have edges directed at Vertex v2.
					if ((*lit).v == v2))
					{
						destinationArray[i] = mit;
						i++;
					}
				}

				mit++;
			}

			temp = i;

			for (int i = 0; i <= temp; i++)
			{

			}



			mit = this->vertices.begin(); 

			temp = i;
			i = 0;
			int j = 0;

			for (i; i <= temp; i++)
			{
				while (mit != this->vertices.end())
				{
					for (lit = mit->edges.begin(); lit != mit->edges.end(); lit++)
					{
						if ((*lit).v == destinationArray[i])
						{
							finalArray[j] == destinationArray[i];
							j++;
						}
					}
				}
			}*/

		}

		double distance(string name1, string name2) 
		{
			double total = 0;

			// Determine all of the edges from vertex(name1) to vertex(name2)
			// total is the sum of the weight of all edges found from above iteration

			return total;
		}

};
