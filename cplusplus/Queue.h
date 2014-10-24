#include"stdlib.h"
template <typename T> class Queue
{
private:
	int N;
	class Node
	{//no constructor, I have no idea how to initiate type T
	public:
		T value;
		Node *next;
	};
	Node *first;
	Node *last;

public:
	Queue(): N(0), first(NULL),last(NULL){}
	bool isEmpty();
	void enqueue(T);
	T dequeue();
	int size();
};
