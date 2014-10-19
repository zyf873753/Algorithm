#include"Graph.h"
#include"../stack.h"
#include"../queue.h" //used in implement

class BreadthFirstPaths
{
private:
	bool *marked;
	int *edgeTo;
	int N;
	int S;

public:
	BreadthFirstPaths(Graph *G, int s);
	void bfs(Graph *G, int v);
	bool hasPathTo(int v);
	StackInt *pathTo(int v);
};
