#include"EdgeWeightedGraph.h"
#include"../../Charactor2/MinPQ.cc"
#include"../../Queue.cc"

class LazyPrimMST
{
private:
	bool *marked;
	int N;
	double weightSum;
	Queue<Edge *> *mst;
	MinPQ<Edge *> *pq;

public:
	LazyPrimMST(EdgeWeightedGraph *G);
	void visit(EdgeWeightedGraph *G, int v);
	Queue<Edge *> *getEdges();
	double getWeightSum();
};
