#include"DepthFirstOrder.h"

DepthFirstOrder::DepthFirstOrder(Digraph *G): N(G->getVertices())
{
	marked = new bool[N];	
	pre = new queueInt();
	post = new queueInt();
	reversePost = new StackInt();
	for(int v=0; v<N; v++)
		if(!marked[v]) dfs(G, v);
}

void DepthFirstOrder::dfs(Digraph *G, int v)
{
	pre->enqueue(v);
	marked[v] = true;
	Digraph::Vertice *vertices = G->getAdj(v);
	while(vertices != NULL)
	{
		int w = vertices->value;
		if(!marked[w]) 
			dfs(G, w);
		vertices = vertices->next;
	}
	post->enqueue(v);
	reversePost->push(v);
}

queueInt *DepthFirstOrder::getPre()
{
	return pre;
}

queueInt *DepthFirstOrder::getPost()
{
	return post;
}

StackInt *DepthFirstOrder::getReversePost()
{
	return reversePost;
}

//int main(int argc, char **argv)
//{
//	Digraph *G = new Digraph(new In(argv[1]));
//	DepthFirstOrder *dfs = new DepthFirstOrder(G);
//	StackInt *order = dfs->getReversePost();
//	while(!order->isEmpty())
//		cout<<order->pop()<<" ";
//	cout<<endl;
//}
