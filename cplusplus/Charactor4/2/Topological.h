#include"DepthFirstOrder.h"

class Topological
{
private:
	StackInt *order;
public:
	Topological(Digraph *G);
	StackInt *getOrder();
	bool isDAG();
};

