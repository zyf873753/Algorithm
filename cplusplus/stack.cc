/*
 *Author: Zhang Yifan
 *Created time: 2014.8.28
 *Modified time:
 *Description: This file implement class StackInt in stack.h which provides some function of stack
 */
#include"stack.h"
#include"StdIn.h"

bool StackInt::isEmpty()
{
	return first==NULL;
}

void StackInt::push(int v)
{
	Node *oldfirst=first;
	first=new Node();
	first->value=v;
	first->next=oldfirst;
	N++;
}

int StackInt::pop()
{
	if(first==NULL)
	{
		cout<<"stack is empty!"<<endl;
		return 0;
	}
	int topvalue=first->value;
	Node *oldfirst=first;
	first=first->next;
	delete oldfirst;
	N--;
	return topvalue;
}

int StackInt::size()
{
	return N;
}

int StackInt::top()
{
	if(first==NULL)
	{		
		cout<<"stack is empty!"<<endl;
		return 0;
	}
	return first->value;
}

//int main()
//{
//	StackInt *link=new StackInt();
//	int tempvalue;
//	cout<<"isEmpty: "<<link->isEmpty()<<endl;
//	while(cin>>tempvalue)
//	{
//		link->push(tempvalue);
//	}
//	cout<<"size: "<<link->size()<<endl;
//	cout<<"pop: "<<link->pop(); cout<<"  size: "<<link->size()<<endl;
//	cout<<"top: "<<link->top(); cout<<"  size: "<<link->size()<<endl;
//	cout<<"isEmpty: "<<link->isEmpty()<<endl;
//
//}
