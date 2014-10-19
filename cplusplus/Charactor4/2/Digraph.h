#include"../../In.h"

class Digraph
{
private:
	int V;
	int E;
	void initial(int v);
public:
	class Vertice
	{
	public:
		int value;
		Vertice *next;
	};
	Vertice **adj;
	Digraph(int v);
	Digraph(In *in);
	int getVertices();
	int getEdges();
	void add(Vertice **v, int w);
	void addEdge(int v, int w);
	Vertice *getAdj(int v);
	Digraph *reverse();
};

