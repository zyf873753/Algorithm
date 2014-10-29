#include<stdlib.h>
#include<iostream>
using namespace std;
template <typename T> class IndexMinPQ
{
private:
	int NMAX;
	int N;
	int *pq;
	int *qp;
	T *keys;
	//the parameter in private fucntion(less, exchange, swim, sink) is index of pq
	bool less(int i, int j);
	void exchange(int i, int j);
	void swim(int k);
	void sink(int k);
public:
	IndexMinPQ(int max);
	//the parameter in public fucntion is index of qp,keys
	void insert(int k, T item);
	void change(int k, T item);
	bool contains(int k);
	void del(int k);
	T min();
	int minIndex();
	int delMin();
	bool isEmpty();
	int size();
};

template <typename T> IndexMinPQ<T>::IndexMinPQ(int max):NMAX(max), N(0)
{
	pq = new int[NMAX+1];
	qp = new int[NMAX+1];
	keys = new T[NMAX+1];
	for(int i=0; i<=NMAX; i++)
	{
		pq[i] = -1;
		qp[i] = -1;
	}
}


template <typename T> bool IndexMinPQ<T>::less(int i, int j)
{
	return keys[pq[i]] < keys[pq[j]];	
}

template <typename T> void IndexMinPQ<T>::exchange(int i, int j)
{
	int swap = pq[i];
	pq[i] = pq[j];
	pq[j] = swap;

	qp[pq[i]] = i;
	qp[pq[j]] = j;
}

template <typename T> void IndexMinPQ<T>::swim(int k)
{
	while(k>1 && less(k, k/2))
	{
		exchange(k/2, k);
		k = k/2;
	}
}

template <typename T> void IndexMinPQ<T>::sink(int k)
{
	while(2*k <= N)
	{
		int j = 2 * k;	
		if(j<N && less(j+1, j)) j++;
		if(less(k, j))
			break;
		exchange(k, j);
		k = j;
	}
}

//tested
template <typename T> void IndexMinPQ<T>::insert(int k, T item)
{
	if(k<0 || k>NMAX) exit(0);	
	if(contains(k)) exit(0);
	N++;
	pq[N] = k;
	qp[k] = N;
	keys[k] = item;
	swim(N);
}

//tested
template <typename T> void IndexMinPQ<T>::change(int k, T item)
{
	if(k<0 || k>NMAX) exit(0);	
	if(!contains(k)) exit(0);
	keys[k] = item;	
	swim(qp[k]);
	sink(qp[k]);
}

template <typename T> bool IndexMinPQ<T>::contains(int k) {
	if(k<0 || k>NMAX) exit(0);	
	return qp[k] != -1;	
}

//tested
template <typename T> void IndexMinPQ<T>::del(int k)
{
	int index = qp[k];
	exchange(index, N--);
	swim(index);
	sink(index);
	keys[k] = NULL;
	qp[k] = -1;
	pq[N+1] = -1;//not necessary
}

//tested
template <typename T> T IndexMinPQ<T>::min()
{
	if(isEmpty())
		exit(0);
	return keys[pq[1]];
}

template <typename T> int IndexMinPQ<T>::minIndex()
{
	return pq[1];
}

//tested
template <typename T> int IndexMinPQ<T>::delMin()
{
	int min = pq[1];
	exchange(1, N--);
	sink(1);
	qp[min] = -1;
	keys[min] = NULL;
	pq[N+1] = -1;//not necessary
	return min;
}

template <typename T> bool IndexMinPQ<T>::isEmpty()
{
	return N == 0;
}

template <typename T> int IndexMinPQ<T>::size() 
{
	return N;
}

int main()
{
	IndexMinPQ<double> *pq = new IndexMinPQ<double>(64);
	double in;
	int i=0;
	while(cin>>in)
	{
		pq->insert(i, in);
		i++;
	}
	pq->del(19);
	pq->change(5, 11);
	while(!pq->isEmpty())
	{
		cout<<pq->min()<<endl;
		pq->delMin();
	}
}
