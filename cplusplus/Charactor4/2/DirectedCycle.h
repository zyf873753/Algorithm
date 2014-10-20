#include"Digraph.h"
#include"../../stack.h"

class DirectedCycle
{
private:
	bool *marked;
	int *edgeTo;
	bool *onStack;	
	int N;
	StackInt *cycle;
public:
	DirectedCycle(Digraph *G);
	void dfs(Digraph *G, int v);
	bool hasCycle();
	StackInt *getCycles();
};

