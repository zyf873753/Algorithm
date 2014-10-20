#include"DirectedCycle.h"

DirectedCycle::DirectedCycle(Digraph *G): N(G->getVertices()), cycle(NULL)
{
	marked = new bool[N];
	edgeTo = new int[N];
	onStack = new bool[N];
	//necessary?
	for(int i=0; i<N; i++)
	{
		marked[i] = false;
		onStack[i] = false;
	}
	for(int v=0; v<N; v++)
	{
		if(!marked[v]) dfs(G, v);
	}
}

void DirectedCycle::dfs(Digraph *G, int v)
{
	onStack[v] = true;	
	marked[v] = true;
	Digraph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		if(hasCycle())
			return;
		int w = vertices->value;
		if(!marked[w])
		{
			edgeTo[w] = v;
			dfs(G, w);
		}
		else if(onStack[w])
		{
			cycle = new StackInt();	
			for(int x=v; x!=w; x=edgeTo[x])
				cycle->push(x);
			cycle->push(w);
			cycle->push(v);
		}
		vertices = vertices->next;
	}
	onStack[v] = false;
}

bool DirectedCycle::hasCycle()
{
	return cycle != NULL;
}

StackInt *DirectedCycle::getCycles()
{
	return cycle;
}

int main(int argc, char **argv)
{
	Digraph *G = new Digraph(new In(argv[1]));
	DirectedCycle *C = new DirectedCycle(G);
	if(C->hasCycle())
	{
		cout<<"has cycle"<<endl;
		StackInt *cycle = C->getCycles();
		while(!cycle->isEmpty())
			cout<<cycle->pop()<<" ";
		cout<<endl;	
	}
	else
		cout<<"no cycle"<<endl;
}
