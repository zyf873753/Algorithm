#include"KosarajuSCC.h"

KosarajuSCC::KosarajuSCC(Digraph *G): N(G->getVertices()), count(0)
{
	marked = new bool[N];
	id = new int[N];
	for(int i=0; i<N; i++)
	{
		marked[i] = false;
		id[i] = -1;
	}
	DepthFirstOrder *order = new DepthFirstOrder(G->reverse());
	StackInt *stack = order->getReversePost();
	while(!stack->isEmpty())
	{
		int w = stack->pop(); 
		if(!marked[w]) 
		{
			dfs(G, w);
			count++;
		}
	}
}

void KosarajuSCC::dfs(Digraph *G, int v)
{
	marked[v] = true;
	id[v] = count; 
	Digraph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		int w = vertices->value;
		if(!marked[w])
			dfs(G, w);
		vertices = vertices->next;
	}
}

bool KosarajuSCC::stronglyConnected(int v, int w)
{
	return id[v] == id[w];
}

int KosarajuSCC::getId(int v)
{
	return id[v];
}

int KosarajuSCC::getCount()
{
	return count;
}

int main(int argc, char **argv)
{
	Digraph *G = new Digraph(new In(argv[1]));
	KosarajuSCC *cc = new KosarajuSCC(G);
	cout<<"count: "<<cc->getCount()<<endl;
	for(int v=0; v<G->getVertices(); v++)
		cout<<cc->getId(v)<<" ";
	cout<<endl;
	bool b = cc->stronglyConnected(1, 2);	
	cout<<b<<endl;
}
