#include"Digraph.h"

class DirectedDFS
{
private:
	bool *marked;
public:
	DirectedDFS(Digraph *G, int s);
	DirectedDFS(Digraph *G, Digraph::Vertice *v);
	void dfs(Digraph *G, int v);
	bool isMarked(int v);
};
