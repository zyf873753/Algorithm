#include"Graph.h"
#include"../stack.h"

class DepthFirstPaths
{
private:
	bool *marked;
	int *edgeTo;
	const int N;
	const int S;

public:
	DepthFirstPaths(Graph *G, int s);
	void dfs(Graph *G, int v);
	bool hasPathTo(int v);
	StackInt *pathTo(int v);
};
