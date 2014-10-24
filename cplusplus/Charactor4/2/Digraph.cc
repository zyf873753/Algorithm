#include"Digraph.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

void Digraph::initial(int v)
{
	adj = new Vertice*[v];
	for(int i=0; i<v; i++)
		adj[i] = NULL;
}

Digraph::Digraph(int v): V(v), E(0)
{
	initial(v);	
}

Digraph::Digraph(In *in)
{
	 V = in->ReadInt();
	 initial(V);
	 int e = in->ReadInt();
	 for(int i=0; i<e; i++)
	 {
		int v = in->ReadInt();
		int w = in->ReadInt();
		addEdge(v, w);
	 }
}

int Digraph::getVertices()
{
	return V;
}

int Digraph::getEdges()
{
	return E;
}

void Digraph::add(Vertice **v, int w)
{
	Vertice *temp = *v;
	*v = new Vertice();
	(*v)->value = w;
	(*v)->next = temp;
}

void Digraph::addEdge(int v, int w)
{
	add(&adj[v], w);
	E++;
}

Digraph::Vertice *Digraph::getAdj(int v)
{
	return adj[v];
}

Digraph *Digraph::reverse()
{
	Digraph *d = new Digraph(V);
	for(int i=0; i<V; i++)
	{
		Vertice *vertices = adj[i];
		while(vertices != NULL)
		{
			d->addEdge(vertices->value, i);
			vertices = vertices->next;
		}
	}
	return d;
}

//int main(int argc, char **argv)
//{
//	if(argc != 2)
//	{
//		cout<<"argc !=2"<<endl;
//		exit(1);
//	}
//	Digraph *g = new Digraph(new In(argv[1]));	
//	for(int i=0; i < g->getVertices(); i++)
//	{
//		cout<<i<<": ";	
//		Digraph::Vertice *temp = g->getAdj(i);	
//		while(temp != NULL)
//		{
//			cout<<temp->value<<" ";	
//			temp = temp->next;
//		}
//		cout<<endl;
//	}
//	cout<<"reverse:"<<endl;
//	Digraph *d = g->reverse();
//	for(int i=0; i < d->getVertices(); i++)
//	{
//		cout<<i<<": ";	
//		Digraph::Vertice *temp = d->getAdj(i);	
//		while(temp != NULL)
//		{
//			cout<<temp->value<<" ";	
//			temp = temp->next;
//		}
//		cout<<endl;
//	}
//}
