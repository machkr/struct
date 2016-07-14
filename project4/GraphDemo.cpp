#define action(f) bind(static_cast<void (GraphDemo::*)(vector<int>&)> (&GraphDemo::f) ,this,_1)
#include "GraphDemo.h"

using namespace std;

void GraphDemo::buildMenus() {

	mainMenu = new MenuList("Please select a graph:");
	graphMenu = new MenuList("Select an option for: Graph");
	digraphMenu = new MenuList("Select an option for: Digraph");

	mainMenu->setIsMain(true);
	mainMenu->add("Graph", MenuList::SubMenu(graphMenu), true);
	mainMenu->add("Digraph", MenuList::SubMenu(digraphMenu), true);

	graphMenu->add("Create Graph", action(createGraph));
	digraphMenu->add("Create Digraph", action(createDigraph));

}

void GraphDemo::createGraph(vector<int>& prev) {

	graph = new Graph<double>();
	
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

	digraph = new Digraph<double>();
	
	digraphMenu->remove("Create Digraph");
	digraphMenu->add("Empty", action(empty));
	digraphMenu->add("Indegree", action(indegree));
	digraphMenu->add("Outdegree", action(outdegree));
	digraphMenu->add("Edge Count", action(edgeCount));
	digraphMenu->add("Is Connected", action(isConnected));
	digraphMenu->add("Adjacent", action(adjacent));
	digraphMenu->add("DFS", action(dfs));
	digraphMenu->add("BFS", action(bfs));
	digraphMenu->add("Shortest Path", action(shortestPath));
	digraphMenu->add("Distance", action(distance));
	digraphMenu->add("Build Digraph From File", action(buildGraph));
	digraphMenu->add("Clear", action(clear));
	digraphMenu->add("Reset", action(reset));
	digraphMenu->add("Insert", action(insert));
	digraphMenu->add("Delete", action(del));
}

void GraphDemo::empty(vector<int> &prev)
{
	cout << "(Empty)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
			cout << ((graph->empty()) ? "True" : "False");
			break;
		case 2: // Digraph 
			cout << ((digraph->empty()) ? "True" : "False");
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::edgeCount(vector<int> &prev)
{
	cout << "(Edge Count)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
			cout << graph->edgeCount();
			break;
		case 2: // Digraph
			cout << digraph->edgeCount();
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::adjacent(vector<int> &prev)
{
	cout << "(Adjacent)" << endl;
	BaseGraph<double>* g;

	if (prev.back() == 1)
		g = graph;
	else
		g = digraph;

	string name1;
	string name2;
	double weight;

	cout << "Vertex 1: ";
	getline(cin, name1);
	cout << "Vertex 2: ";
	getline(cin, name2);

	try
	{
		weight = g->adjacent(name1, name2);
	}
	catch (const underflow_error& e)
	{
		cout << "Error: " << e.what();
		return;
	}

	if (weight == numeric_limits<double>::max())
	{
		cout << "Weight: ∞" << endl << endl;
		return;
	}
	cout << "Weight: " << weight;
	cout << endl << endl;
}

void GraphDemo::dfs(vector<int> &prev)
{
	cout << "(DFS)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
		{
			cout << "Name: ";
			string name;
			getline(cin, name);
			try
			{ 
				cout << graph->DFS(name); 
				cout << " vertices visisted";
			}
			catch (const underflow_error& e)
			{
				cout << "Error: " << e.what();
			}
			break;
		}

		case 2: // Digraph 
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::bfs(vector<int> &prev)
{
	cout << "(BFS)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
			break;
		case 2: // Digraph 
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::buildGraph(vector<int> &prev)
{
	cout << "(Build Graph)" << endl;

	BaseGraph<double>* g;
	if (prev.back() == 1)
		g = graph;
	else 
		g = digraph;

	string fileName;
	cout << "Filename: ";
	getline(cin, fileName);
	try { 
		g->buildGraph(fileName); 
		cout << "File opened successfully";
	} catch ( const underflow_error& e) {
		cout << "Error: " << e.what(); 
	}
	
	cout << endl << endl;
}

void GraphDemo::clear(vector<int> &prev)
{
	cout << "(Clear)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
			break;
		case 2: // Digraph 
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::reset(vector<int> &prev)
{
	cout << "(Reset)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
			graph->reset();
			break;
		case 2: // Digraph 
			digraph->reset();
			break;
	}
	
	cout << "Reset successful" << endl << endl;
}

void GraphDemo::insert(vector<int> &prev)
{
	cout << "(Insert)" << endl;

	switch(prev.back()) 
	{
		case 1: // Graph
			break;
		case 2: // Digraph 
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::del(vector<int> &prev)
{
	cout << "(Delete)" << endl;
	
	switch(prev.back()) 
	{
		case 1: // Graph
			break;
		case 2: // Digraph 
			break;
	}
	
	cout << endl << endl;
}

void GraphDemo::degree(vector<int> &prev)
{
	cout << "(Degree)" << endl; // Graph only
	
	cout << endl << endl;
}

void GraphDemo::isConnected(vector<int> &prev)
{
	cout << "(Is Connected)" << endl; // Graph only

	
	cout << endl << endl;
}

void GraphDemo::mst(vector<int> &prev)
{
	cout << "(MST)" << endl; // Graph only

	
	cout << endl << endl;
}

void GraphDemo::indegree(vector<int> &prev)
{
	cout << "(In-Degree)" << endl; // Digraph only

	
	cout << endl << endl;
}

void GraphDemo::outdegree(vector<int> &prev)
{
	cout << "(Out-Degree)" << endl; // Digraph only

	
	cout << endl << endl;
}

void GraphDemo::shortestPath(vector<int> &prev)
{
	cout << "(Shortest Path)" << endl; // Digraph only

	
	cout << endl << endl;
}

void GraphDemo::distance(vector<int> &prev)
{
	cout << "(Distance)" << endl; // Digraph only

	
	cout << endl << endl;
}
