#include"DirectedDFS.h"
#include<iostream>
#include<sstream>
using namespace std;

DirectedDFS::DirectedDFS(Digraph *G, int s)
{
	marked = new bool[G->getVertices()];
	dfs(G, s);
}

DirectedDFS::DirectedDFS(Digraph *G, Digraph::Vertice *v)
{
	marked = new bool[G->getVertices()];
	while(v != NULL)
	{
		if(!marked[v->value]) dfs(G, v->value);
		v = v->next;
	}
}

void DirectedDFS::dfs(Digraph *G, int v)
{
	marked[v] = true;
	Digraph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL) 
	{
		int w = vertices->value;
		if(!marked[w]) dfs(G, w);
		vertices = vertices->next;
	}
}

bool DirectedDFS::isMarked(int v)
{
	return marked[v];
}

int main(int argc, char **argv)
{
	Digraph *G = new Digraph(new In(argv[1]));
	Digraph::Vertice *s = NULL;
	for(int i=2; i<argc; i++)
	{
		Digraph::Vertice *temp = s;
		s = new Digraph::Vertice();
		stringstream ss;
		ss<<argv[i];
		int n;
		ss>>n;
		s->value = n;
		s->next = temp;
	}
	DirectedDFS *reachable = new DirectedDFS(G, s);
	for(int i=0; i<G->getVertices(); i++)
		if(reachable->isMarked(i)) cout<<i<<" ";
	cout<<endl;
}
