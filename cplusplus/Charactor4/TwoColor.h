#include"Graph.h"

class TwoColor
{
private:
	bool *marked;
	bool *color;
	int N;
	bool twoColorable;
public:
	TwoColor(Graph *G);
	void dfs(Graph *G, int v);
	bool isTwoColorable();
};
