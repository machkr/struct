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
		{
			MapIterator it;
			it = this->vertices.begin();

			int V = this->numVertices;
			int *MST = new int [V];
			double *key = new double [V];

			Vertex<Type> * root = this->vertices.search(name);
			MinHeap<Vertex<Type>*> *minheap;
			minheap = new MinHeap<Vertex<Type>*>(V);

			for (int v = 1; v < V; ++v)
			{
				MST[v] = -1;
				key[v] = 1000;

				while(it != this->vertices.end())
				{
					HeapNode<Vertex<Type>*> *node = new HeapNode<Vertex<Type>*>(key[v], v, (*it));
					if (!((*it) == root)) (*minheap).insert(*node, v);
					it++;
					break;
				}
			}

			key[0] = 0;
			(*minheap).insert(HeapNode<Vertex<Type>*>(key[0], 0, root), 0);
			(*minheap).setPosition(0,0);

			(*minheap).setSize(V);

			while (!(*minheap).isEmpty())
			{
				HeapNode<Vertex<Type>*> *minHeapNode = new HeapNode<Vertex<Type>*>;

				try
				{
					*minHeapNode = (*minheap).extractMin();
				}
				catch (const underflow_error &e)
				{
					cout << "Error: " << e.what();
				}

				Vertex<Type>* temp = (*minHeapNode).getData();
				int a = (*minHeapNode).getVertex();

				LLIterator it;
				for (it = temp->edges.begin(); it != temp->edges.end(); it++)
				{
					int b = (*minheap).findVertex((*it).v);
					if ((*minheap).isInHeap(b) && (*it).weight < key[b])
					{
						key[b] = (*it).weight;
						MST[b] = a;
						(*minheap).dKey(b, key[b]);
					}
				}

			}

			// Add display for minimum spanning tree
		}

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
