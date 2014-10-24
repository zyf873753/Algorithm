#include<iostream>
#include<stdlib.h>
using namespace std;


template <typename T> class MinPQ
{
private:
	T *pq;
	int N;
	bool less(int i, int j);
	void exchange(int i, int j);
	void swim(int k);
	void sink(int k);
public:
	MinPQ(): N(0){ pq = new T[1024]; }
	MinPQ(int maxN): N(0){ pq = new T[maxN+1]; }
	void insert(T v);
	T min();
	T delMin();
	bool isEmpty();
	int size();
};

template <typename T> bool MinPQ<T>::less(int i, int j)
{
	//suppose that T is pointer type
	return (*pq[i]) < (*pq[j]);
}

template <typename T> void MinPQ<T>::exchange(int i, int j)
{
	T temp = pq[i];
	pq[i] = pq[j];
	pq[j] = temp;
}

template <typename T> void MinPQ<T>::swim(int k)
{
	while(k>1 && less(k, k/2))
	{
		exchange(k/2, k);	
		k = k/2;
	}
}

template <typename T> void MinPQ<T>::sink(int k)
{
	while(2*k <= N)
	{
		int j = 2*k;
		if(j<N && less(j+1, j)) j++;
		if(less(k, j))  break;
		exchange(k, j);
		k = j;
	}
}

/*public function*/
template <typename T> void MinPQ<T>::insert(T v)
{
	pq[++N] = v;
	swim(N);
}

template <typename T> T MinPQ<T>::min()
{
	return pq[1];	
}

template <typename T> T MinPQ<T>::delMin()
{
	if(isEmpty())
	{
		cout<<"The queue is empty!"<<endl;
		exit(1);
	}
	T min = pq[1];
	exchange(1, N--);
	pq[N+1] = NULL; ////NULL is describe for pointer in c++,so there is a warning, and this sentence is not neccessary because N limit the size of array.
	sink(1);
	return min;
}

template <typename T> bool MinPQ<T>::isEmpty()
{
	return N == 0;
}

template <typename T> int MinPQ<T>::size()
{
	return N;
}

//int main()
//{
//	MinPQ<double *> *pq = new MinPQ<double *>();
//	double temp;
//	while(cin>>temp)
//	{
//		double *v = new double(temp);
//		pq->insert(v);
//	}
//	while(!pq->isEmpty())
//		cout<<*pq->delMin()<<endl;
//}
