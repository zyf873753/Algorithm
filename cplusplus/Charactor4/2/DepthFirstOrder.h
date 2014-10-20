#include"Digraph.h"
#include"../../queue.h"
#include"../../stack.h"

class DepthFirstOrder
{
private:
	bool *marked;
	int N;
	queueInt *pre;
	queueInt *post;
	StackInt *reversePost;
public:
	DepthFirstOrder(Digraph *G);
	void dfs(Digraph *G, int v);
	queueInt *getPre();
	queueInt *getPost();
	StackInt *getReversePost();
};
