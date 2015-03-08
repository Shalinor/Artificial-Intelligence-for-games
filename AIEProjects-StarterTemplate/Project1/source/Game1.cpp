#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#include "Graph.h"

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	//t = new Texture("./Images/nodeTexture.png");//box0_256.png");
	t1 = new Texture("./Images/yellowBox_16.png");
	t2 = new Texture("./Images/redBox_16.png");

	graph = new Graph(true);

	/*
	Node* node1 = new Node(vec3(10, 100, 0), t1, t2);	//Jason has each node having an int id
	Node* node2 = new Node(vec3(50, 50, 0), t1, t2);
	Node* node3 = new Node(vec3(100, 230, 0), t1, t2);
	Node* node4 = new Node(vec3(150, 150, 0), t1, t2);

	graph->AddNode(node1);
	graph->AddNode(node2);
	graph->AddNode(node3);
	graph->AddNode(node4);

	graph->AddEdge(node1, node3);
	graph->AddEdge(node1, node4);
	graph->AddEdge(node3, node2);
	*/

	//Attempting to duplicate the slide's 6 node graph

	Node* node1 = new Node(vec3(100, 50, 0), t1, t2);
	Node* node2 = new Node(vec3(200, 50, 0), t1, t2);
	Node* node3 = new Node(vec3(200, 100, 0), t1, t2);
	Node* node4 = new Node(vec3(200, 150, 0), t1, t2);
	Node* node5 = new Node(vec3(150, 200, 0), t1, t2);
	Node* node6 = new Node(vec3(100, 150, 0), t1, t2);

	graph->AddNode(node1);
	graph->AddNode(node2);
	graph->AddNode(node3);
	graph->AddNode(node4);
	graph->AddNode(node5);
	graph->AddNode(node6);

	graph->AddEdge(node1, node2);
	graph->AddEdge(node2, node3);
	graph->AddEdge(node3, node1);
	graph->AddEdge(node3, node4);
	graph->AddEdge(node4, node5);
	graph->AddEdge(node4, node6);
	graph->AddEdge(node1, node6);
	graph->AddEdge(node6, node5);

	graph->DisplayToConsole();


	//graph->RemoveNode(node1);

	//graph->RemoveEdge(node1, node2);

	//std::cout << "\n\n";

	//graph->DisplayToConsole();
	
}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	
	delete graph;
}


void Game1::Update(float deltaTime)
{
	graph->Update(t1, t2);
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// TODO: draw stuff.

//	graph->DisplayToScreen(m_spritebatch, t);
	graph->DisplayToScreen(m_spritebatch);

	//graph->TraverseDFS();
	graph->TraverseBFS();

/*	m_spritebatch->DrawSprite(t, 300.f, 300.f, 64.f, 64.f, 3.14f);

	m_spritebatch->SetRenderColor(255, 0, 0, 255);
	m_spritebatch->DrawLine(30.f, 30.f, 300.f, 200.f, 1.f);
*/
	m_spritebatch->End();

}