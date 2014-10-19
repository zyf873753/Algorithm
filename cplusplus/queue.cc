#include"queue.h"
using namespace std;
bool queueInt::isEmpty()
{
	return first==NULL;
}

void queueInt::enqueue(int v)
{
	Node *oldlast=last;
	last=new Node();
	last->value=v;
	last->next=NULL;//not neccessary due to the constructor
	if(first==NULL)
		first=last;
	else
		oldlast->next=last;
	N++;
}

int queueInt::dequeue()
{
	int firstvalue=first->value;
	Node *oldfirst=first;
	first=first->next;
	delete oldfirst;
	if(isEmpty())
		last=first;
	N--;
	return firstvalue;
}

int queueInt::size()
{
	return N;
}

//int main()
//{
//	queueInt *queue=new queueInt();
//	int temp;
//	while(cin>>temp)
//	{
//		queue->enqueue(temp);	
//	}
////	cout<<"size: "<<queue->size()<<endl;
////	cout<<"dequeue: "<<queue->dequeue(); cout<<"  size: "<<queue->size()<<endl;
//	while(!queue->isEmpty())
//	{
//		cout<<queue->dequeue()<<endl;	
//	}
//}
