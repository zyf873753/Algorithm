#include"DepthFirstPaths.h"
#include<iostream>
#include<sstream>
using namespace std;

DepthFirstPaths::DepthFirstPaths(Graph *G, int s):S(s), N(G->getVertices())
{
	marked = new bool[N];
	edgeTo = new int[N];
	dfs(G, s);
}

void DepthFirstPaths::dfs(Graph *G, int v)
{
	marked[v] = true;
	Graph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		int w = vertices->value;
		if(!marked[w])
		{
			edgeTo[w] = v;	
			dfs(G, w);
		}
		vertices = vertices->next;
	}
}

bool DepthFirstPaths::hasPathTo(int v)
{
	return marked[v];
}

StackInt *DepthFirstPaths::pathTo(int v)
{
	if(!hasPathTo(v)) return NULL;
	StackInt *stack = new StackInt();
	for(int x=v; x!=S; x=edgeTo[x])
		stack->push(x);
	stack->push(S);
	return stack;
}

//follow function is not member of class DepthFirstPaths
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
	DepthFirstPaths *path = new DepthFirstPaths(G, s);
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

