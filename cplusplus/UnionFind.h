
class UF/*{{{*/
{
private:
	int *id;
	int count;
	int N;

public:
	UF(int n):count(n),N(n) 
	{ 
		id=new int[n]; 
		for(int i=0;i<n;i++)
			id[i]=i;
	}
	int Find(int p); //quick-find
	void Union(int p, int q); //quick-find
	bool Connected(int p, int q);
	int Count();
	int FindFast(int p); //quick-union
	void UnionFast(int p, int q); //quick-union
};
/*}}}*/

class QuickUnionUF/*{{{*/
{
private:
	int *id;
	int count;
	int N;

public:
	QuickUnionUF(int n):count(n),N(n)
	{
		id=new int[n];
		for(int i=0;i<n;i++)
		{
			id[i]=i;
		}
	}
	int Count();
	bool Connected(int p, int q);
	int Find(int p);
	void Union(int p, int q);
};/*}}}*/

class WeightedQuickUnionUF/*{{{*/
{
private:
	int count;	
	int N;
	int *id;
	int *sz;
public:
	WeightedQuickUnionUF(int n):count(n),N(n)
	{
		id=new int[N];	
		sz=new int[N];
		for(int i=0;i<N;i++) id[i]=i;
		for(int i=0;i<N;i++) sz[i]=1;
	}
	int Count();
	bool Connected(int q, int p);
	int Find(int p);
	void Union(int p,int q);
};/*}}}*/
