#include"UnionFind.h"
#include<iostream>
using namespace std;


/*********************************union-find************************************//*{{{*/
int UF::Find(int p)
{
	return id[p];
}

bool UF::Connected(int p,int q)
{
	return id[p]==id[q];
}

void UF::Union(int p,int q)
{
	int pID=Find(p);
	int qID=Find(q);

	if(pID==qID)
		return;

	for(int i=0;i<N;i++)
	{
		if(id[i]==qID)
			id[i]=pID;
	}
	count--;
}

int UF::Count()
{
	return count;
}

int QuickUnionUF::Count()
{
	return count;
}
/*}}}*/

/*************************************Quick-Union*******************************//*{{{*/

int QuickUnionUF::Find(int p)
{
	while(id[p] != p)
		p = id[p];
	return p;
}

bool QuickUnionUF::Connected(int p, int q) //not really fast
{
	return Find(p)==Find(q);
}

void QuickUnionUF::Union(int p, int q)
{
	int pID=Find(p);
	int qID=Find(q);

	if(pID == qID)
		return;

	id[qID]=pID;
	count--;
}
/*}}}*/

/******************************WeightedQuickUnionUF*****************************//*{{{*/

int WeightedQuickUnionUF::Count()
{
	return count;
}

bool WeightedQuickUnionUF::Connected(int p, int q)
{
	return Find(p)==Find(q);
}

int WeightedQuickUnionUF::Find(int p)
{
	while(p!=id[p]) p=id[p];
	return p;
}

void WeightedQuickUnionUF::Union(int p, int q)
{
	int pID=Find(p);
	int qID=Find(q);
	if(pID==qID)
		return;
	if(sz[pID]>sz[qID])
	{
		id[qID]=pID;
		sz[pID]+=sz[qID];
	}
	else
	{
		id[pID]=qID;
		sz[qID]+=sz[pID];
	}
	count--;
}
/*}}}*/


int  main()
{
	int N,q,p;
	cin>>N;
//	WeightedQuickUnionUF*uf=new WeightedQuickUnionUF(N);
//	QuickUnionUF *uf=new QuickUnionUF(N);
	UF *uf=new UF(N);
	time_t t1=time(NULL);
	while( (cin>>p) && (cin>>q) )
	{
		if( uf->Connected(p,q) )
			continue;
		uf->Union(p,q);
//		cout<<p<<" "<<q<<endl;
	}
	//cout<<"p: "<<p<<"q: "<<q<<endl;
	time_t t2=time(NULL);
	cout<<"time: "<<t2-t1<<endl;
	cout<<uf->Count()<<" components"<<endl;
}
