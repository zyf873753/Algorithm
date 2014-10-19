#include<iostream>
#include"../StdRandom.h"
using namespace std;

int main()
{
	int N, lo, hi;
	cin>>N>>lo>>hi;
	cout<<N<<endl;
	/*
	for(int i=N-1;i>=0;i--)
	{
		cout<<i<<endl;
	}
	*/
	
/*
	for(int i=0;i<N;i++)
	{
		cout<<i<<endl;
	}
*/	

	StdRandom *r=new StdRandom();
	int *a = r->getNums(N, lo, hi);
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<endl;
	}
}
