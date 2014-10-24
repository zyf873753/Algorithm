#include"EdgeWeightedGraph.h"

void EdgeWeightedGraph::initial(int v)
{
	adj = new Edges *[V];
	for(int i=0; i<V; i++)
		adj[i] = NULL;
}

EdgeWeightedGraph::EdgeWeightedGraph(int v): V(v), E(0)
{
	initial(v);
}

EdgeWeightedGraph::EdgeWeightedGraph(In *in): E(0)
{
	V = in->ReadInt();
	initial(V);
	int e = in->ReadInt();
	for(int i=0; i<e; i++)
	{
		int v = in->ReadInt();
		int w = in->ReadInt();
		double weight = in->ReadDouble();
		addEdge(new Edge(v, w, weight));
	}
}

int EdgeWeightedGraph::getVerticeNum()
{
	return V;
}

int EdgeWeightedGraph::getEdgeNum()
{
	return E;
}

void EdgeWeightedGraph::add(Edges **es, Edge *e)
{
	Edges *old = *es;
	(*es) = new Edges();
	(*es)->value = e;
	(*es)->next = old;
}

void EdgeWeightedGraph::addEdge(Edge *e)
{
	int v = e->either();
	int w = e->other(v);
	add(&adj[v], e);
	add(&adj[w], e);
	E++;
}

EdgeWeightedGraph::Edges *EdgeWeightedGraph::getAdj(int v)
{
	return adj[v];
}



//this function not copy a new object, just return the reference
//the names in this function are a little confused
EdgeWeightedGraph::Edges *EdgeWeightedGraph::getEdges()
{
	Edges *es = NULL;
	for(int i=0; i<V; i++)
	{
		Edges *e = adj[i];
		while(e != NULL)
		{
			if(e->value->other(i) > i) 
			   	add(&es, e->value);
			e = e->next;
		}
	}	
	return es;
}

//int main(int argc, char **argv)
//{
//	EdgeWeightedGraph *G = new EdgeWeightedGraph(new In(argv[1]));
//	EdgeWeightedGraph::Edges *es = G->getEdges(); 
//	while(es != NULL)
//	{
//		Edge *e = es->value;
//		int v  = e->either();
//		int w = e->other(v);
//		double weight = e->getWeight();
//		cout<<v<<" "<<w<<" "<<weight<<endl;
//		es = es->next;
//	}
//}
