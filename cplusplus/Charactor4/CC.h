#include"Graph.h"

class CC
{
private:
	bool *marked;
	int *id;
	int N;
	int count;
public:
	CC(Graph *G);
	void dfs(Graph *G, int v);
	bool connected(int v, int w);
	int getId(int v);
	int getCount();
};
