#include"MaxPQ.h"
#include<stdlib.h>
#include<iostream>

using namespace std;

/*private function*/
bool MaxPQ::less(int i, int j)
{
	return pq[i] < pq[j];
}

void MaxPQ::exchange(int i, int j)
{
	int temp=pq[i];
	pq[i] = pq[j];
	pq[j] = temp;
}

void MaxPQ::swim(int k)
{
	while(k > 1 && less(k/2, k))
	{
		exchange(k, k/2);
		k = k/2;
	}
}

void MaxPQ::sink(int k)
{
	while(2*k <= N)
	{
		int j = 2*k; 
		if(j < N && less(j, j+1)) j++;
		if(less(j, k)) break;
		exchange(k, j);
		k = j;
	}
}

/*public function*/
bool MaxPQ::isEmpty()
{
	return N == 0;
}

int MaxPQ::size()
{
	return N;
}

void MaxPQ::insert(int v)
{
	pq[++N] = v;//N=0 at beginning, and pq[0] is useless in heap
	swim(N);
}

int MaxPQ::delMax()
{
	if(isEmpty())
	{
		cout<<"The queue is empty!"<<endl;
		exit(0);
	}
	int max = pq[1];	
	exchange(1, N--);
	pq[N+1] = NULL; //NULL is describe for pointer in c++,so there is a warning, and this sentence is not neccessary because N limit the size of array.
	sink(1);
	return max;
}

int MaxPQ::max()
{
	return pq[1];
}


int main()
{
	MaxPQ *pq = new MaxPQ();
	int v;
	while(cin>>v)
		pq->insert(v);
	while(!pq->isEmpty())
		cout<<pq->delMax()<<endl;
//	cout<<"isempty: "<<pq->isEmpty()<<endl;
//	cout<<"size: "<<pq->size()<<endl;
//	cout<<"max: "<<pq->max()<<endl;
//	cout<<"delMax: "<<pq->delMax()<<endl;
//	cout<<"size: "<<pq->size()<<endl;
//	cout<<"max: "<<pq->max()<<endl;
}
