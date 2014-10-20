#include"Topological.h"

Topological::Topological(Digraph *G)
{
	//we don't test if there is DAG, because DepthFirstOrder.h and DirectedCycle.h both include Digraph.h
	DepthFirstOrder *dfs = new DepthFirstOrder(G); 	
	order = dfs->getReversePost();
}

StackInt *Topological::getOrder()
{
	return order;
}

//useless
bool Topological::isDAG()
{
	return order != NULL;
}

int main(int argc, char **argv)
{
	Digraph *G = new Digraph(new In(argv[1]));
	Topological *T = new Topological(G);
	StackInt *order = T->getOrder();
	while(!order->isEmpty())
		cout<<order->pop()<<" ";
	cout<<endl;
}
