#include"Cycle.h"
#include<iostream>
using namespace std;

Cycle::Cycle(Graph *G): N(G->getVertices())
{
	marked = new bool[N];
	cycle= false;
	for(int i=0; i<N; i++)
	{
		if(!marked[i])
			dfs(G, i, i);
	}
}

void Cycle::dfs(Graph *G, int v, int u)
{
	marked[v] = true;
	Graph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		int w = vertices->value;
		if(!marked[w])
			dfs(G, w, v);
		else if(u != w)
			cycle = true;
		vertices = vertices->next;
	}
}

bool Cycle::hasCycle()
{
	return cycle; 
}

int main(int argc, char **argv)
{
	Graph *G = new Graph(new In(argv[1]));
	Cycle *cy = new Cycle(G);
	if(cy->hasCycle())
		cout<<"has cycle"<<endl;
	else
		cout<<"no cycle"<<endl;
}
