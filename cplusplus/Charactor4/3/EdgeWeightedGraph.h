#include"Edge.h"
#include"../../In.h"

class EdgeWeightedGraph
{
private:
	int V;
	int E;
	void initial(int v);
public:
	class Edges
	{
	public:
		Edge *value;
		Edges *next;
	};
	Edges **adj;
	EdgeWeightedGraph(int v);
	EdgeWeightedGraph(In *in);
	int getVerticeNum();
	int getEdgeNum();
	void add(Edges **es, Edge * e);
	void addEdge(Edge *e);
	Edges *getAdj(int v);
	Edges *getEdges();
};
