#include "BaseGraph.h"
#include "MinHeap.h"





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
			MapIterator it = this->vertices.begin();
			int V = this->numVertices;
			int * distance = new int[V];

			Vertex<Type> * origin = this->vertices.search(name1);
			Vertex<Type> * destination = this->vertices.search(name2);

			MinHeap<Vertex<Type>*> * minheap;
			minheap = new MinHeap<Vertex<Type>*>(V);

			for (int v = 0; v < V; ++v)
			{
				distance[v] = 1000;

				HeapNode<Vertex<Type>*> * node = new HeapNode<Vertex<Type>*>(distance[v], v, (*it));
				it++;
			}

			int originKey = (*minheap).findVertex(origin);
			(*minheap).insert(HeapNode<Vertex<Type>*>(distance[originKey], originKey, origin), originKey);
			(*minheap).setPosition(originKey, originKey);
			distance[originKey] = 0;
			(*minheap).dKey(originKey, distance[originKey]);
			(*minheap).setSize(V);


			while (!(*minheap).isEmpty())
			{
				HeapNode<Vertex<Type>*> *minHeapNode = new HeapNode<Vertex<Type>*>;

				try
				{
					*minHeapNode = (*minheap).extractMin<Type>();
				}
				catch (const underflow_error &e)
				{
					cout << "Error: " << e.what();
				}

				Vertex<Type> * temp = (*minHeapNode).getData();
				int a = (*minHeapNode).getVertex();

				LLIterator checker;

				for (checker = temp->edges.begin(); checker != temp->edges.end(); checker++)
				{
					int vertexNumber = (*minheap).findVertex((*checker).v);

					if ((*minheap).isInHeap(vertexNumber) && distance[a] != 1000 && (*checker).weight + distance[a] < distance[vertexNumber])
					{
						distance[vertexNumber] = distance[a] + (*checker).weight;
						(*minheap).dKey(vertexNumber, distance[vertexNumber]);
					}

				}
			}
		}

		double distance(string name1, string name2) 
		{
			double total = 0;

			// Determine all of the edges from vertex(name1) to vertex(name2)
			// total is the sum of the weight of all edges found from above iteration

			return total;
		}

};
