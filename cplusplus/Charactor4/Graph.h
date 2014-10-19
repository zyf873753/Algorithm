#include"../In.h"

class Graph
{
private:
	int V; //number of vertices
	int E; //number of edges
	void initial(int v);

public:
	class Vertice //we can add constructor lator
	{
	public: // there must be public, or cannot access value and next outsideclass Vertice and Graph
		int value;
		Vertice *next;
	};
	Vertice **adj; //array of adjecency list
	Graph(int v);
	Graph(In *in);
	int getVertices();
	int getEdges();
	void add(Vertice **v, int w);
	void addEdge(int v, int w);
	Vertice *getAdj(int v);

		
};
