//#include<iostream>
//#include<stdlib.h>
using namespace std;

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
template <typename T> bool Queue<T>::isEmpty()
{
	return first == NULL;
}

template <typename T> void Queue<T>::enqueue(T v)
{
	Node *oldlast = last;
	last = new Node();
	last->value = v;
	last->next = NULL;
	if(first == NULL)
		first = last;
	else
		oldlast->next = last;
	N++;
}

template <typename T> T Queue<T>::dequeue()
{
	T firstValue = first->value;
	Node *oldfirst = first;
	first = first->next;
	delete oldfirst;
	if(first == NULL)
		last = first; //last = NULL
	N--;
	return firstValue;	
}

template <typename T> int Queue<T>::size()
{
	return N;
}

//int main()
//{
//	Queue<double> *queue=new Queue<double>();
//	double temp;
//	while(cin>>temp)
//	{
//		queue->enqueue(temp);	
//	}
//	cout<<"size: "<<queue->size()<<endl;
////	cout<<"dequeue: "<<queue->dequeue(); cout<<"  size: "<<queue->size()<<endl;
//	while(!queue->isEmpty())
//	{
//		cout<<queue->dequeue()<<endl;	
//	}
//}
