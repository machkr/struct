#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include "Vertex.h"
#include "Edge.h"
#include "DynMap.h"
#include "LinkedList.h"
#include "DynStack.h"
#include "SimpleQueue.h"

using namespace std;

template <class Type> 
class Graph
{
	friend class Vertex<Type>;

	typedef typename LinkedList<Edge<Type>>::iterator LLIterator;
	typedef DynMap<string, Vertex<Type>*> Map;
	typedef typename DynMap<string, Vertex<Type>*>::iterator MapIterator;

	private:
		Map vertices;
		int numVertices;
		int numEdges;

	public:
		Graph() : 
			vertices(0.68),
			numVertices(0),
			numEdges(0)
		{}

		bool empty() { return numVertices == 0; }

		int degree(string name) 
		{
			if (!vertices.exists(name))
				throw underflow_error("Vertex " + name + " cannot be found");

			return vertices.search(name)->degree();
		}

		int edgeCount() { return numEdges; }

		bool isConnected() {}

		double adjacent( string name1, string name2 )
		{
			// Find vertices
			if (!vertices.exists(name1))
				throw underflow_error("Vertex " + name1 + " cannot be found");
				
			if (!vertices.exists(name2))
				throw underflow_error("Vertex " + name2 + " cannot be found");

			Vertex<Type>* v1 = vertices.search(name1);
			Vertex<Type>* v2 = vertices.search(name2);

			if (v1 == v2) 
				return 0;

			// Look to see if edge exists
			LLIterator it;
			for (it = v1->edges.begin(); it != v1->edges.end(); it++) 
			{
				if (it->v == v2) 
					return it->weight;
			}

			// 1000 represents infinity. No connection between v1 and v2
			return 1000;
		}

		void DFS(string name) {
			DynStack<Vertex<Type>*> stack;
			if (!vertices.exists(name)) 
				throw underflow_error("Vertex " + name + " doesn't exist");

			stack.push(vertices.search(name));
			
			outer:
			while (!stack.empty()) {

				Vertex<Type>* v = stack.top();
				
				// Visit
				if (!v->isVisited()) {
					cout << v->getName() << " " << v->getData() << endl;
					v->setVisited(true);
				}	

				// Push child to stack
				LLIterator it;
				for (it = v->edges.begin(); it != v->edges.end(); it++) {
					if (!(*it).v->isVisited()) { 
						stack.push((*it).v);
						goto outer; // Continue while loop
					}
				}
				stack.pop();
			}

		}

		void BFS(string name) {}

		void MST(string name) {}

		void buildGraph(string fileName) 
		{
			ifstream file;
			file.open(fileName, ios::in);

			if (!file)
				throw underflow_error("Error opening file: " + fileName);

			// Read vertices
			int l = 0;
			string line;
			while(getline(file, line)) 
			{
				l++;
				string name;
				double data; 
				string dataStr;

				istringstream ss(line);

				if (getline(ss, name, ',') && getline(ss, dataStr, ';')) {
					data = stod(dataStr);
					insertNode(name, data);
				}
			}

			// Return to beginning of file
			file.clear();
			file.seekg(0, ios::beg);

			// Read edges
			l = 0;
			while(getline(file, line))
			{
				l++;
				string name1;

				istringstream ss(line);
				if (!getline(ss, name1, ',')) 
					continue;
				Vertex<Type>* v1 = vertices.search(name1);

				ss.ignore(numeric_limits<streamsize>::max(), ';');
				ss.ignore();
				
				string weightStr;
				string name2;
				double weight;
				while (getline(ss, weightStr, ' '))
				{
					weight = stod(weightStr);
					getline(ss, name2, ',');
					ss.ignore();

					if (!vertices.exists(name2)) {
						ostringstream errorSs;
						errorSs << "Parse error on line " << l << ": " << name2 << " vertex does not exist";
						throw underflow_error(errorSs.str());
					}

					insert(name1, name2, weight);
				}
				
			}
		}

		void clear() {}

		void reset() 
		{
			MapIterator it;
			for(it = vertices.begin(); it != vertices.end(); it++) {
				if (it->visited)
					it->visited = false;
			}
		
		}

		void insert(string name1, string name2, double weight) 
		{

			if (!vertices.exists(name1))
				throw underflow_error("Vertex " + name1 + " cannot be found");
				
			if (!vertices.exists(name2))
				throw underflow_error("Vertex " + name2 + " cannot be found");
				

			if (weight == 0 )
				throw invalid_argument("Weight cannot be 0");

			Vertex<Type>* v1 = vertices.search(name1); 
			Vertex<Type>* v2 = vertices.search(name2);

			Edge<Type> newEdge(v2, weight);

			// Remove existing edge 
			LLIterator it;
			for (it = v1->edges.begin(); it != v1->edges.end(); it++) {
				if ((*it).v == v2) {
					v1->edges.erase(*it);
				}
			}

			v1->edges.push_front(newEdge);

			numEdges++;
		
		}

		void insertNode(string name, Type data) 
		{
			vertices.insert(name, new Vertex<Type>(name, data));
			numVertices++;
		}


		void del(string name) {}

};

		

			

	



