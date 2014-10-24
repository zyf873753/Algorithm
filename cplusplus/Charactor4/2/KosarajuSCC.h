#include"DepthFirstOrder.h"

class KosarajuSCC
{
private:
	bool *marked;
	int *id;
	int N;
	int count;
public:
	KosarajuSCC(Digraph *G);
	void dfs(Digraph *G, int v);
	bool stronglyConnected(int v, int w);
	int getId(int v);
	int getCount();
};
