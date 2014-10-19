#include"BreadthFirstPaths.h"
#include<sstream>
#include<iostream>
using namespace std;

BreadthFirstPaths::BreadthFirstPaths(Graph *G, int s): S(s), N(G->getVertices())
{
	marked = new bool[N];	
	edgeTo = new int[N];
	bfs(G, S);
}

void BreadthFirstPaths::bfs(Graph *G, int v)
{
	marked[v] = true;	
	queueInt * queue = new queueInt();
	queue->enqueue(v);
	while(!queue->isEmpty())
	{
		int x = queue->dequeue();
		Graph::Vertice *vertices = G->getAdj(x);//note that the parameter is x, not v
		while(vertices != NULL)
		{
			int w = vertices->value;
			if(!marked[w])
			{
				marked[w] = true;
				edgeTo[w] = x;
				queue->enqueue(w);
			}
			vertices = vertices->next;
		}
	}		
}

bool BreadthFirstPaths::hasPathTo(int v)
{
	return marked[v];
}

StackInt *BreadthFirstPaths::pathTo(int v)
{
	if(!hasPathTo(v))	return NULL;
	StackInt *stack = new StackInt();
	for(int x=v; x!=S; x=edgeTo[x])
		stack->push(x);
	stack->push(S);
	return stack;
}

//followint function is not member of class BreadthFirstPaths
int stringToInt(char *str)
{
	string strTemp(str);
	stringstream ss;
	ss<<strTemp;
	int i;
	ss>>i;
	return i;
}

int main(int argc, char **argv)
{
	Graph *G = new Graph(new In(argv[1]));
	int s = stringToInt(argv[2]);
	BreadthFirstPaths *path = new BreadthFirstPaths(G, s);
	for(int v=0; v<G->getVertices(); v++)
	{
		cout<<s<<" to "<<v<<": ";	
		if(path->hasPathTo(v))
		{
			StackInt *stack  = path->pathTo(v);
			while(!stack->isEmpty())
			{
				int x = stack->pop();
				if(x == s) cout<<x;
				else cout<<"-"<<x;
			}
			delete stack;
		}
		cout<<endl;
	}
}

