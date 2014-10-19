/*
 *Author: Zhang Yifan
 *Created time: 2014.8.28
 *Modified time:
 *Description: This file defined class StackInt which provides some function of stack still not implement
 */
#include<iostream>


class StackInt
{
private:
	int N;
	class Node
	{
	public:
		int value;
		Node *next;//undefined class can't used to declare object,just reference or pointer.
	};
	Node *first;

public:
	StackInt():N(0),first(NULL){};
	bool isEmpty();
	void push(int);
	int pop();
	int size();
	int top();	
};
