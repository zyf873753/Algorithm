#include"Sort.h"
#include<iostream>
#include<time.h>
using namespace std;

bool Sort::less(int a, int b)/*{{{*/
{
	return a<b;
}/*}}}*/

void Sort::exchange(int *array, int a, int b)/*{{{*/
{
	int temp=array[a];
	array[a]=array[b];
	array[b]=temp;
}/*}}}*/

bool Sort::isSorted(int *array, int N)/*{{{*/
{
	for(int i=1;i<N;i++)
	{
		if(less(array[i], array[i-1]))
			return false;
	}
	return true;
}/*}}}*/

void Sort::selectionSort(int *array, int N)/*{{{*/
{
	int min;
	for(int i=0;i<N;i++)
	{
		min=i;
		for(int j=i+1;j<N;j++)
		{
			if(less(array[j], array[min])) min=j;
		}
		exchange(array,i,min);
	}
}/*}}}*/

void Sort::insertSort(int *array, int N)/*{{{*/
{
	for(int i=1;i<N;i++)
	{
		for(int j=i;j>0 && less(array[j], array[j-1]);j--)
		{
				exchange(array, j, j-1);
		}
	}
}/*}}}*/

void Sort::shellSort(int *array, int N)/*{{{*/
{
	int h=1;
	while(h < N/3) h = 3*h+1;	

	while(h >= 1)
	{
		for(int i=h;i<N;i++)
		{
			for(int j=i;j>=h && less(array[j],array[j-h]);j-=h)
			{
				exchange(array,j,j-h);
			}
		}
		h=h/3;
	}
}/*}}}*/

void Sort::merge(int *array, int lo, int mid, int hi)/*{{{*/
{
	int i=lo, j=mid+1;

	int *aux=new int[hi+1];
	for(int k=lo;k<=hi;k++)
	{
		aux[k]=array[k];
	}

	for(int k=lo;k<=hi;k++)
	{
		if(i>mid) array[k]=aux[j++];
		else if(j>hi) array[k]=aux[i++];
		else if( less(aux[i], aux[j]) ) array[k]=aux[i++];
		else array[k]=aux[j++];
	}
	delete []aux; //don't forget this sentence, it's important, or ram would be leaked
}/*}}}*/

void Sort::mergeSort(int *array, int lo, int hi)/*{{{*/
{
	if(lo==hi) return;
	int mid=lo+(hi-lo)/2;
	mergeSort(array, lo, mid);
	mergeSort(array, mid+1, hi);
	merge(array, lo, mid, hi);
}/*}}}*/

void Sort::mergeSort(int *array, int N)/*{{{*/
{
	mergeSort(array, 0, N-1);
}/*}}}*/

int Sort::quick(int *array, int lo, int hi)/*{{{*/
{
	int i = lo, j = hi+1;
	int v = array[lo];
	while(true)
	{
		while(less(array[++i], v)) if(i == hi) break;
		while(less(v, array[--j])) if(j == lo) break;
		if(i >= j) break;
		exchange(array, i, j);
	}
	exchange(array, lo, j);
	return j;
}/*}}}*/

void Sort::quickSort(int *array, int lo, int hi)/*{{{*/
{
	if(lo >= hi) return;
	int j = quick(array, lo, hi);
	quickSort(array, lo, j-1);
	quickSort(array, j+1, hi);
}/*}}}*/

void Sort::quickSort(int *array, int N)/*{{{*/
{
	quickSort(array, 0, N-1);
}/*}}}*/

void Sort::quick3waySort(int *array, int lo, int hi)
{
	if(lo >= hi) return;		
	int lt = lo, i = lo + 1, gt = hi;
	int v = array[lo];
	while(i <= gt)
	{
		if(less(array[i], v)) exchange(array, lt++, i++);
		else if(less(v, array[i])) exchange(array, gt--, i);
		else i++;
	}
	quick3waySort(array, lo, lt - 1);
	quick3waySort(array, gt + 1, hi);
}

void Sort::quick3waySort(int *array, int N)
{
	quick3waySort(array, 0, N-1);
}

void Sort::sink(int *array, int k, int N)/*{{{*/
{
	while(2*k <= N)
	{
		int j = 2*k;
		if(j<N && less(array[j], array[j+1])) j++;
		if(less(array[j], array[k]))  break;
		exchange(array, j, k);
		k = j;
	}

}/*}}}*/

void Sort::heapSort(int *array, int N)/*{{{*/
{
	for(int k=N/2;k>=1;k--)
		sink(array, k, N);

	cout<<array[1]<<endl;

	while(N > 1)
	{
		exchange(array, 1, N--);
		sink(array, 1, N);
	}
}/*}}}*/

int main()
{
	int input,N;
	int *a;
	Sort *s=new Sort();
	cin>>N;
	a=new int[N];
	for(int i=0;i<N;i++)
	{
		cin>>input;
		a[i]=input;
	}
	/*
	for(int i=0;i<N;i++)	
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;	
	*/
	time_t start=time(NULL);
	cout<<"Before sorted: "<<s->isSorted(a, N)<<endl;
	s->quick3waySort(a,N);
	for(int i=0;i<N;i++)	
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;	
	cout<<"interval tima: "<<time(NULL)-start<<endl;
	cout<<"After sorted: "<<s->isSorted(a, N)<<endl;
	
}

/*for heap sort*/
//int main()
//{
//	int input,N;
//	int *a;
//	Sort *s=new Sort();
//	cin>>N;
//	a=new int[N+1];
//	a[0] = 0;
//	for(int i=1;i<=N;i++)
//	{
//		cin>>input;
//		a[i]=input;
//	}
//	/*
//	for(int i=0;i<N;i++)	
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;	
//	*/
//	time_t start=time(NULL);
//	cout<<"Before sorted: "<<s->isSorted(a, N)<<endl;
//	s->heapSort(a,N);
//	for(int i=1;i<=N;i++)	
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;	
//	cout<<"interval tima: "<<time(NULL)-start<<endl;
//	cout<<"After sorted: "<<s->isSorted(a, N)<<endl;
//	
//}
