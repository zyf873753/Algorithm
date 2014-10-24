#include"LazyPrimMST.h"

LazyPrimMST::LazyPrimMST(EdgeWeightedGraph *G): N(G->getVerticeNum()), weightSum(0)
{
	marked = new bool[N];	
	mst = new Queue<Edge *>();
	pq = new MinPQ<Edge *>();

	visit(G, 0);
	while(!pq->isEmpty())
	{
		Edge* e = pq->delMin();
		int v = e->either();
		int w = e->other(v);
		if(marked[v] && marked[w]) continue;
		mst->enqueue(e);
		weightSum += e->getWeight();
		//delete e; 
		if(!marked[v]) visit(G, v);
		if(!marked[w]) visit(G, w);
	}
}

void LazyPrimMST::visit(EdgeWeightedGraph *G, int v)
{
	marked[v] = true;	
	EdgeWeightedGraph::Edges *es = G->getAdj(v);
	while(es != NULL)
	{
		Edge *e = es->value;
		if(!marked[e->other(v)])
			pq->insert(e);
		//don't neet delete e
		es = es->next;
	}
}

Queue<Edge *> *LazyPrimMST::getEdges()
{
	return mst;	
}

double LazyPrimMST::getWeightSum()
{
	return weightSum;
}


int main(int argc, char **argv)
{
	EdgeWeightedGraph *G = new EdgeWeightedGraph(new In(argv[1]));
	LazyPrimMST *P = new LazyPrimMST(G);
	Queue<Edge *> *mst = P->getEdges(); 
	cout<<"size: "<<mst->size()<<endl;
  
	while(!mst->isEmpty())
	{
		Edge *e = mst->dequeue();	
		int v = e->either();
		int w = e->other(v);
		double weight = e->getWeight();
		cout<<v<<" "<<w<<" "<<weight<<endl;
		delete e;
	}
	cout<<"sum of weight: "<<P->getWeightSum()<<endl;
}
