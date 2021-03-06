#include "Graph.h"

int main(int numArgs, char** args)
{
	Graph* graph = new Graph();

	//float temp = 0;

	Graph::Node *a, *b, *c, *d, *e, *f;// , *g, *h, *i, *j;

	/*Graph::Node *a(Vector2(temp));
	temp += 10.f;
	Graph::Node *b(Vector2(temp));
	temp += 10.f;
	Graph::Node *c(Vector2(temp));
	temp += 10.f;
	Graph::Node *d(Vector2(temp));
	temp += 10.f;
	Graph::Node *e(Vector2(temp));
	temp += 10.f;
	Graph::Node *f(Vector2(temp));
	temp += 10.f;
	Graph::Node *g(Vector2(temp));
	temp += 10.f;
	Graph::Node *h(Vector2(temp));
	temp += 10.f;
	Graph::Node *i(Vector2(temp));
	temp += 10.f;
	Graph::Node *j(Vector2(temp));*/


	a = graph->AddNode(10, 10);	//Exercise Node 0
	b = graph->AddNode(12, 10);	//Exercise Node 1
	c = graph->AddNode(12, 13);	//Exercise Node 2
	d = graph->AddNode(12, 14);	//Exercise Node 3
	e = graph->AddNode(11, 17);	//Exercise Node 4
	f = graph->AddNode(10, 15);	//Exercise Node 5

	graph->AddConnection(a, b);
	graph->AddConnection(b, c);
	graph->AddConnection(a, c);
	graph->AddConnection(a, f);
	graph->AddConnection(c, d);
	graph->AddConnection(d, f);
	graph->AddConnection(d, e);
	graph->AddConnection(f, e);

	//a = graph->AddNode(temp, temp);
	////temp += 10.f;
	//b = graph->AddNode(temp, temp);
	////emp += 10.f;
	//c = graph->AddNode(temp, temp);
	////temp += 10.f;
	//d = graph->AddNode(temp, temp);
	////temp += 10.f;
	//e = graph->AddNode(temp, temp);
	////temp += 10.f;
	//f = graph->AddNode(temp, temp);
	//temp += 10.f;
	//g = graph->AddNode(temp, temp);
	//temp += 10.f;
	//h = graph->AddNode(temp, temp);
	//temp += 10.f;
	//i = graph->AddNode(temp, temp);
	//temp += 10.f;
	//j = graph->AddNode(temp, temp);

	//graph->AddConnection(a, b);
	//graph->AddConnection(a, d);
	//graph->AddConnection(a, e);
	//graph->AddConnection(b, c);
	//graph->AddConnection(d, h);
	//graph->AddConnection(e, h);
	//graph->AddConnection(e, f);
	//graph->AddConnection(f, c);
	//graph->AddConnection(f, j);
	//graph->AddConnection(g, c);
	//graph->AddConnection(g, j);
	//graph->AddConnection(i, j);
	//graph->AddConnection(i, h);


	//graph->PrintBFS(a);
	//printf("\n");
	//graph->PrintDFS(a);

//	graph->TraverseGraph(a, true);
//	printf("\n");
//	graph->TraverseGraph(a, false);

	std::list<Graph::Node*>	potEndNodes;
	potEndNodes.push_back(e);

	graph->FindDijkstrasPath(a, potEndNodes);

	printf("\n");
	system("pause");


	delete graph;

	return 0;
}