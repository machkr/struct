#define action(f) bind(static_cast<void (GraphDemo::*)(vector<int>&)> (&GraphDemo::f) ,this,_1)
#include "GraphDemo.h"

void GraphDemo::buildMenus() {

	mainMenu = new MenuList("Please select a graph:");
	graphMenu = new MenuList("Select an option for: Graph");
	digraphMenu = new MenuList("Select an option for: Digraph");

	mainMenu->setIsMain(true);
	mainMenu->add("Graph", MenuList::SubMenu(graphMenu), true);
	mainMenu->add("Diraph", MenuList::SubMenu(digraphMenu), true);

	graphMenu->add("Create Graph", action(createGraph));
	digraphMenu->add("Create Digraph", action(createDigraph));

}

void GraphDemo::createGraph(vector<int>& prev) {
	// Create graph
	
	graphMenu->remove("Create Graph");
	graphMenu->add("Empty", action(empty));
	graphMenu->add("Degree", action(degree));
	graphMenu->add("Edge Count", action(edgeCount));
	graphMenu->add("Is Connected", action(isConnected));
	graphMenu->add("Adjacent", action(adjacent));
	graphMenu->add("DFS", action(dfs));
	graphMenu->add("BFS", action(bfs));
	graphMenu->add("MST", action(mst));
	graphMenu->add("Build Graph From File", action(buildGraph));
	graphMenu->add("Clear", action(clear));
	graphMenu->add("Reset", action(reset));
	graphMenu->add("Insert", action(insert));
	graphMenu->add("Delete", action(del));

}

void GraphDemo::createDigraph(vector<int>& prev) {
	// Create digraph
	
	digraphMenu->remove("Create Digraph");
	digraphMenu->add("Empty", action(empty));
	digraphMenu->add("Indegree", action(indegree));
	digraphMenu->add("Outdegree", action(outdegree));
	digraphMenu->add("Edge Count", action(edgeCount));
	digraphMenu->add("Is Connected", action(isConnected));
	digraphMenu->add("Adjacent", action(adjacent));
	digraphMenu->add("DFS", action(dfs));
	digraphMenu->add("BFS", action(bfs));
	digraphMenu->add("Short Path", action(shortPath));
	digraphMenu->add("Distance", action(distance));
	digraphMenu->add("Build Digraph From File", action(buildGraph));
	digraphMenu->add("Clear", action(clear));
	digraphMenu->add("Reset", action(reset));
	digraphMenu->add("Insert", action(insert));
	digraphMenu->add("Delete", action(del));

}
