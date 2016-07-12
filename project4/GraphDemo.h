#include <iostream>
#include <string>
#include "MenuList.h"

class GraphDemo {
	private: 
		// Graph * graph;
		// Digraph * digraph;
		
		MenuList * mainMenu;
		MenuList * graphMenu;
		MenuList * digraphMenu;

		void createGraph(vector<int>& prev);
		void createDigraph(vector<int>& prev);
		
		// Common
		void empty(vector<int> &prev) {};
		void edgeCount(vector<int> &prev) {};
		void adjacent(vector<int> &prev) {};
		void dfs(vector<int> &prev) {};
		void bfs(vector<int> &prev) {};
		void buildGraph(vector<int> &prev) {};
		void clear(vector<int> &prev) {};
		void reset(vector<int> &prev) {};
		void insert(vector<int> &prev) {};
		void del(vector<int> &prev) {};
		
		// Graph
		void degree(vector<int> &prev) {};
		void isConnected(vector<int> &prev) {};
		void mst(vector<int> &prev) {};

		// Digraph
		void indegree(vector<int> &prev) {};
		void outdegree(vector<int> &prev) {};
		void shortPath(vector<int> &prev) {};
		void distance(vector<int> &prev) {};

		void buildMenus();

	public: 
		void run() {
			buildMenus();
			mainMenu->run();
		}
};
