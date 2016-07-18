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
				throw underflow_error("vertex \"" + name1 + "\" cannot be found.");
				
			if (!this->vertices.exists(name2))
				throw underflow_error("vertex \"" + name2 + "\" cannot be found.");
				

			if (weight == 0) throw invalid_argument("invalid weight (0).");

			// Create new edges
			Vertex<Type>* v1 = this->vertices.search(name1); 
			Vertex<Type>* v2 = this->vertices.search(name2);

			Edge<Type> newEdge(v2, weight);

			// Remove existing edge from v1 
			LLIterator it;
			for (it = v1->edges.begin(); it != v1->edges.end(); it++)
			{
				if ((*it).v == v2) { 
					v1->edges.erase(*it); 
					break;
				}
			}
			
			// Push edges into appropriate vertex
			v1->edges.push_back(newEdge);

			this->numEdges++;
		}
		
		int indegree(string name)
		{
			if (!this->vertices.exists(name))
				throw underflow_error("vertex \"" + name + "\" cannot be found.");

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
			if (!this->vertices.exists(name))
				throw underflow_error("vertex \"" + name + "\" cannot be found.");

			Vertex<Type> *v1 = this->vertices.search(name);
			return v1->getDegree();
		}

		void shortestPath(string name1, string name2) // Djikstra's Algorithm
		{
			if (!this->vertices.exists(name1))
				throw underflow_error("vertex \"" + name1 + "\" cannot be found.");

			if (!this->vertices.exists(name2))
				throw underflow_error("vertex \"" + name2 + "\" cannot be found.");

			MapIterator it = this->vertices.begin();
			int V = this->numVertices;
			double * dist = new double[V];
			
			Vertex<Type> * origin = this->vertices.search(name1);
			Vertex<Type> * destination = this->vertices.search(name2);

			MinHeap<Vertex<Type>*> * minheap;
			minheap = new MinHeap<Vertex<Type>*>(V);

			for (int v = 0; v < V && it!= this->vertices.end(); v++)
			{
				dist[v] = 1000;
				(*minheap).insert(HeapNode<Vertex<Type>*>(dist[v], v, (*it)), v);
				it++;
			}

		

			int originKey = (*minheap).findVertex(origin);
			(*minheap).insert(HeapNode<Vertex<Type>*>(dist[originKey], originKey, origin), originKey);
			(*minheap).setPosition(originKey, originKey);
			dist[originKey] = 0;
			(*minheap).dKey(originKey, dist[originKey]);
			(*minheap).setSize(V);

			while (!(*minheap).isEmpty())
			{
				HeapNode<Vertex<Type>*> *minHeapNode = new HeapNode<Vertex<Type>*>;

				try
				{
					*minHeapNode =  (*minheap).extractMin();
				}
				catch (const underflow_error &e)
				{
					cout << "Error: " << e.what();
				}

				Vertex<Type> * temp = (*minHeapNode).getData();
				int a = (*minHeapNode).getVertex();

				//if (temp == destination) break;

				LLIterator it;

				for (it = temp->edges.begin(); it != temp->edges.end(); it++)
				{
					int b = (*minheap).findVertex((*it).v);

					if ((*minheap).isInHeap(b) && dist[a] != 1000 && (*it).weight + dist[a] < dist[b])
					{
						dist[b] = dist[a] + (*it).weight;
						(*minheap).dKey(b, dist[b]);
					}

				}

			}

			//cout << dist[(*minheap).findVertex(destination)];

			for (int i = 0; i < V; i++)
			{
				cout << i << ": " << dist[i] << endl;
			}
		}

		double distance(string name1, string name2) 
		{
			if (!this->vertices.exists(name1))
				throw underflow_error("vertex \"" + name1 + "\" cannot be found.");

			if (!this->vertices.exists(name2))
				throw underflow_error("vertex \"" + name2 + "\" cannot be found.");

			double total = 0;

			// Determine all of the edges from vertex(name1) to vertex(name2)
			// total is the sum of the weight of all edges found from above iteration

			return total;
		}

};
