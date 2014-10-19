#include<iostream>

class queueInt
{
private:
	int N;
	class Node
	{
	public:
		Node():value(0),next(NULL) {};
		int value;
		Node *next;
	};
	Node *first;
	Node *last;

public:
	queueInt():N(0),first(NULL),last(NULL) {};
	bool isEmpty();
	void enqueue(int);
	int dequeue();
	int size();
};
