#include"Graph.h"

class Cycle
{
private:
	bool *marked;
	int N;
	bool cycle;
public:
	Cycle(Graph *G);
	void dfs(Graph *G, int v, int u);
	bool hasCycle();
};
