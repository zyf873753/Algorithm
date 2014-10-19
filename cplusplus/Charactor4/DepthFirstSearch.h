#include"Graph.h"

class DepthFirstSearch
{
private:
	bool *marked;
	int N;
	int count;
public:
	DepthFirstSearch(Graph *G, int v);
	void dfs(Graph *G, int v);
	bool isMarked(int w);
	int getCount();
};
