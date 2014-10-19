#include"TwoColor.h"

TwoColor::TwoColor(Graph *G): N(G->getVertices()), twoColorable(true)
{
	marked = new bool[N];
	color = new bool[N];
	for(int i=0; i<N; i++)
		color[i] = false;
	for(int i=0; i<N; i++)
	{
		if(!marked[i])
			dfs(G, i);
	}
}

void TwoColor::dfs(Graph *G, int v)
{
	marked[v] = true;
	Graph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		int w = vertices->value;	
		if(!marked[w]) 
		{
			color[w] = !color[v];
			dfs(G, w);
		}
		else if(color[w] == color[v])
			twoColorable = false;
		vertices = vertices->next;
	}
}

bool TwoColor::isTwoColorable()
{
	return twoColorable;
}

int main(int argc, char **argv)
{
	Graph *G = new Graph(new In(argv[1]));
	TwoColor *T = new TwoColor(G);
	if(T->isTwoColorable())
		cout<<"is two colorable"<<endl;
	else 
		cout<<"not two colorable"<<endl;
}
