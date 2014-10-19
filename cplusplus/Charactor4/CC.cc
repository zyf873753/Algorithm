#include"CC.h"
#include<iostream>
using namespace std;

CC::CC(Graph *G):N(G->getVertices()), count(0)
{
	marked = new bool[N];
	id = new int[N];
	for(int i=0; i<G->getVertices(); i++)
	{
		if(!marked[i])
		{
			dfs(G, i);
			count++;
		}
	}
}

void CC::dfs(Graph *G, int v)
{
	marked[v] = true;
	id[v] = count;
	Graph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		int w = vertices->value;
		if(!marked[w])
			dfs(G, w);	
		vertices = vertices->next;
	}
}

bool CC::connected(int v, int w)
{
	return id[v] == id[w];
}

int CC::getId(int v)
{
	return id[v];
}

int CC::getCount()
{
	return count;
}




int main(int argc ,char **argv)
{
	Graph *G = new Graph(new In(argv[1]));	
	CC *C = new CC(G);

	int M = C->getCount();
	cout<<M<<" components"<<endl;
	Graph::Vertice **components = new Graph::Vertice *[M];
	for(int i=0; i<M; i++)
		components[i] = NULL;
	for(int i=0; i<G->getVertices(); i++)
	{
		int v = C->getId(i);
		Graph::Vertice *old = components[v];
		components[v] = new Graph::Vertice();
		components[v]->value = i;
		components[v]->next = old;	
	}
	for(int i=0; i<M; i++)
	{
		Graph::Vertice *temp = components[i];
		while(temp != NULL)
		{
			cout<<temp->value<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}
}
