#define action(f) bind(static_cast<void (GraphDemo::*)(vector<int>&)> (&GraphDemo::f) ,this,_1)
#include "GraphDemo.h"

using namespace std;

void GraphDemo::buildMenus()
{

	mainMenu = new MenuList("Please select a graph:");
	graphMenu = new MenuList("Please choose an action for: Graph");
	digraphMenu = new MenuList("Please choose an action for: Digraph");

	graphAccessMenu = new MenuList("Please choose an accessor method: Graph");
	digraphAccessMenu = new MenuList("Please choose an accessor method: Digraph");

	graphMutateMenu = new MenuList("Please choose a mutator method: Graph");
	digraphMutateMenu = new MenuList("Please choose a mutator method: Digraph");

	graphTraverseMenu = new MenuList("Please choose a traversal method: Graph");
	digraphTraverseMenu = new MenuList("Please choose a traversal method: Digraph");

	mainMenu->setIsMain(true);
	mainMenu->add("Graph", MenuList::SubMenu(graphMenu), true);
	mainMenu->add("Digraph", MenuList::SubMenu(digraphMenu), true);

	graphMenu->add("Create Graph", action(createGraph));
	digraphMenu->add("Create Digraph", action(createDigraph));

}

void GraphDemo::createGraph(vector<int>& prev)
{
	graph = new Graph<double>();
	
	graphMenu->remove("Create Graph");
	graphMenu->add("Access", MenuList::SubMenu(graphAccessMenu), true);
	graphMenu->add("Mutate", MenuList::SubMenu(graphMutateMenu), true);
	graphMenu->add("Traverse", MenuList::SubMenu(graphTraverseMenu), true);

	graphAccessMenu->add("Empty", action(empty));
	graphAccessMenu->add("Degree", action(degree));
	graphAccessMenu->add("Edge Count", action(edgeCount));
	graphAccessMenu->add("Is Connected", action(isConnected));
	graphAccessMenu->add("Adjacent", action(adjacent));

	graphMutateMenu->add("Build Graph From File", action(buildGraph));
	graphMutateMenu->add("Clear", action(clear));
	graphMutateMenu->add("Reset", action(reset));
	graphMutateMenu->add("Insert", action(insert));
	graphMutateMenu->add("Delete", action(del));

	graphTraverseMenu->add("DFS", action(dfs));
	graphTraverseMenu->add("BFS", action(bfs));
	graphTraverseMenu->add("MST", action(mst));
}

void GraphDemo::createDigraph(vector<int>& prev)
{
	digraph = new Digraph<double>();
	
	digraphMenu->remove("Create Digraph");
	digraphMenu->add("Access", MenuList::SubMenu(digraphAccessMenu), true);
	digraphMenu->add("Mutate", MenuList::SubMenu(digraphMutateMenu), true);
	digraphMenu->add("Traverse", MenuList::SubMenu(digraphTraverseMenu), true);

	digraphAccessMenu->add("Empty", action(empty));
	digraphAccessMenu->add("Indegree", action(indegree));
	digraphAccessMenu->add("Outdegree", action(outdegree));
	digraphAccessMenu->add("Edge Count", action(edgeCount));
	digraphAccessMenu->add("Is Connected", action(isConnected));
	digraphAccessMenu->add("Adjacent", action(adjacent));
	digraphAccessMenu->add("Distance", action(distance));

	digraphMutateMenu->add("Build Digraph From File", action(buildGraph));
	digraphMutateMenu->add("Clear", action(clear));
	digraphMutateMenu->add("Reset", action(reset));
	digraphMutateMenu->add("Insert", action(insert));
	digraphMutateMenu->add("Delete", action(del));

	digraphTraverseMenu->add("DFS", action(dfs));
	digraphTraverseMenu->add("BFS", action(bfs));
	digraphTraverseMenu->add("Shortest Path", action(shortestPath));
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

	if (prev.back() == 1) g = graph;
	else g = digraph;

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

	BaseGraph<double> * g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	string name;
	cout << "Name: ";
	getline(cin, name);
	
	try
	{
		cout << g->DFS(name);
		cout << " vertices visited.";
	}
	catch (const underflow_error& e)
	{
		cout << "Error: " << e.what();
	}
	
	cout << endl << endl;
}

void GraphDemo::bfs(vector<int> &prev)
{
	cout << "(BFS)" << endl;

	BaseGraph<double> * g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	string name;
	cout << "Name: ";
	getline(cin, name);

	try
	{
		cout << g->DFS(name);
		cout << " vertices visited.";
	}
	catch (const underflow_error& e)
	{
		cout << "Error: " << e.what();
	}

	cout << endl << endl;
}

void GraphDemo::buildGraph(vector<int> &prev)
{
	cout << "(Build Graph)" << endl;

	BaseGraph<double> * g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	string fileName;
	cout << "Filename: ";
	getline(cin, fileName);

	try
	{ 
		g->buildGraph(fileName); 
		cout << "File opened successfully.";
	}
	catch ( const underflow_error& e)
	{
		cout << "Error: " << e.what(); 
	}
	
	cout << endl << endl;
}

void GraphDemo::clear(vector<int> &prev)
{
	cout << "(Clear)" << endl;

	BaseGraph<double>* g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	try
	{
		g->clear();
		cout << "Cleared successfully.";
	}
	catch(const underflow_error& e)
	{
		cout << "Error: " << e.what();
	}

	cout << endl << endl;
}

void GraphDemo::reset(vector<int> &prev)
{
	cout << "(Reset)" << endl;

	BaseGraph<double> * g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	try
	{
		g->reset();
		cout << "Reset successfully.";
	}
	catch (const underflow_error& e)
	{
		cout << "Error: " << e.what() << endl << endl;
	}
	
	cout << endl << endl;
}

void GraphDemo::insert(vector<int> &prev)
{
	cout << "(Insert)" << endl;

	string v1;
	string v2;
	double weight;

	cout << "Vertex 1: ";
	getline(cin, v1);
	cout << "Vertex 2: ";
	getline(cin, v2);
	cout << "Weight: ";
	cin >> weight;
	cin.ignore();

	BaseGraph<double> * g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	try
	{
		g->insert(v1,v2,weight);
		cout << "Edge inserted successfully.";
	}
	catch (const underflow_error& e)
	{
		cout << "Error: " << e.what();
	}

	cout << endl << endl;
}

void GraphDemo::del(vector<int> &prev)
{
	cout << "(Delete)" << endl;
	
	BaseGraph<double> * g;
	if (prev.back() == 1) g = graph;
	else g = digraph;

	string name;
	cout << "Name: ";
	getline(cin, name);

	try
	{
		g->del(name);
		cout << name << "deleted successfully.";
	}
	catch(const underflow_error& e)
	{
		cout << "Error: " << e.what();
	}
	
	cout << endl << endl;
}

void GraphDemo::degree(vector<int> &prev)
{
	cout << "(Degree)" << endl; // Graph only
	
	string name;
	cout << "Name: ";
	getline(cin, name);

	cout << graph->degree(name);

	cout << endl << endl;
}

void GraphDemo::isConnected(vector<int> &prev)
{
	cout << "(Is Connected)" << endl; // Graph only
	
	cout << ((graph->isConnected()) ? "True" : "False");

	cout << endl << endl;
}

void GraphDemo::mst(vector<int> &prev)
{
	cout << "(MST)" << endl; // Graph only

	string name;
	cout << "Name: ";
	getline(cin, name);
	
	try
	{
		graph->MST(name);
	}
	catch (const invalid_argument& i)
	{
		cout << "Error: " << i.what();
	}

	cout << endl << endl;
}

void GraphDemo::indegree(vector<int> &prev)
{
	cout << "(In-Degree)" << endl; // Digraph only

	string name;
	cout << "Name: ";
	getline(cin, name);

	try
	{
		cout << digraph->indegree(name);
	}
	catch (const invalid_argument& i)
	{
		cout << "Error: " << i.what();
	}
	
	cout << endl << endl;
}

void GraphDemo::outdegree(vector<int> &prev)
{
	cout << "(Out-Degree)" << endl; // Digraph only
	
	string name;
	cout << "Name: ";
	getline(cin, name);

	try
	{
		cout << digraph->outdegree(name);
	}
	catch (const invalid_argument& i)
	{
		cout << "Error: " << i.what();
	}

	cout << endl << endl;
}

void GraphDemo::shortestPath(vector<int> &prev)
{
	cout << "(Shortest Path)" << endl; // Digraph only
	
	string name1;
	string name2;

	cout << "Vertex 1: ";
	getline(cin, name1);
	cout << "Vertex 2: ";
	getline(cin, name2);

	try
	{
		digraph->shortestPath(name1, name2);
	}
	catch (const invalid_argument& i)
	{
		cout << "Error: " << i.what();
	}

	cout << endl << endl;
}

void GraphDemo::distance(vector<int> &prev)
{
	cout << "(Distance)" << endl; // Digraph only

	string name1;
	string name2;

	cout << "Vertex 1: ";
	getline(cin, name1);
	cout << "Vertex 2: ";
	getline(cin, name2);

	try
	{
		cout << digraph->distance(name1, name2);
	}
	catch(const invalid_argument& i)
	{
		cout << "Error: " << i.what();
	}

	cout << endl << endl;
}