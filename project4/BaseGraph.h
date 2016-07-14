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
class BaseGraph
{
	protected:
		// Typedefs
		typedef DynMap<string, Vertex<Type>*> Map;
		typedef typename LinkedList<Edge<Type>>::iterator LLIterator;
		typedef typename DynMap<string, Vertex<Type>*>::iterator MapIterator;

		Map vertices;
		int numVertices;
		int numEdges;
		
	public:
		BaseGraph() : 
			vertices(0.68),
			numVertices(0),
			numEdges(0)
		{}

		bool empty() { return numVertices == 0; }

		int edgeCount() { return numEdges; }

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
				if ((*it).v == v2) 
					return (*it).weight;
			}

			// Max value of double == infinity
			return numeric_limits<double>::max();
		}

		int DFS(string name) 
		{
			DynStack<Vertex<Type>*> stack;
			int count = 0;

			if (!vertices.exists(name)) 
				throw underflow_error("Vertex " + name + " cannot be found");

			// Push first vertex onto stack
			stack.push(vertices.search(name));
			
			outer:
			while (!stack.empty()) 
			{
				Vertex<Type>* v = stack.top();
				
				// Visit vertex at top of stack
				if (!v->isVisited()) 
				{
					cout << v->getName() << " " << v->getData() << endl;
					v->setVisited(true);
					count++;
				}	

				// Push next unvisited child onto stack
				LLIterator it;
				for (it = v->edges.begin(); it != v->edges.end(); it++) 
				{
					if (!(*it).v->isVisited()) 
					{ 
						stack.push((*it).v);
						goto outer; // Continue while loop
					}
				}

				// Remove vertex from stack if it has no unvisited children
				stack.pop();
			}
			return count;

		}

		void BFS(string name)
		{
			
		}

		void buildGraph(string fileName) 
		{
			ifstream file;
			file.open(fileName, ios::in);

			if (!file)
				throw underflow_error("Error opening file: " + fileName);

			// Read vertices from file
			int l = 0;
			string line;
			while(getline(file, line)) 
			{
				l++;
				string name;
				double data; 
				string dataStr;

				istringstream ss(line);

				// Read name and data, insert new vertex
				if (getline(ss, name, ',') && getline(ss, dataStr, ';')) {
					data = stod(dataStr);
					insertVertex(name, data);
				}
			}

			// Return to beginning of file
			file.clear();
			file.seekg(0, ios::beg);

			// Read edges from file
			l = 0;
			while(getline(file, line))
			{
				l++;
				string name1;

				istringstream ss(line);
				if (!getline(ss, name1, ',')) 
					continue;

				// Ignore anything after name1 until it hits the ';'
				ss.ignore(numeric_limits<streamsize>::max(), ';');
				ss.ignore();
				
				// Get each edge name and weight and insert it into the graph
				string weightStr;
				string name2;
				double weight;
				while (getline(ss, weightStr, ' '))
				{
					weight = stod(weightStr);
					getline(ss, name2, ',');
					ss.ignore();

					// If name2 vertex doesn't exist, throw error w/ line number
					if (!vertices.exists(name2)) {
						ostringstream errorSs;
						errorSs << "Parse error on line " << l << ": \"" << 
							name2 << "\" vertex does not exist";
						throw underflow_error(errorSs.str());
					}

					// Insert edge
					insert(name1, name2, weight);
				}
				
			}
		}

		void clear() {}

		void reset() 
		{
			MapIterator it;
			for (it = vertices.begin(); it != vertices.end(); it++)
			{
				if (it->visited)
					it->visited = false;
			}
		
		}

		void del(string name)
		{
			LLIterator lit;
			MapIterator mit;

			for (mit = vertices.begin(); mit != vertices.end; mit++)
			{
				for(lit = (*mit).v)
			}
		}

		void insertVertex(string name, Type data)
		{
			vertices.insert(name, new Vertex<Type>(name, data));
			numVertices++;
		}

		virtual void insert(string name1, string name2, double weight) = 0;
};
