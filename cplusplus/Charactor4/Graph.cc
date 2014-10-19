#include"Graph.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

/********************private function*****************************/
void Graph::initial(int v)
{
	adj = new Vertice*[v];
	for(int i=0; i<v; i++)
		adj[i] = NULL;
}

/********************public function*****************************/
Graph::Graph(int v): V(v), E(0)
{
	initial(v);
}

Graph::Graph(In *in) //can V be const?
{
	V = in->ReadInt();
	initial(V);
	int e = in->ReadInt(); //e is the edge in file, not in graph
	for(int i=0; i<e; i++)
	{
		int v = in->ReadInt();
		int w = in->ReadInt();
		addEdge(v, w);
	}
}

int Graph::getVertices()
{
	return V;
}

int Graph::getEdges()
{
	return E;
}

void Graph::add(Vertice **v, int w)
{
	Vertice *old = *v;
	*v = new Vertice();
	(*v)->value = w;
	(*v)->next = old;
}

void Graph::addEdge(int v, int w)
{
	add(&adj[v], w);	
	add(&adj[w], v);
	E++;
}

Graph::Vertice *Graph::getAdj(int v) //type Graph is a inner class, so mustdeclare namespace front Vertice
{
	return adj[v];
}

//int main(int argc, char **argv)
//{
//	if(argc != 2)
//	{
//		cout<<"argc !=2"<<endl;
//		exit(1);
//	}
//	Graph *g = new Graph(new In(argv[1]));	
//	for(int i=0; i < g->getVertices(); i++)
//	{
//		cout<<i<<": ";	
//		Graph::Vertice *temp = g->getAdj(i);	
//		while(temp != NULL)
//		{
//			cout<<temp->value<<" ";	
//			temp = temp->next;
//		}
//		cout<<endl;
//	}
//}
